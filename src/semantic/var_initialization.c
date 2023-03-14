
/**
 * @file
 *
 * This file contains the code for the VarInitialization traversal.
 * The traversal has the uid: VI
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"
#include "palm/str.h"

void VIinit() { return; }
void VIfini() { return; }

node_st *VIlookup(node_st *symbol_table, char *identifier)
{
    // Check if the symbol table or identifier are NULL
    if (symbol_table == NULL || identifier == NULL)
    {
        return NULL;
    }

    // Check if the identifier exists in the symbol table
    node_st *entry = SYMTBL_HEAD(symbol_table);
    while (entry != NULL)
    {
        if (STReq(STE_NAME(entry), identifier) == true)
        {
            // Identifier found in the symbol table
            return entry;
        }
        entry = STE_NEXT(entry);
    }

    // Identifier not found in the symbol table
    return NULL;
}

/**
 * @fn VIprogram
 */
node_st *VIprogram(node_st *node)
{
    // Set the current scope of the program's data to be the node being traversed
    struct data_vi *data = DATA_VI_GET();
    data->current_scope = node;

    // Traverse the children of the current node
    TRAVchildren(node);

    // Reset the parent node as the current scope
    data->current_scope = node;

    // Return the current node
    return node;
}

/**
 * @fn VIfundef
 */
node_st *VIfundef(node_st *node)
{
    struct data_vi *data = DATA_VI_GET();

    node_st *outer = data->current_scope;

    // Set this node as the current scope
    data->current_scope = node;

    TRAVchildren(node);

    // Reset the parent node as the current scope
    data->current_scope = outer;

    return node;
}

/**
 * @fn VIprogram
 */
node_st *VIglobdef(node_st *node)
{

    // Traverse the children of the current node
    TRAVchildren(node);

    // Get the program's data and current scope
    struct data_vi *data = DATA_VI_GET();
    node_st *outer_scope = data->current_scope;

    // Check if there is an initialization assignment
    if (GLOBDEF_INIT(node) != NULL)
    {

        // Lookup the "__init" declaration in the program's symbol table
        char *init_function_name = "__init";
        node_st *init_function_lookup = VIlookup(PROGRAM_SYMTBL(outer_scope), init_function_name);

        // Get the function declaration node for the "__init" function
        node_st *init_function_declaration = STE_DECL(init_function_lookup);

        // Create an assignment statement with the initialization value
        node_st *assignment_statement = ASTassign(
            ASTvarlet(GLOBDEF_DIMS(node), GLOBDEF_NAME(node)),
            GLOBDEF_INIT(node));

        // Get the body and statement list of the "__init" function
        node_st *init_function_body = FUNDEF_BODY(init_function_declaration);
        node_st *init_function_statements = FUNBODY_STMTS(init_function_body);

        if (init_function_statements != NULL)
        {
            node_st *temp = init_function_statements;

            while (STMTS_NEXT(temp) != NULL)
            {
                temp = STMTS_NEXT(temp);
            }

            // Create a new statement list with the assignment statement added to the beginning
            STMTS_NEXT(temp) = CCNcopy(ASTstmts(assignment_statement, NULL));
        }
        else
        {
            FUNBODY_STMTS(init_function_body) = ASTstmts(CCNcopy(assignment_statement), NULL);
        }

        // Clear the initialization value of the current global definition node
        GLOBDEF_INIT(node) = NULL;
    }

    // Return the current node
    return node;
}

/**
 * @fn VIvardecl
 */
node_st *VIvardecl(node_st *node)
{
    // First we traverse to keep order of assignments correct.
    TRAVchildren(node);

    // Get the data and the current scope
    struct data_vi *data = DATA_VI_GET();
    node_st *outer = data->current_scope;

    // Create an assignment node if there is an initial value
    if (VARDECL_INIT(node) != NULL)
    {
        // Create the assignment node
        node_st *assign = ASTassign(ASTvarlet(VARDECL_DIMS(node), VARDECL_NAME(node)), VARDECL_INIT(node));

        // Insert the assignment node into the outer function body's statements
        node_st *outer_body = FUNDEF_BODY(outer);
        node_st *outer_stmts = FUNBODY_STMTS(outer_body);

        node_st *newassign_stmts = ASTstmts(assign, outer_stmts);

        FUNBODY_STMTS(outer_body) = CCNcopy(newassign_stmts);

        // Clear the initial value from the variable declaration node
        VARDECL_INIT(node) = NULL;
    }

    return node;
}