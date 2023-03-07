/**
 * @file
 *
 * This file contains the code for the SymbolTable traversal.
 * The traversal has the uid: ST
 *
 *
 */

#include <stdio.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"

void STinit() { return; }
void STfini() { return; }

/**
 * @fn STprogram
 */
node_st *STprogram(node_st *node)
{
    printf("STprogram \n");

    return node;
}

/**
 * @fn STglobdef
 */
node_st *STglobdef(node_st *node)
{
    printf("STglobdef \n");

    return node;
}

/**
 * @fn STglobdecl
 */
node_st *STglobdecl(node_st *node)
{
    printf("STglobdecl \n");

    return node;
}

/**
 * @fn STfundef
 */
node_st *STfundef(node_st *node)
{
    printf("STfundef \n");

    return node;
}

/**
 * @fn STvardecl
 */
node_st *STvardecl(node_st *node)
{
    printf("STvardecl \n");

    return node;
}

/**
 * @fn STvar
 */
node_st *STvar(node_st *node)
{
    printf("STvar \n");

    return node;
}

/**
 * @fn STvarlet
 */
node_st *STvarlet(node_st *node)
{

    printf("STvarlet \n");

    return node;
}
