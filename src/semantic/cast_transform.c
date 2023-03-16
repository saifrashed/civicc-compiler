
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

    // If value is either = true we change this cast expression to ASTnum of 1

    // If value is either = false we change this cast expression to ASTnum of 0

    return node;
}
