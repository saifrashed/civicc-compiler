
/**
 * @file
 *
 * This file contains the code for the Assignmentextract traversal.
 * The traversal has the uid: AE
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

void AEinit() { return; }
void AEfini() { return; }

node_st *AElookup(node_st *symbol_table, char *identifier)
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
 * @fn AEprogram
 */
node_st *AEprogram(node_st *node)
{
    // Initialize a function declaration node with the name "__init" and void return type
    char *init_function_name = "__init";
    node_st *init_function_declaration = ASTdecls(
        ASTfundef(ASTfunbody(NULL, NULL, NULL), NULL, CT_void, init_function_name, false),
        NULL);

    // Add the "__init" declaration to the end of the declaration list
    node_st *declaration_tail = PROGRAM_NEXT(node);
    while (DECLS_NEXT(declaration_tail) != NULL)
    {
        declaration_tail = DECLS_NEXT(declaration_tail);
    }
    DECLS_NEXT(declaration_tail) = CCNcopy(init_function_declaration);

    // Set the symbol table of the "__init" declaration to be a copy of the program's symbol table
    FUNDEF_SYMTBL(DECLS_DECL(DECLS_NEXT(declaration_tail))) = ASTsymtbl(PROGRAM_SYMTBL(node), NULL);

    // Copy the program's symbol table
    node_st *symbol_table_head = CCNcopy(SYMTBL_HEAD(PROGRAM_SYMTBL(node)));

    // Create a new symbol table with the "__init" declaration as its first declaration
    node_st *new_symbol_table_head = ASTste(
        symbol_table_head,
        FUNDEF_NAME(DECLS_DECL(DECLS_NEXT(declaration_tail))),
        CT_void,
        DECLS_DECL(DECLS_NEXT(declaration_tail)));

    // Set the new symbol table head as the program's symbol table head
    SYMTBL_HEAD(PROGRAM_SYMTBL(node)) = CCNcopy(new_symbol_table_head);

    // Set the current scope of the program's data to be the node being traversed
    struct data_ae *program_data = DATA_AE_GET();
    program_data->current_scope = node;

    // Traverse the children of the current node
    TRAVchildren(node);

    // Return the current node
    return node;
}

/**
 * @fn AEfundef
 */
node_st *AEfundef(node_st *node)
{
    struct data_ae *data = DATA_AE_GET();

    node_st *outer = data->current_scope;

    // Set this node as the current scope
    data->current_scope = node;

    TRAVchildren(node);

    // Reset the parent node as the current scope
    data->current_scope = outer;

    return node;
}

/**
 * @fn AEprogram
 */
node_st *AEglobdef(node_st *node)
{
    // Traverse the children of the current node
    TRAVchildren(node);

    // Get the program's data and current scope
    struct data_ae *program_data = DATA_AE_GET();
    node_st *outer_scope = program_data->current_scope;

    // Check if there is an initialization assignment
    if (GLOBDEF_INIT(node) != NULL)
    {

        // Lookup the "__init" declaration in the program's symbol table
        char *init_function_name = "__init";
        node_st *init_function_lookup = AElookup(PROGRAM_SYMTBL(outer_scope), init_function_name);

        // Get the function declaration node for the "__init" function
        node_st *init_function_declaration = STE_DECL(init_function_lookup);

        // Create an assignment statement with the initialization value
        node_st *assignment_statement = ASTassign(
            ASTvarlet(GLOBDEF_DIMS(node), GLOBDEF_NAME(node)),
            GLOBDEF_INIT(node));

        // Get the body and statement list of the "__init" function
        node_st *init_function_body = FUNDEF_BODY(init_function_declaration);
        node_st *init_function_statements = FUNBODY_STMTS(init_function_body);

        // Create a new statement list with the assignment statement added to the beginning
        node_st *new_statement_list = ASTstmts(assignment_statement, init_function_statements);

        // Set the new statement list as the statement list for the "__init" function
        FUNBODY_STMTS(init_function_body) = CCNcopy(new_statement_list);

        // Clear the initialization value of the current global definition node
        GLOBDEF_INIT(node) = NULL;
    }

    // Traverse the children of the current node again
    TRAVchildren(node);

    // Return the current node
    return node;
}

/**
 * @fn AEvardecl
 */
node_st *AEvardecl(node_st *node)
{
    // Get the data and the current scope
    struct data_ae *data = DATA_AE_GET();
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

    // Traverse the node's children and return the node
    TRAVchildren(node);

    return node;
}