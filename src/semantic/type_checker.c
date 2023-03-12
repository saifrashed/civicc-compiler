/**
 * @file
 *
 * This file contains the code for the Typechecker traversal.
 * The traversal has the uid: TC
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

void TCinit() { return; }
void TCfini() { return; }

/**
 * @fn TCassign
 */
node_st *TCassign(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * @fn TCifelse
 */
node_st *TCifelse(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * @fn TCfundef
 */
node_st *TCwhile(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * @fn TCfundef
 */
node_st *TCdowhile(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * @fn TCfor
 */
node_st *TCfor(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * @fn TCreturn
 */
node_st *TCreturn(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * @fn TCcast
 */
node_st *TCcast(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * @fn TCfuncall
 */
node_st *TCfuncall(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * @fn TCvar
 */
node_st *TCvar(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * @fn TCarrexpr
 */
node_st *TCarrexpr(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * @fn TCbinop
 */
node_st *TCbinop(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * @fn TCmonop
 */
node_st *TCmonop(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * @fn TCfloat
 */
node_st *TCfloat(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * @fn TCbool
 */
node_st *TCbool(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * @fn TCnum
 */
node_st *TCnum(node_st *node)
{
    TRAVchildren(node);

    return node;
}