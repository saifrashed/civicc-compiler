
/**
 * @file
 *
 * This file contains the code for the ParameterPassing traversal.
 * The traversal has the uid: PP
 */

#include <stdio.h>
#include <string.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"
#include "palm/str.h"

void PPinit() { return; }
void PPfini() { return; }

/**
 * @fn PPprogram
 */
node_st *PPprogram(node_st *node)
{
    struct data_pp *data = DATA_PP_GET();

    data->current_scope = node;

    TRAVchildren(node);

    return node;
}

/**
 * @fn PPfundef
 */
node_st *PPfundef(node_st *node)
{

    struct data_pp *data = DATA_PP_GET();
    node_st *outer = data->current_scope;

    data->current_scope = node;

    TRAVchildren(node);

    data->current_scope = outer;

    return node;
}

/**
 * @fn PPbool
 */
node_st *PPfuncall(node_st *node)
{

    return node;
}
