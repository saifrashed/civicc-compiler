
/**
 * @file
 *
 * This file contains the code for the InductionInitialization traversal.
 * The traversal has the uid: II
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

void IIinit() { return; }
void IIfini() { return; }

node_st *IIlookup(node_st *symbol_table, char *identifier)
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
 * @fn IIprogram
 */
node_st *IIprogram(node_st *node)
{
    struct data_ii *data = DATA_II_GET();

    data->current_scope = node;

    TRAVchildren(node);

    return node;
}

/**
 * @fn IIfundef
 */
node_st *IIfundef(node_st *node)
{

    struct data_ii *data = DATA_II_GET();
    node_st *outer = data->current_scope;

    data->current_scope = node;

    TRAVchildren(node);

    data->current_scope = outer;

    return node;
}

/**
 * @fn IIfor
 */
node_st *IIfor(node_st *node)
{
    struct data_ii *data = DATA_II_GET();

    node_st *entry = FOR_BLOCK(node);
    node_st *previous = NULL;

    while (entry != NULL)
    {

        if (NODE_TYPE(STMTS_STMT(entry)) == NT_FOR)
        {
            node_st *forloop = STMTS_STMT(entry);
            node_st *vardecl = IIlookup(FUNDEF_SYMTBL(data->current_scope), FOR_VAR(forloop));

            node_st *assign = ASTassign(ASTvarlet(NULL, STE_NAME(vardecl)), VARDECL_INIT(STE_DECL(vardecl)));

            node_st *stmts = ASTstmts(assign, ASTstmts(forloop, STMTS_NEXT(entry)));

            // The desired vardecl is found
            if (previous == NULL)
            {
                // The found declaration is the first one
                FOR_BLOCK(node) = ASTstmts(CCNcopy(assign), ASTstmts(forloop, STMTS_NEXT(entry)));
            }
            else
            {
                STMTS_NEXT(previous) = ASTstmts(CCNcopy(assign), ASTstmts(forloop, STMTS_NEXT(entry)));
            }

            // We null the vardecl so that it doesnt get processed further down the pipe line.
            VARDECL_INIT(STE_DECL(vardecl)) = NULL;
        }

        previous = entry;
        entry = STMTS_NEXT(entry);
    }

    return node;
}