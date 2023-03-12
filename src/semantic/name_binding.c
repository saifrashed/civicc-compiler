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

char *NBgeneratesignature(node_st *funcall, node_st *symtbl)
{
    char *signature = STRcpy(FUNCALL_NAME(funcall));
    int count = 0; // Initialize a counter variable

    if (FUNCALL_ARGS(funcall) != NULL)
    {
        node_st *arg = FUNCALL_ARGS(funcall);
        while (arg != NULL)
        {
            count++; // Increment the counter
            arg = EXPRS_NEXT(arg);
        }
    }

    // Append the counter value to the signature string
    char count_str[10];
    snprintf(count_str, 10, "_%d", count);
    signature = STRcat(signature, count_str);

    return signature;
}

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

    char *signature = NBgeneratesignature(node, FUNDEF_SYMTBL(scope));
    node_st *entry = NBlookup(FUNDEF_SYMTBL(scope), signature);

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

// /**
//  * Returns the type as a character.
//  **/
// char *get_type(node_st *expr, node_st *symtbl)
// {
//     // If type is constant
//     // If type is var (look up in table)
//     // If type is binop
//     // if expression has dimensions it an array of certain type

//     char *type = NULL;
//     switch (NODE_TYPE(expr))
//     {
//     case NT_NUM:
//         type = "int";
//         break;
//     case NT_FLOAT:
//         type = "float";
//         break;
//     case NT_BOOL:
//         type = "bool";
//         break;
//     case NT_VAR:
//         switch (STE_TYPE(NBlookup(symtbl, VAR_NAME(expr))))
//         {
//         case CT_bool:
//             type = "bool";
//             break;
//         case CT_float:
//             type = "float";
//             break;
//         case CT_int:
//             type = "int";
//             break;
//         }
//         break;
//     }
//     return type;
// }

// /**
//  * Generates a unique function signature based on a given function call and its arguments.
//  * The function infers the return type, name, and number of parameters of the function to create a
//  * signature with the format funtype_funname_arity. The signature is used to distinguish the function
//  * from others with the same name but different types or parameters.
//  *
//  * @param funcall A pointer to a funcall node representing the function call.
//  * @param symtbl A pointer to the symbol table containing information about the function's scope.
//  *
//  * @return A pointer to a string containing the function signature, or NULL if the signature cannot be generated.
//  **/

// char *NBgeneratesignature(node_st *funcall, node_st *symtbl)
// {
//     char *signature = STRcpy(FUNCALL_NAME(funcall));
//     if (FUNCALL_ARGS(funcall) != NULL)
//     {
//         node_st *arg = FUNCALL_ARGS(funcall);
//         while (arg != NULL)
//         {
//             char *type = get_type(EXPRS_EXPR(arg), symtbl);
//             signature = STRcat(signature, "_");
//             signature = STRcat(signature, type);
//             arg = EXPRS_NEXT(arg);
//         }
//     }
//     return signature;
// }
