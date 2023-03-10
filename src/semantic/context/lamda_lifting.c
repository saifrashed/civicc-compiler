/**
 * @file
 *
 * This file contains the code for the LamdaLifting traversal.
 * The traversal has the uid: LL
 *
 *
 */

#include <stdio.h>

#include <stdio.h>
#include <string.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"

void LLinit() { return; }
void LLfini() { return; }

/**
 * @fn LLfundef
 */
node_st *LLfundef(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * THESE NODES MUST HAVE
 * AN PARAMETER OR VARIABLE DECLARATION ALREADY INITIALISED OTHER WISE WE RETURN AN ERROR.
 */

// /**
//  * @fn STvarlet
//  */
// node_st *STfuncall(node_st *node)
// {
//     struct data_st *data = DATA_ST_GET();
//     printf("STfuncall \n");

//     TRAVchildren(node);

//     return node;
// }

// /**
//  * @fn STvar
//  */
// node_st *STvar(node_st *node)
// {
//     struct data_st *data = DATA_ST_GET();
//     printf("STvar \n");

//     TRAVchildren(node);

//     return node;
// }

// /**
//  * @fn STvarlet
//  */
// node_st *STvarlet(node_st *node)
// {
//     struct data_st *data = DATA_ST_GET();
//     printf("STvarlet \n");

//     TRAVchildren(node);

//     return node;
// }

// /**
//  * This functions takes an fundefinition and generates an unique name to be stored in the symbol table.
//  **/
// char *generateFunName(node_st *fundef)
// {

//     return "name_type_arity";
// }

// /**
//  * This function searches all SYMTBL's from inner to outer for an identifier.
//  * Returns STE if found.
//  **/
// node_st *lookup(node_st *symtbl, char *identifier)
// {
//     if (symtbl == NULL)
//         return NULL;

//     if (identifier == NULL)
//         return NULL;

//     node_st *parent = SYMTBL_PARENT(symtbl);
//     node_st *temp = SYMTBL_HEAD(symtbl);

//     while (temp != NULL)
//     {
//         printf("CHECK: %s with %s\n", STE_NAME(temp), identifier);

//         if (strcmp(STE_NAME(temp), identifier) == 0)
//             return temp;

//         if (temp == NULL && parent != NULL) // Check if there is a parent and no next node (to upscope)
//         {
//             temp = SYMTBL_HEAD(parent);
//             parent = SYMTBL_PARENT(parent);
//         }

//         temp = STE_NEXT(temp);
//     }

//     return NULL;
// }

// node_st *lookup(node_st *symtbl, char *identifier)
// {
//     if (symtbl == NULL)
//         return NULL;

//     if (identifier == NULL)
//         return NULL;

//     node_st *parent = SYMTBL_PARENT(symtbl);
//     node_st *temp = SYMTBL_HEAD(symtbl);

//     while (temp != NULL)
//     {
//         printf("CHECK: %s with %s\n", STE_NAME(temp), identifier);

//         if (strcmp(STE_NAME(temp), identifier) == 0)
//             return temp;

//         if (temp == NULL && parent != NULL) // Check if there is a parent and no next node (to upscope)
//         {
//             temp = SYMTBL_HEAD(parent);
//             parent = SYMTBL_PARENT(parent);
//         }

//         temp = STE_NEXT(temp);
//     }

//     return NULL;
// }

//  node_st *result = lookup(PROGRAM_SYMTBL(outer), FUNDEF_NAME(node)); // We search for an occurance.
