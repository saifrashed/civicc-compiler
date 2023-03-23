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

enum Type inferred = CT_NULL;

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

    if (NODE_TYPE(expr) == NT_VARLET)
    {
        dims = VARLET_INDICES(expr);

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

bool TChas_return(node_st *fundef)
{

    node_st *funbody = FUNDEF_BODY(fundef);

    if (funbody == NULL)
    {
        return false;
    }

    if (FUNBODY_STMTS(funbody) == NULL)
    {
        return false;
    }

    node_st *temp = FUNBODY_STMTS(funbody);

    while (temp != NULL)
    {

        if (NODE_TYPE(STMTS_STMT(temp)) == NT_RETURN)
        {
            return true;
        }

        temp = STMTS_NEXT(temp);
    }

    return false;
}

enum Type TCget_decl_type(node_st *decl)
{
    if (NODE_TYPE(decl) == NT_VARDECL)
    {
        return VARDECL_TYPE(decl);
    }

    if (NODE_TYPE(decl) == NT_GLOBDEF)
    {
        return GLOBDEF_TYPE(decl);
    }

    if (NODE_TYPE(decl) == NT_GLOBDECL)
    {
        return GLOBDECL_TYPE(decl);
    }

    return CT_NULL;
}

enum Type TCget_inferred_type(enum Type inferred)
{
    switch (inferred)
    {
    case CT_int:
        return CT_int;
        break;
    case CT_bool:
        return CT_bool;
        break;
    case CT_float:
        return CT_float;
        break;
    case CT_NULL:
        return CT_NULL;
        break;
    case CT_void:
        return CT_void;
        break;
    }

    return CT_NULL;
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
    // If __init or __allocate we skip type checking
    if (STReq(FUNDEF_NAME(node), "__allocate") || STReq(FUNDEF_NAME(node), "__init"))
    {
        return node;
    }

    if (FUNDEF_TYPE(node) == CT_void && TChas_return(node))
    {
        // We sent error if void function contains a return statement.
        CTI(CTI_ERROR, true, "\n Error: Invalid return statement at: line: %d col: %d-%d. \n",
            NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

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
    // skip allocate
    if (NODE_TYPE(ASSIGN_EXPR(node)) == NT_FUNCALL && STReq(FUNCALL_NAME(ASSIGN_EXPR(node)), "__allocate"))
    {
        return node;
    }

    struct data_tc *data = DATA_TC_GET();

    node_st *ste = TClookup(FUNDEF_SYMTBL(data->current_scope), VARLET_NAME(ASSIGN_LET(node)));

    // Traverse let
    TRAVlet(node);
    // Get inferred type
    enum Type let = inferred;

    // Traverse expr
    TRAVexpr(node);
    // Get inferred type
    enum Type expr = inferred;

    // Type check if assignment doesnt have a function call with allocate
    if (let != expr)
    {
        // We sent error if any other expressions mistmatches on type
        CTI(CTI_ERROR, true, "\n Error: Invalid assign statement at: line: %d col: %d-%d. \n",
            NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

        return node;
    }

    if (VARLET_INDICES(ASSIGN_LET(node)) != NULL)
    {
        int varlet_indices = TCcountindices(ASSIGN_LET(node));
        int decl_indices = TCcountindices(STE_DECL(ste));

        if (varlet_indices != decl_indices)
        {
            // We sent error if any other expressions mistmatches on type
            CTI(CTI_ERROR, true, "\n Error: Invalid assign statement at: line: %d col: %d-%d. \n",
                NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

            return node;
        }
    }

    return node;
}

/**
 * @fn TCifelse
 */
node_st *TCifelse(node_st *node)
{
    // Traverse cond and infer type
    TRAVcond(node);
    enum Type cond_type = inferred;

    // Must match bool
    if (cond_type != CT_bool)
    {
        // We sent error if any other expressions mistmatches on type
        CTI(CTI_ERROR, true, "\n Type error in loop expression: at: line: %d col: %d-%d. \n",
            NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

        return node;
    }

    return node;
}

/**
 * @fn TCfundef
 */
node_st *TCwhile(node_st *node)
{
    // Traverse cond and infer type
    TRAVcond(node);
    enum Type cond_type = inferred;

    // Must match bool
    if (cond_type != CT_bool)
    {
        // We sent error if any other expressions mistmatches on type
        CTI(CTI_ERROR, true, "\n Type error in loop expression: at: line: %d col: %d-%d. \n",
            NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

        return node;
    }

    return node;
}

/**
 * @fn TCfundef
 */
node_st *TCdowhile(node_st *node)
{
    // Traverse cond and infer type
    TRAVcond(node);
    enum Type cond_type = inferred;

    // Must match bool
    if (cond_type != CT_bool)
    {
        // We sent error if any other expressions mistmatches on type
        CTI(CTI_ERROR, true, "\n Type error in loop expression: at: line: %d col: %d-%d. \n",
            NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

        return node;
    }

    return node;
}

/**
 * @fn TCfor
 */
node_st *TCfor(node_st *node)
{
    // Traverse stop and infer type
    TRAVstop(node);
    enum Type stop_type = inferred;

    // Must match num
    if (stop_type != CT_int)
    {
        // We sent error if any other expressions mistmatches on type
        CTI(CTI_ERROR, true, "\n Type error in loop expression: at: line: %d col: %d-%d. \n",
            NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    // Traverse step and infer type
    TRAVstep(node);
    enum Type step_type = inferred;

    // Must match num
    if (step_type != CT_int)
    {
        // We sent error if any other expressions mistmatches on type
        CTI(CTI_ERROR, true, "\n Type error in loop expression: at: line: %d col: %d-%d. \n",
            NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    return node;
}

/**
 * @fn TCreturn
 */
node_st *TCreturn(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();

    // We determine function type
    enum Type fun_type = FUNDEF_TYPE(data->current_scope);

    // Traverse expressison
    enum Type return_type = inferred;

    TRAVexpr(node);
    return_type = inferred;

    if (fun_type != return_type)
    {
        // We sent error if any other return expressions mistmatches on function type
        CTI(CTI_ERROR, true, "\n Error: Invalid return type at: line: %d col: %d-%d. \n",
            NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));
    }

    return node;
}

/**
 * @fn TCcast
 */
node_st *TCcast(node_st *node)
{
    // We infer the type based on the type being cast. Bool, Int and Float are compatible with eachother.
    switch (CAST_TYPE(node))
    {
    case CT_int:
        inferred = CT_int;
        break;
    case CT_bool:
        inferred = CT_bool;
        break;
    case CT_float:
        inferred = CT_float;
        break;
    case CT_void:
        inferred = CT_void;
        break;
    case CT_NULL:
        inferred = CT_NULL;
        break;
    }

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

    while (param != NULL && arg != NULL)
    {
        // If any pair has different types, then the types don't match and we sent an error.
        enum Type param_type = PARAM_TYPE(param);

        TRAVexpr(arg);
        enum Type arg_type = inferred;

        // We check if the types align.
        if (param_type != arg_type)
        {
            // We sent error if any other expressions mistmatches on type
            CTI(CTI_ERROR, true, "\n Function parameter types don't match: at: line: %d col: %d-%d. \n",
                NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

            return node;
        }

        arg = EXPRS_NEXT(arg);
        param = PARAM_NEXT(param);
    }

    // We infer type num or float if all expressions are one of two.
    inferred = type;

    return node;
}

/**
 * @fn TCbinop
 */
node_st *TCbinop(node_st *node)
{
    // Traverse left
    TRAVleft(node);
    // Get inferred type
    enum Type left = inferred;

    // Traverse right
    TRAVright(node);
    // Get inferred type
    enum Type right = inferred;

    // Infer the correct types.
    switch (BINOP_OP(node)) // Arithmetic operators
    {
    case BO_add:
    case BO_mul:
        if (left == CT_bool && right == CT_bool)
        {
            inferred = CT_bool;
            BINOP_TYPE(node) = CT_bool;
            return node;
        }
        else if (left == CT_int && right == CT_int)
        {
            inferred = CT_int;
            BINOP_TYPE(node) = CT_int;
            return node;
        }
        else if (left == CT_float && right == CT_float)
        {
            inferred = CT_float;
            BINOP_TYPE(node) = CT_float;
            return node;
        }
        break;
    case BO_sub:
    case BO_div:
        if (left == CT_int && right == CT_int)
        {
            inferred = CT_int;
            BINOP_TYPE(node) = CT_int;
            return node;
        }
        else if (left == CT_float && right == CT_float)
        {
            inferred = CT_float;
            BINOP_TYPE(node) = CT_float;
            return node;
        }
        break;
    case BO_mod:
        if (left == CT_int && right == CT_int)
        {
            inferred = CT_int;
            BINOP_TYPE(node) = CT_int;
            return node;
        }
        break;
    case BO_lt:
    case BO_le:
    case BO_gt:
    case BO_ge:
        if ((left == CT_int || left == CT_float) && (right == CT_int || right == CT_float))
        {
            inferred = CT_bool;
            BINOP_TYPE(node) = CT_bool;
            return node;
        }
        break;
    case BO_eq:
    case BO_ne:
        if (left == right && (left == CT_bool || left == CT_int || left == CT_float))
        {
            inferred = CT_bool;
            BINOP_TYPE(node) = CT_bool;
            return node;
        }
        break;
    case BO_and:
    case BO_or:
        if (left == CT_bool && right == CT_bool)
        {
            inferred = CT_bool;
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
    // Traverse operand
    TRAVoperand(node);

    // Get inferred type
    enum Type type = inferred;

    // We infer the type bool when negation with bool.
    if (MONOP_OP(node) == MO_neg)
    {
        if (type == CT_bool)
        {
            inferred = CT_bool;
            MONOP_TYPE(node) = CT_bool;
            return node;
        }
    }

    // We infer the type num or float when unary minus with num or float
    if (MONOP_OP(node) == MO_not)
    {
        if (type == CT_float)
        {
            inferred = CT_float;
            MONOP_TYPE(node) = CT_float;
            return node;
        }

        if (type == CT_int)
        {
            inferred = CT_int;
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
    node_st *ste = TClookup(FUNDEF_SYMTBL(data->current_scope), VAR_NAME(node));
    enum Type type = STE_TYPE(ste);

    // We do a indices check
    if (VAR_INDICES(node) != NULL)
    {
        int decl_dims_count = TCcountindices(STE_DECL(ste));
        int indices_count = TCcountindices(node);

        if (decl_dims_count != indices_count)
        {
            // We sent error if any other expressions mistmatches on type
            CTI(CTI_ERROR, true, "\n Array dimensions of variable do not match declared dimensions: at: line: %d col: %d-%d. \n",
                NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

            return node;
        }
    }

    inferred = type;

    return node;
}

/**
 * @fn TCvar
 */
node_st *TCvarlet(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();

    // We infer type
    node_st *ste = TClookup(FUNDEF_SYMTBL(data->current_scope), VARLET_NAME(node));

    enum Type type = STE_TYPE(ste);

    if (NODE_TYPE(ste) == NT_PARAM && PARAM_DIMS(ste) != NULL)
    {
        // We do a indices check if this varlet is simply a assign varlet.
        int decl_dims_count = TCcountindices(STE_DECL(ste));

        int indices_count = TCcountindices(node);

        if (decl_dims_count != indices_count)
        {
            // We sent error if any other expressions mistmatches on type
            CTI(CTI_ERROR, true, "\n Array dimensions of variable do not match declared dimensions: at: line: %d col: %d-%d. \n",
                NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

            return node;
        }
    }

    inferred = type;

    return node;
}

/**
 * @fn TCfloat
 */
node_st *TCfloat(node_st *node)
{
    // We infer the type CT_float
    inferred = CT_float;

    return node;
}

/**
 * @fn TCbool
 */
node_st *TCbool(node_st *node)
{
    // We infer the type CT_bool
    inferred = CT_bool;

    return node;
}

/**
 * @fn TCnum
 */
node_st *TCnum(node_st *node)
{
    // We infer the type CT_num
    inferred = CT_int;

    return node;
}

// Type mismatch error

// Incompatible types error

//

// switch (return_type)
// {
// case CT_int:
//     printf("%s: CT_int\n", FUNDEF_NAME(node));
//     break;
// case CT_bool:
//     printf("%s: CT_bool\n", FUNDEF_NAME(node));
//     break;
// case CT_float:
//     printf("%s: CT_float\n", FUNDEF_NAME(node));
//     break;
// case CT_NULL:
//     printf("%s: CT_NULL\n", FUNDEF_NAME(node));
//     break;
// case CT_void:
//     printf("%s: CT_void\n", FUNDEF_NAME(node));
//     break;
// }

// switch (fun_type)
// {
// case CT_int:
//     printf("%s: CT_int\n", FUNDEF_NAME(node));
//     break;
// case CT_bool:
//     printf("%s: CT_bool\n", FUNDEF_NAME(node));
//     break;
// case CT_float:
//     printf("%s: CT_float\n", FUNDEF_NAME(node));
//     break;
// case CT_NULL:
//     printf("%s: CT_NULL\n", FUNDEF_NAME(node));
//     break;
// case CT_void:
//     printf("%s: CT_void\n", FUNDEF_NAME(node));
//     break;
// }

// printf("\n\n");
