/**
 * @file
 *
 * This file contains the code for the SymbolTable traversal.
 * The traversal has the uid: ST
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

void STinit() { return; }
void STfini() { return; }

// /**
//  * This functions takes an fundefinition and generates an unique name to be stored in the symbol table.
//  **/
// char *generateFunName(node_st *fundef)
// {

//     return "name_type_arity";
// }

/**
 * This function searches all SYMTBL's from inner to outer for an identifier.
 * Returns STE if found.
 **/
node_st *lookup(node_st *symtbl, char *identifier)
{
    if (symtbl == NULL)
        return NULL;

    if (identifier == NULL)
        return NULL;

    node_st *parent = SYMTBL_PARENT(symtbl);
    node_st *temp = SYMTBL_HEAD(symtbl);

    while (STE_NEXT(temp) != NULL)
    {
        if (strcmp(STE_NAME(temp), identifier) == 0) // Check if identifier matches STE name
        {
            return temp;
        }

        if (STE_NEXT(temp) == NULL && parent != NULL) // If there is no entry but there is a new parent table.
        {
            parent = SYMTBL_PARENT(parent); // We set parent to a (probably non existing parent)
            temp = parent;                  // We search outer scope.
        }
    }

    return NULL;
}

/**
 * @fn STprogram
 */
node_st *STprogram(node_st *node)
{
    printf("STprogram \n");

    struct data_st *data = DATA_ST_GET();

    data->current_scope = node;

    PROGRAM_SYMTBL(node) = ASTsymtbl(NULL, NULL); // Create a blank symbol table for global scope.

    TRAVchildren(node);

    return node;
}

/**
 * @fn STfundef
 */
node_st *STfundef(node_st *node)
{
    struct data_st *data = DATA_ST_GET();

    node_st *outer = data->current_scope;

    // We first create a new symbol table in this node.
    if (NODE_TYPE(outer) == NT_PROGRAM)
        FUNDEF_SYMTBL(node) = ASTsymtbl(PROGRAM_SYMTBL(outer), NULL); // If parent is program we set parent to global scope.

    if (NODE_TYPE(outer) == NT_FUNDEF)
        FUNDEF_SYMTBL(node) = ASTsymtbl(FUNDEF_SYMTBL(outer), NULL); // If parent is fundef we set parent to outer scope.

    // switch (NODE_TYPE(parent))
    // {
    // case NT_PROGRAM: // Global scope

    //     break;

    // case NT_FUNDEF: // Nested scope

    //     break;

    // case NT_NULL:
    //     DBUG_ASSERT(false, "unknown parent node detected!");
    // }

    // IK moet in de parent deze node toevoegen
    // Ik moet in deze node een symtbl aan maken

    // switch (NODE_TYPE(parent))
    // {
    // case NT_PROGRAM: // Global scope

    //     // If parent node does not have an initial entry node already we create a new one.
    //     if (PROGRAM_HEAD(parent) == NULL)
    //     {
    //         PROGRAM_HEAD(parent) = ASTste(NULL, FUNDEF_NAME(node));
    //     }
    //     else
    //     {
    //         // Check if fun definition already occurred.
    //         node_st *result = lookup(PROGRAM_HEAD(parent), FUNDEF_NAME(node));

    //         if (result != NULL) // The FUNDEF has occurred before.
    //         {
    //         }
    //         else // The FUNDEF has not occurred before.
    //         {
    //         }
    //     }

    //     break;

    // case NT_FUNDEF: // Nested scope

    //     // If parent node does not have an initial entry node already we create a new one.
    //     if (FUNDEF_HEAD(parent) == NULL)
    //     {
    //         FUNDEF_HEAD(parent) = ASTste(NULL, FUNDEF_NAME(node));
    //     }
    //     else
    //     {
    //         // Check if fun definition already occurred.
    //         node_st *result = lookup(FUNDEF_HEAD(parent), FUNDEF_NAME(node));

    //         if (result != NULL) // The FUNDEF has occurred before.
    //         {
    //         }
    //         else // The FUNDEF has not occurred before.
    //         {
    //         }
    //     }

    //     break;
    // case NT_NULL:
    //     DBUG_ASSERT(false, "unknown parent node detected!");
    // }

    // Set this node as current node
    data->current_scope = node;

    printf("STfundef \n");
    TRAVchildren(node);

    // Set parent node back if we are done with traversing
    data->current_scope = outer;

    return node;
}

/**
 * THESE NODES MUST HAVE
 * AN UNIQUE DECLARATION SO NO DECLARATION CAN PRECEDE IT IN THE SAME SCOPE
 */

/**
 * @fn STglobdecl
 */
node_st *STglobdecl(node_st *node)
{
    struct data_st *data = DATA_ST_GET();

    printf("STglobdef \n");

    TRAVchildren(node);

    return node;
}

/**
 * @fn STglobdef
 */
node_st *STglobdef(node_st *node)
{
    struct data_st *data = DATA_ST_GET();

    printf("STglobdef \n");

    TRAVchildren(node);

    return node;
}

/**
 * @fn STvardecl
 */
node_st *STvardecl(node_st *node)
{
    struct data_st *data = DATA_ST_GET();

    printf("STvardecl \n");

    TRAVchildren(node);

    return node;
}

/**
 * @fn STparam
 */
node_st *STparam(node_st *node)
{
    struct data_st *data = DATA_ST_GET();

    printf("STparam \n");

    TRAVchildren(node);

    return node;
}

/**
 * THESE NODES MUST HAVE
 * AN PARAMETER OR VARIABLE DECLARATION ALREADY INITIALISED OTHER WISE WE RETURN AN ERROR.
 */

/**
 * @fn STvarlet
 */
node_st *STfuncall(node_st *node)
{
    struct data_st *data = DATA_ST_GET();
    printf("STfuncall \n");

    TRAVchildren(node);

    return node;
}

/**
 * @fn STvar
 */
node_st *STvar(node_st *node)
{
    struct data_st *data = DATA_ST_GET();
    printf("STvar \n");

    TRAVchildren(node);

    return node;
}

/**
 * @fn STvarlet
 */
node_st *STvarlet(node_st *node)
{
    struct data_st *data = DATA_ST_GET();
    printf("STvarlet \n");

    TRAVchildren(node);

    return node;
}

/**
 * @fn STids
 */
node_st *STids(node_st *node)
{
    struct data_st *data = DATA_ST_GET();
    printf("STids \n");

    TRAVchildren(node);

    return node;
}
