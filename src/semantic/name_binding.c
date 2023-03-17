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

char *NBgeneratesignature(node_st *funcall)
{
    // Copy the function call name to the signature string
    char *signature = STRcpy(FUNCALL_NAME(funcall));

    // Initialize a counter variable
    int count = 0;

    // Count the number of arguments in the function call
    if (FUNCALL_ARGS(funcall) != NULL)
    {
        node_st *arg = FUNCALL_ARGS(funcall);
        while (arg != NULL)
        {
            count++;
            arg = EXPRS_NEXT(arg);
        }
    }

    // Append the counter value to the signature string
    char count_str[10];
    snprintf(count_str, 10, "_%d", count);
    signature = STRcat(signature, count_str);

    return signature;
}

node_st *NBlookup(node_st *symtbl, char *identifier)
{
    // Check if the symbol table and identifier are not null
    if (symtbl == NULL || identifier == NULL)
    {
        return NULL;
    }

    // Traverse the symbol table hierarchy
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

    // If the identifier is not found, return null
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
    // Get the data and current scope
    struct data_nb *data = DATA_NB_GET();
    node_st *scope = data->current_scope;

    // Look up the variable in the symbol table
    node_st *entry = NBlookup(FUNDEF_SYMTBL(scope), VARLET_NAME(node));

    // If the variable is found, mark it as a variable entry
    if (entry != NULL)
    {
        VARLET_ENTRY(entry);
    }

    // If the variable is not found, print an error message
    if (entry == NULL)
    {
        CTI(CTI_ERROR, true, "\n Undefined reference: '%s' is not defined at: line: %d col: %d-%d. \n",
            VARLET_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    // Traverse the node's children and return the node
    TRAVchildren(node);
    return node;
}

/**
 * @fn NBvar
 */
node_st *NBvar(node_st *node)
{
    // Get the data and current scope
    struct data_nb *data = DATA_NB_GET();
    node_st *scope = data->current_scope;

    // Look up the variable in the symbol table
    node_st *entry = NBlookup(FUNDEF_SYMTBL(scope), VAR_NAME(node));

    // If the variable is found, mark it as a variable entry
    if (entry != NULL)
    {
        VAR_ENTRY(entry);
    }

    // If the variable is not found, print an error message
    if (entry == NULL)
    {
        CTI(CTI_ERROR, true, "\n Undefined reference: '%s' is not defined at: line: %d col: %d-%d. \n",
            VAR_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    // Traverse the node's children and return the node
    TRAVchildren(node);
    return node;
}

/**
 * @fn NBfuncall
 */
node_st *NBfuncall(node_st *node)
{
    // Get the data and current scope
    struct data_nb *data = DATA_NB_GET();
    node_st *scope = data->current_scope;

    // Look up the function call in the symbol table
    char *signature = NBgeneratesignature(node);

    node_st *entry = NBlookup(FUNDEF_SYMTBL(scope), signature);

    // If the function is found, mark it as a function call entry
    if (entry != NULL)
    {
        FUNCALL_NAME(node) = signature;
        FUNCALL_ENTRY(entry) = entry;
    }

    // If function is an allocate function
    if (STReq(FUNCALL_NAME(node), "__allocate") == true)
    {
        node_st *allocate_entry = NBlookup(FUNDEF_SYMTBL(scope), "__allocate");

        FUNCALL_ENTRY(node) = allocate_entry;
    }
    else if (entry == NULL) // If there is no entries to be found.
    {
        CTI(CTI_ERROR, true, "\n Undefined reference: '%s' is not defined at: line: %d col: %d-%d. \n",
            FUNCALL_NAME(node), NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    // Traverse the node's children and return the node
    TRAVchildren(node);
    return node;
}
