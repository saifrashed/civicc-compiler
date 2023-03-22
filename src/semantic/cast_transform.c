
/**
 * @file
 *
 * This file contains the code for the CastTransform traversal.
 * The traversal has the uid: CT
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
node_st *CTcast(node_st *node)
{
    // Trav expression

    // For each Cast operation with a boolean we replace the expression with a ternary (bool) ? 1 : 0 - using the ternary node.

    return node;
}
