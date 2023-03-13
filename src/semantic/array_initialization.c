
/**
 * @file
 *
 * This file contains the code for the ArrayInitialization traversal.
 * The traversal has the uid: AI
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

void AIinit() { return; }
void AIfini() { return; }

/**
 * @fn AIprogram
 */
node_st *AIprogram(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn AIfundef
 */
node_st *AIfundef(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn AIvardecl
 */
node_st *AIvardecl(node_st *node)
{

    // If vardecl has indices

    // If right hand side is arrexpression we have a hetrogeneous array - we use nested for loops.

    // If right hand side is expression we have a homogeneous array - We have whole lot of scalar assignments

    TRAVchildren(node);
    return node;
}
