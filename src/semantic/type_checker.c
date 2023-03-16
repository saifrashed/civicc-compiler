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
#include "palm/ctinfo.h"
#include "palm/dbug.h"
#include "palm/str.h"

void TCinit() { return; }
void TCfini() { return; }

int TCdimensions(node_st *expr)
{
    int dimensions = 0;

    if (NODE_TYPE(expr) == NT_ARREXPR)
    {
        dimensions = 1;
        node_st *temp = EXPRS_EXPR(ARREXPR_EXPRS(expr));

        while (NODE_TYPE(temp) == NT_ARREXPR)
        {
            dimensions++;

            temp = EXPRS_EXPR(ARREXPR_EXPRS(temp));
        }
    }

    return dimensions;
}

int TCcountindices(node_st *expr)
{
    node_st *dims;
    int count = 0;

    if (NODE_TYPE(expr) == NT_PARAM)
    {
        dims = PARAM_DIMS(expr);

        while (dims != NULL)
        {
            count++;
            dims = IDS_NEXT(dims);
        }
    }

    if (NODE_TYPE(expr) == NT_VARDECL)
    {
        dims = VARDECL_DIMS(expr);

        while (dims != NULL)
        {
            count++;
            dims = EXPRS_NEXT(dims);
        }
    }

    if (NODE_TYPE(expr) == NT_GLOBDEF)
    {
        dims = GLOBDEF_DIMS(expr);

        while (dims != NULL)
        {
            count++;
            dims = EXPRS_NEXT(dims);
        }
    }

    if (NODE_TYPE(expr) == NT_VAR)
    {
        dims = VAR_INDICES(expr);

        while (dims != NULL)
        {
            count++;
            dims = EXPRS_NEXT(dims);
        }
    }

    if (NODE_TYPE(expr) == NT_GLOBDECL)
    {
        dims = GLOBDECL_DIMS(expr);

        while (dims != NULL)
        {
            count++;
            dims = IDS_NEXT(dims);
        }
    }

    return count;
}

node_st *TClookup(node_st *symtbl, char *identifier)
{
    // Check if the symbol table and identifier are not null
    if (symtbl == NULL || identifier == NULL)
    {
        return NULL;
    }

    // Traverse the symbol table hierarchy
    node_st *temp = symtbl;
    while (temp != NULL)
    {
        // Check if the identifier exists in the current symbol table
        node_st *entry = SYMTBL_HEAD(temp);
        while (entry != NULL)
        {
            if (STReq(STE_NAME(entry), identifier) == true)
            {
                return entry;
            }
            entry = STE_NEXT(entry);
        }

        // Move to the outer symbol table
        node_st *outer = SYMTBL_OUTER(temp);
        if (outer != NULL)
        {
            temp = outer;
            continue;
        }

        // No more outer symbol tables, exit the loop
        break;
    }

    // If the identifier is not found, return null
    return NULL;
}

/**
 * @fn TCprogram
 */
node_st *TCprogram(node_st *node)
{

    struct data_tc *data = DATA_TC_GET();

    data->current_scope = node;

    TRAVchildren(node);

    CTIabortOnError(); // This Initialises the error messages.

    return node;
}

/**
 * @fn TCfundef
 */
node_st *TCfundef(node_st *node)
{

    struct data_tc *data = DATA_TC_GET();
    node_st *outer = data->current_scope;

    data->current_scope = node;

    TRAVchildren(node);

    data->current_scope = outer;

    return node;
}

/**
 * @fn TCassign
 */
