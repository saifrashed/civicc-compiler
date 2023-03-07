/**
 * @file
 *
 * This file contains the code for the SymbolTable traversal.
 * The traversal has the uid: CST
 *
 *
 */

#include <stdio.h>

#include "ccn/ccn.h"
#include "ccngen/ast.h"

/**
 * @fn CSTprogram
 */
node_st *CSTprogram(node_st *node)
{
    printf("Program \n");

    return node;
}

/**
 * @fn CSTprogram
 */
node_st *CSTvardecl(node_st *node)
{
    printf("Vardecl \n");

    return node;
}

/**
 * @fn CSTprogram
 */
node_st *CSTvar(node_st *node)
{
    printf("Var \n");

    return node;
}

/**
 * @fn CSTprogram
 */
node_st *CSTvarlet(node_st *node)
{

    printf("VarLet \n");

    return node;
}