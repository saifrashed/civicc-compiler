
/**
 * @file
 *
 * This file contains the code for the LoopTransform traversal.
 * The traversal has the uid: LT
 */

#include <stdio.h>
#include <string.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"
#include "palm/str.h"

void LTinit() { return; }
void LTfini() { return; }

node_st *LTlookup(node_st *symbol_table, char *identifier)
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
 * @fn LTprogram
 */
node_st *LTprogram(node_st *node)
{
    // Set the current scope of the program's data to be the node being traversed
    struct data_lt *data = DATA_LT_GET();
    data->current_scope = node;

    // Traverse the children of the current node
    TRAVchildren(node);

    // Reset the parent node as the current scope
    data->current_scope = node;

    // Return the current node
    return node;
}

/**
 * @fn LTfundef
 */
node_st *LTfundef(node_st *node)
{
    struct data_lt *data = DATA_LT_GET();

    node_st *outer = data->current_scope;

    // Set this node as the current scope
    data->current_scope = node;

    TRAVchildren(node);

    // Reset the parent node as the current scope
    data->current_scope = outer;

    return node;
}

/**
 * @fn LTfor
 */
node_st *LTfor(node_st *node)
{

    struct data_lt *data = DATA_LT_GET();

    node_st *outer = data->current_scope;

    node_st *step = FOR_STEP(node);

    if (step == NULL)
    {
        step = ASTnum(1);
    }

    node_st *condition = ASTternary(ASTbinop(CCNcopy(step), ASTnum(0), BO_gt), ASTbinop(ASTvar(NULL, STRcpy(FOR_VAR(node))), CCNcopy(FOR_STOP(node)), BO_lt), ASTbinop(ASTvar(NULL, STRcpy(FOR_VAR(node))), CCNcopy(FOR_STOP(node)), BO_gt));
    node_st *increment = ASTassign(ASTvarlet(NULL, STRcpy(FOR_VAR(node))), ASTbinop(ASTvar(NULL, STRcpy(FOR_VAR(node))), CCNcopy(step), BO_add));

    node_st *stmts = FOR_BLOCK(node);

    if (stmts != NULL)
    {
        node_st *temp_stmts = stmts;

        while (STMTS_NEXT(temp_stmts) != NULL)
        {
            temp_stmts = STMTS_NEXT(temp_stmts);
        }

        STMTS_NEXT(temp_stmts) = ASTstmts(increment, NULL);
    }
    else
    {
        stmts = ASTstmts(increment, NULL);
    }

    node = ASTwhile(condition, stmts);

    TRAVchildren(node); // Continue searching for loops

    return node;
}