node_st *TCassign(node_st *node)
{

    // Traverse Varlet and infer type

    // We check if dimensions on the left hand side match the dimension of the right hand side.

    // Traverse expression and infer type

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCifelse
 */
node_st *TCifelse(node_st *node)
{

    // Traverse cond and infer type
    // Must match bool

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCfundef
 */
node_st *TCwhile(node_st *node)
{

    // Traverse cond and infer type
    // Must match bool

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCfundef
 */
node_st *TCdowhile(node_st *node)
{

    // Traverse cond and infer type
    // Must match bool

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCfor
 */
node_st *TCfor(node_st *node)
{
    // INDUCTION VARIABEL IS REMOVED

    // Traverse stop and infer type
    // Must match num

    // Traverse step and infer type
    // Must match num

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCreturn
 */
node_st *TCreturn(node_st *node)
{
    // Traverse expressison

    // Infer type

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCcast
 */
node_st *TCcast(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();

    // We infer the type based on the type being cast. Bool, Int and Float are compatible with eachother.

    // switch (CAST_TYPE(node))
    // {
    // case CT_int:
    //     TRAVexpr(node);
    //     enum Type expr_type = data->inferred;

    //     data->inferred = CT_int;
    //     break;
    // case CT_bool:
    //     TRAVexpr(node);
    //     enum Type expr_type = data->inferred;

    //     data->inferred = CT_bool;
    //     break;
    // case CT_float:
    //     TRAVexpr(node);
    //     enum Type expr_type = data->inferred;

    //     if()

    //     data->inferred = CT_float;
    //     break;
    // }

    return node;
}

/**
 * @fn TCfuncall
 */
node_st *TCfuncall(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();

    // We find the function definition node.
    node_st *decl = STE_DECL(TClookup(FUNDEF_SYMTBL(data->current_scope), FUNCALL_NAME(node)));

    enum Type type = FUNDEF_TYPE(decl);

    // Iterate through each argument and parameter pair, and compare their types.
    node_st *param = FUNDEF_PARAMS(decl);

    node_st *arg = FUNCALL_ARGS(node);

    while (param != NULL)
    {
        // If any pair has different types, then the types don't match and we sent an error.
        enum Type param_type = PARAM_TYPE(param);

        TRAVexpr(arg);

        enum Type arg_type = data->inferred;

        // We check if the types align.
        if (param_type != arg_type)
        {
            // We sent error if any other expressions mistmatches on type
            CTI(CTI_ERROR, true, "\n Function parameter types don't match: at: line: %d col: %d-%d. \n",
                NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

            return node;
        }

        if (NODE_TYPE(EXPRS_EXPR(arg)) == NT_VAR) // If we are dealing with a VAR
        {
            int param_dims_count = TCcountindices(param);

            node_st *decl = STE_DECL(TClookup(FUNDEF_SYMTBL(data->current_scope), VAR_NAME(EXPRS_EXPR(arg))));

            int arg_dims_count = TCcountindices(decl);

            if (param_dims_count != arg_dims_count)
            {
                // We sent error if any other expressions mistmatches on type
                CTI(CTI_ERROR, true, "\n Function parameter types don't match: at: line: %d col: %d-%d. \n",
                    NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

                return node;
            }
        }

        arg = EXPRS_NEXT(arg);
        param = PARAM_NEXT(param);
    }

    // We infer type num or float if all expressions are one of two.
    data->inferred = type;

    return node;
}

/**
 * @fn TCarrexpr
 */
node_st *TCarrexpr(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();

    // We First want to determine dimension of first element (If it has dimensions)
    int dimension = TCdimensions(EXPRS_EXPR(ARREXPR_EXPRS(node)));

    // Then we want to determine type of first element.
    TRAVexpr(ARREXPR_EXPRS(node));
    enum Type arrtype = data->inferred;

    // Then we loop through all other expressions and test if the values are the same. If not we send a an error
    node_st *temp = EXPRS_NEXT(ARREXPR_EXPRS(node));

    // Loop through all expressions.
    while (temp != NULL)
    {
        TRAVexpr(temp);

        if (arrtype != data->inferred)
        {
            // We sent error if any other expressions mistmatches on type
            CTI(CTI_ERROR, true, "\n Mixed types error: at: line: %d col: %d-%d. \n",
                NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

            return node;
        }

        if (dimension != TCdimensions(EXPRS_EXPR(temp)))
        {
            // We sent error if any other expressions mistmatches on dimensions
            CTI(CTI_ERROR, true, "\n Mixed dimensions error: at: line: %d col: %d-%d. \n",
                NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

            return node;
        }

        temp = EXPRS_NEXT(temp);
    }

    // We infer type num or float if all expressions are one of two.
    data->inferred = arrtype;

    return node;
}

/**
 * @fn TCbinop
 */
node_st *TCbinop(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();

    // Traverse left
    TRAVleft(node);

    // Get inferred type
    enum Type left = data->inferred;

    // Traverse right
    TRAVright(node);

    // Get inferred type
    enum Type right = data->inferred;

    // Infer the correct types.
    switch (BINOP_OP(node)) // Arithmetic operators
    {
    case BO_add:
    case BO_mul:
        if (left == CT_bool && right == CT_bool)
        {
            data->inferred = CT_bool;
            BINOP_TYPE(node) = CT_bool;
            return node;
        }
        else if (left == CT_int && right == CT_int)
        {
            data->inferred = CT_int;
            BINOP_TYPE(node) = CT_int;
            return node;
        }
        else if (left == CT_float && right == CT_float)
        {
            data->inferred = CT_float;
            BINOP_TYPE(node) = CT_float;
            return node;
        }
        break;
    case BO_sub:
    case BO_div:
        if (left == CT_int && right == CT_int)
        {
            data->inferred = CT_int;
            BINOP_TYPE(node) = CT_int;
            return node;
        }
        else if (left == CT_float && right == CT_float)
        {
            data->inferred = CT_float;
            BINOP_TYPE(node) = CT_float;
            return node;
        }
        break;
    case BO_mod:
        if (left == CT_int && right == CT_int)
        {
            data->inferred = CT_int;
            BINOP_TYPE(node) = CT_int;
            return node;
        }
        break;
    }

    switch (BINOP_OP(node)) // Equality operators
    {
    case BO_lt:
    case BO_le:
    case BO_gt:
    case BO_ge:
        if ((left == CT_int || left == CT_float) && (right == CT_int || right == CT_float))
        {
            data->inferred = CT_bool;
            BINOP_TYPE(node) = CT_bool;
            return node;
        }
        break;
    case BO_eq:
    case BO_ne:
        if (left == right && (left == CT_bool || left == CT_int || left == CT_float))
        {
            data->inferred = CT_bool;
            BINOP_TYPE(node) = CT_bool;
            return node;
        }
        break;
    }

    switch (BINOP_OP(node)) // Logical operators
    {
    case BO_and:
    case BO_or:
        if (left == CT_bool && right == CT_bool)
        {
            data->inferred = CT_bool;
            BINOP_TYPE(node) = CT_bool;
            return node;
        }
        break;
    }

    // Else we sent error
    CTI(CTI_ERROR, true, "\n Incompatible types error: at: line: %d col: %d-%d. \n",
        NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

    return node;
}

/**
 * @fn TCmonop
 */
node_st *TCmonop(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();

    // Traverse operand
    TRAVoperand(node);

    // Get inferred type
    enum Type type = data->inferred;

    // We infer the type bool when negation with bool.
    if (MONOP_OP(node) == MO_neg)
    {
        if (type == CT_bool)
        {
            data->inferred = CT_bool;
            MONOP_TYPE(node) = CT_bool;
            return node;
        }
    }

    // We infer the type num or float when unary minus with num or float
    if (MONOP_OP(node) == MO_not)
    {
        if (type == CT_float)
        {
            data->inferred = CT_float;
            MONOP_TYPE(node) = CT_float;
            return node;
        }

        if (type == CT_int)
        {
            data->inferred = CT_int;
            MONOP_TYPE(node) = CT_int;
            return node;
        }
    }

    // Else we sent error
    CTI(CTI_ERROR, true, "\n Incompatible types error: at: line: %d col: %d-%d. \n",
        NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

    return node;
}

/**
 * @fn TCvar
 */
node_st *TCvar(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();

    // We infer type
    node_st *decl = STE_DECL(TClookup(FUNDEF_SYMTBL(data->current_scope), VAR_NAME(node)));

    enum Type type;

    if (NODE_TYPE(decl) == NT_VARDECL)
    {
        type = VARDECL_TYPE(decl);
    }

    if (NODE_TYPE(decl) == NT_GLOBDEF)
    {
        type = GLOBDEF_TYPE(decl);
    }

    if (NODE_TYPE(decl) == NT_GLOBDECL)
    {
        type = GLOBDECL_TYPE(decl);
    }

    // We do a indices check
    if (VAR_INDICES(node) != NULL)
    {
        int decl_dims_count = TCcountindices(decl);

        int indices_count = TCcountindices(node);

        if (decl_dims_count != indices_count)
        {
            // We sent error if any other expressions mistmatches on type
            CTI(CTI_ERROR, true, "\n Array dimensions of variable do not match declared dimensions: at: line: %d col: %d-%d. \n",
                NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

            return node;
        }
    }

    switch (type)
    {
    case CT_int:
        data->inferred = CT_int;
        break;
    case CT_bool:
        data->inferred = CT_bool;
        break;
    case CT_float:
        data->inferred = CT_float;
        break;
    }

    return node;
}

/**
 * @fn TCvar
 */
node_st *TCvarlet(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();

    // We infer type
    node_st *decl = STE_DECL(TClookup(FUNDEF_SYMTBL(data->current_scope), VARLET_NAME(node)));

    enum Type type;

    if (NODE_TYPE(decl) == NT_VARDECL)
    {
        type = VARDECL_TYPE(decl);
    }

    if (NODE_TYPE(decl) == NT_GLOBDEF)
    {
        type = GLOBDEF_TYPE(decl);
    }

    if (NODE_TYPE(decl) == NT_GLOBDECL)
    {
        type = GLOBDECL_TYPE(decl);
    }

    switch (type)
    {
    case CT_int:
        data->inferred = CT_int;
        break;
    case CT_bool:
        data->inferred = CT_bool;
        break;
    case CT_float:
        data->inferred = CT_float;
        break;
    }

    return node;
}

/**
 * @fn TCfloat
 */
node_st *TCfloat(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();

    // We infer the type CT_float
    data->inferred = CT_float;

    return node;
}

/**
 * @fn TCbool
 */
node_st *TCbool(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();

    // We infer the type CT_bool
    data->inferred = CT_bool;

    return node;
}

/**
 * @fn TCnum
 */
node_st *TCnum(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();

    // We infer the type CT_num
    data->inferred = CT_int;

    return node;
}

// Type mismatch error

// Incompatible types error

//
