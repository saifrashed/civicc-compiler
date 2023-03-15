
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
    // Set the current scope of the program's data to be the node being traversed
    struct data_ai *data = DATA_AI_GET();
    data->current_scope = node;

    // Traverse the children of the current node
    TRAVchildren(node);

    // Reset the parent node as the current scope
    data->current_scope = node;

    // Return the current node
    return node;
}

/**
 * @fn AIfundef
 */
node_st *AIfundef(node_st *node)
{
    struct data_ai *data = DATA_AI_GET();

    node_st *outer = data->current_scope;

    // Set this node as the current scope
    data->current_scope = node;

    TRAVchildren(node);

    // Reset the parent node as the current scope
    data->current_scope = outer;

    return node;
}

/**
 * @fn AIglobdef
 */
node_st *AIglobdef(node_st *node)
{
    // Traverse the children of the current node
    TRAVchildren(node);

    // Get the program's data and current scope
    struct data_ai *data = DATA_AI_GET();
    node_st *outer_scope = data->current_scope;

    // If globdef has indices

    // If right hand side is arrexpression we have a hetrogeneous array - we use nested for loops.

    // If right hand side is expression we have a homogeneous array - We have whole lot of scalar assignments

    return node;
}

/**
 * @fn AIvardecl
 */
node_st *AIvardecl(node_st *node)
{
    // Traverse the children of the current node
    TRAVchildren(node);

    // Get the program's data and current scope
    struct data_ai *data = DATA_AI_GET();
    node_st *outer_scope = data->current_scope;

    // If vardecl has indices

    // If right hand side is arrexpression we have a hetrogeneous array - we use nested for loops.

    // If right hand side is expression we have a homogeneous array - We have whole lot of scalar assignments

    return node;
}
