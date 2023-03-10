/**
 * @file
 *
 * This file contains the code for the FunctionOverloading traversal.
 * The traversal has the uid: NB
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"
#include "palm/str.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "palm/memory.h"
#include "palm/ctinfo.h"
#include "ccngen/enum.h"

void NBinit() { return; }
void NBfini() { return; }

/**
 * This function searches all SYMTBL's from inner to outer for an identifier.
 * Returns STE if found.
 **/
node_st *NBlookup(node_st *symtbl, char *identifier)
{
    if (symtbl == NULL || identifier == NULL)
        return NULL;

    node_st *temp = symtbl;
    while (temp != NULL)
    {
        // Check if the identifier exists in the current symbol table
        node_st *entry = SYMTBL_HEAD(temp);
        while (entry != NULL)
        {
            if (STReq(STE_NAME(entry), identifier) == true)
            {
                return entry;
            }
            entry = STE_NEXT(entry);
        }

        // Move to the outer symbol table
        node_st *outer = SYMTBL_OUTER(temp);
        if (outer != NULL)
        {
            temp = outer;
            continue;
        }

        // No more outer symbol tables, exit the loop
        break;
    }

    return NULL;
}

/**
 * @fn NBprogram
 */
node_st *NBprogram(node_st *node)
{
    struct data_nb *data = DATA_NB_GET();

    data->current_scope = node;

    TRAVchildren(node);

    CTIabortOnError(); // This Initialises the error messages.

    return node;
}

/**
 * @fn NBfundef
 */
node_st *NBfundef(node_st *node)
{
    struct data_nb *data = DATA_NB_GET();

    node_st *outer = data->current_scope;

    // Set this node as the current scope
    data->current_scope = node;

    TRAVchildren(node);

    // Reset the parent node as the current scope
    data->current_scope = outer;

    return node;
}

/**
 * @fn NBvarlet
 */
node_st *NBvarlet(node_st *node)
{
    struct data_nb *data = DATA_NB_GET();

    node_st *scope = data->current_scope;

    node_st *entry = NBlookup(FUNDEF_SYMTBL(scope), VARLET_NAME(node));

    if (entry != NULL)
    {
        VARLET_ENTRY(entry);
    }

    if (entry == NULL)
    {
        CTI(CTI_ERROR, true, "\n Undefined reference: '%s' is not defined at: line: %d col: %d-%d. \n",
            VARLET_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    TRAVchildren(node);

    return node;
}

/**
 * @fn NBvar
 */
node_st *NBvar(node_st *node)
{
    struct data_nb *data = DATA_NB_GET();

    node_st *scope = data->current_scope;

    node_st *entry = NBlookup(FUNDEF_SYMTBL(scope), VAR_NAME(node));

    if (entry != NULL)
    {
        VAR_ENTRY(entry);
    }

    if (entry == NULL)
    {
        CTI(CTI_ERROR, true, "\n Undefined reference: '%s' is not defined at: line: %d col: %d-%d. \n",
            VAR_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    TRAVchildren(node);

    return node;
}

/**
 * @fn NBfuncall
 */
node_st *NBfuncall(node_st *node)
{
    struct data_nb *data = DATA_NB_GET();

    node_st *scope = data->current_scope;

    node_st *entry = NBlookup(FUNDEF_SYMTBL(scope), FUNCALL_NAME(node));

    if (entry != NULL)
    {
        FUNCALL_ENTRY(entry);
    }

    if (entry == NULL)
    {
        CTI(CTI_ERROR, true, "\n Undefined reference: '%s' is not defined at: line: %d col: %d-%d. \n",
            FUNCALL_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    TRAVchildren(node);

    return node;
}