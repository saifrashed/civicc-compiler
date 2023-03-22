
/**
 * @file
 *
 * This file contains the code for the BooleanTransform traversal.
 * The traversal has the uid: BT
 */

#include <stdio.h>
#include <string.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"
#include "palm/str.h"

/**
 * @fn CTcast
 */
node_st *BTbinop(node_st *node)
{

    // We convert each binop with and/or to a equel ternary expression.

    return node;
}
