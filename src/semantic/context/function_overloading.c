/**
 * @file
 *
 * This file contains the code for the FunctionOverloading traversal.
 * The traversal has the uid: FO
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

void FOinit() { return; }
void FOfini() { return; }

/**
 * Generates a signature for a given function for the context analysis.
 * The function takes a fundef node and infers the type, number of parameters and parameter types
 * to generate a function name like funtype_funname_arity.
 **/
char *FOgeneratesignature(node_st *fundef)
{
    char *newstr = NULL; // Allocate memory for the new string

    return newstr;
}

/**
 * @fn FOfundef
 */
node_st *FOfundef(node_st *node)
{

    // 1. we take the arity of a function. So we count the amount of params it has in travdata
    // 2. We take it's type
    // 3. We generate a signature type_name_paramtype_paramtype
    // 4. We search and replace every funcall with the same, type and arity.
    // We do type checking in type analysis

    TRAVchildren(node);

    return node;
}

/**
 * @fn FOfuncall
 */
node_st *FOfuncall(node_st *node)
{

    TRAVchildren(node);

    return node;
}
