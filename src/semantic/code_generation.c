
/**
 * @file
 *
 * This file contains the code for the CodeGeneration traversal.
 * The traversal has the uid: CG
 */

#include <string.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"
#include "palm/str.h"
#include "global/globals.h"
#include <stdio.h>
#include "palm/ctinfo.h"

// 1. To create a assembly file  ./civicc ../test/arrays/check_success/scopes.cvc -o test  - in build-debug for own
// 1. To create a assembly file  ../civcc ../test/arrays/check_success/test.cvc -o test    - in bin for reference

// Don't forget to turn on functional tests in the makefile

// *** Things to do *** //
// 1. A function that counts total amount of elements in a symbol table.
// 2. A Hash table in the travdata that keeps track of the constant pool
// 3. A function that gets index from the symbol table.

int constant_index = 0;

int CGcount_symtbl(node_st *symtbl)
{
    int count = 0;

    node_st *temp = SYMTBL_HEAD(symtbl);

    while (temp != NULL)
    {
        count++;
        temp = STE_NEXT(temp);
    }

    return count;
}

node_st *CGlookup_symtbl(node_st *symbol_table, char *identifier)
{
    // Check if the symbol table or identifier are NULL
    if (symbol_table == NULL || identifier == NULL)
    {
        return NULL;
    }

    // Check if the identifier exists in the symbol table
    node_st *entry = SYMTBL_HEAD(symbol_table);
    while (entry != NULL)
    {
        if (STReq(STE_NAME(entry), identifier) == true)
        {
            // Identifier found in the symbol table
            return entry;
        }
        entry = STE_NEXT(entry);
    }

    // Identifier not found in the symbol table
    return NULL;
}

int CGindex_symtbl(node_st *symbol_table, char *identifier)
{
    int index = 0;

    // Check if the symbol table or identifier are NULL
    if (symbol_table == NULL || identifier == NULL)
    {
        return NULL;
    }

    // Check if the identifier exists in the symbol table
    node_st *entry = SYMTBL_HEAD(symbol_table);
    while (entry != NULL)
    {

        if (STReq(STE_NAME(entry), identifier) == true)
        {
            // Identifier found in the symbol table
            return index;
        }

        index++;
        entry = STE_NEXT(entry);
    }

    // Identifier not found in the symbol table
    return NULL;
}

void CGinsert_constbl(node_st *constant_table, enum Type type, node_st *constant)
{
    // Check for null pointers
    if (!constant_table || !type || !constant)
    {
        return;
    }

    // Find the tail of the constant table
    node_st *tail = CONSTBL_HEAD(constant_table);
    if (tail)
    {
        while (CTE_NEXT(tail))
        {
            tail = CTE_NEXT(tail);
        }
    }
    else
    { // Set the head of the symbol table if it's empty
        CONSTBL_HEAD(constant_table) = ASTcte(NULL, constant, type);
        return;
    }

    // Add a new entry to the tail of the symbol table
    CTE_NEXT(tail) = ASTcte(NULL, constant, type);
}

int CGindex_constbl(node_st *constant_table, node_st *constant)
{
    int index = 0;

    // Check if the symbol table or identifier are NULL
    if (constant_table == NULL || constant == NULL)
    {
        return -1;
    }

    // Check if the constant exists in the symbol table
    node_st *entry = CONSTBL_HEAD(constant_table);
    while (entry != NULL)
    {
        if (NODE_TYPE(constant) == NT_NUM && NODE_TYPE(CTE_CONSTANT(entry)) == NT_NUM)
        {
            if (NUM_VAL(constant) == NUM_VAL(CTE_CONSTANT(entry)))
            {
                // Value found in the constant table
                return index;
            }
        }

        if (NODE_TYPE(constant) == NT_FLOAT && NODE_TYPE(CTE_CONSTANT(entry)) == NT_FLOAT)
        {
            if (FLOAT_VAL(constant) == FLOAT_VAL(CTE_CONSTANT(entry)))
            {
                // Value found in the constant table
                return index;
            }
        }

        index++;
        entry = CTE_NEXT(entry);
    }

    // Identifier not found in the symbol table
    return -1;
}

void CGinit()
{
    FILE *file = fopen(global.output_file, "w");

    if (file != NULL)
    {
        struct data_cg *data = DATA_CG_GET();
        data->output_file = file;

        // fprintf(data->output_file, "Sterkkk\n");
    }
    else
    {
        // We sent error if any other expressions mistmatches on type
        CTI(CTI_ERROR, true, "\n Error: global file not found. \n");
        CCNerrorAction();
    }

    return;
}
void CGfini()
{
    struct data_cg *data = DATA_CG_GET();

    if (data->output_file != NULL)
    {
        fclose(data->output_file);
    }

    return;
}

/**
 * @fn CGprogram
 */
node_st *CGprogram(node_st *node)
{
    // Set the current scope of the program's data to be the node being traversed
    struct data_cg *data = DATA_CG_GET();

    PROGRAM_CONSTBL(node) = ASTconstbl(NULL); // We create a constant table.

    data->constbl = PROGRAM_CONSTBL(node); // We make the constant table accessible.

    data->current_scope = node;

    // Traverse the children of the current node
    TRAVchildren(node);

    // Reset the parent node as the current scope
    data->current_scope = node;

    // Return the current node
    return node;
}

/**
 * @fn CGfundef
 */
node_st *CGfundef(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    // write label
    fprintf(data->output_file, "%s:\n", FUNDEF_NAME(node));

    // Make space on the stack with ESR for N elements in symbol table
    int free_amount = CGcount_symtbl(FUNDEF_SYMTBL(node));

    if (free_amount > 0)
    {
        fprintf(data->output_file, "    esr %d\n", free_amount);
    }

    node_st *outer = data->current_scope;

    // Set this node as the current scope
    data->current_scope = node;

    TRAVchildren(node);

    // Reset the parent node as the current scope
    data->current_scope = outer;

    fprintf(data->output_file, "\n");

    return node;
}

/**
 * @fn CGassign
 */
node_st *CGassign(node_st *node)
{
    TRAVexpr(node); // traverse into right (some expression)
    TRAVlet(node);  // traverse into left (varlet)

    return node;
}

/**
 * @fn CGassign
 */
node_st *CGreturn(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    TRAVexpr(node);

    switch (FUNDEF_TYPE(data->current_scope))
    {
    case CT_int:
        fprintf(data->output_file, "    ireturn\n");
        break;
    case CT_bool:
        fprintf(data->output_file, "    breturn\n");
        break;
    case CT_float:
        fprintf(data->output_file, "    freturn\n");
        break;
    case CT_NULL:
        fprintf(data->output_file, "    return\n");
        break;
    case CT_void:
        fprintf(data->output_file, "    return\n");
        break;
    }

    return node;
}

/**
 * @fn CGbinop
 */
node_st *CGbinop(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    // TRAV left
    TRAVleft(node);

    // TRAV right
    TRAVright(node);

    // PUSH BINOP OP instruction
    switch (BINOP_OP(node))
    {
    case BO_add:
        if (BINOP_TYPE(node) == CT_int)
        {
            fprintf(data->output_file, "    iadd\n");
        }

        if (BINOP_TYPE(node) == CT_float)
        {
            fprintf(data->output_file, "    fadd\n");
        }
        break;
    case BO_sub:
        if (BINOP_TYPE(node) == CT_int)
        {
            fprintf(data->output_file, "    isub\n");
        }

        if (BINOP_TYPE(node) == CT_float)
        {
            fprintf(data->output_file, "    fsub\n");
        }
        break;
    case BO_mul:
        if (BINOP_TYPE(node) == CT_int)
        {
            fprintf(data->output_file, "    imul\n");
        }

        if (BINOP_TYPE(node) == CT_float)
        {
            fprintf(data->output_file, "    fmul\n");
        }
        break;
    case BO_div:
        if (BINOP_TYPE(node) == CT_int)
        {
            fprintf(data->output_file, "    idiv\n");
        }

        if (BINOP_TYPE(node) == CT_float)
        {
            fprintf(data->output_file, "    fdiv\n");
        }
        break;
    case BO_mod:
        if (BINOP_TYPE(node) == CT_int)
        {
            fprintf(data->output_file, "    imod\n");
        }

        if (BINOP_TYPE(node) == CT_float)
        {
            fprintf(data->output_file, "    fmod\n");
        }
        break;
    case BO_lt:
        if (BINOP_TYPE(node) == CT_int)
        {
            fprintf(data->output_file, "    ilt\n");
        }

        if (BINOP_TYPE(node) == CT_float)
        {
            fprintf(data->output_file, "    flt\n");
        }
        break;
    case BO_le:
        if (BINOP_TYPE(node) == CT_int)
        {
            fprintf(data->output_file, "    ile\n");
        }

        if (BINOP_TYPE(node) == CT_float)
        {
            fprintf(data->output_file, "    fle\n");
        }
        break;
    case BO_gt:
        if (BINOP_TYPE(node) == CT_int)
        {
            fprintf(data->output_file, "    igt\n");
        }

        if (BINOP_TYPE(node) == CT_float)
        {
            fprintf(data->output_file, "    fgt\n");
        }
        break;
    case BO_ge:
        if (BINOP_TYPE(node) == CT_int)
        {
            fprintf(data->output_file, "    ige\n");
        }

        if (BINOP_TYPE(node) == CT_float)
        {
            fprintf(data->output_file, "    fge\n");
        }
        break;
    case BO_eq:
        if (BINOP_TYPE(node) == CT_int)
        {
            fprintf(data->output_file, "    ieq\n");
        }

        if (BINOP_TYPE(node) == CT_float)
        {
            fprintf(data->output_file, "    feq\n");
        }
        break;
    case BO_ne:
        if (BINOP_TYPE(node) == CT_int)
        {
            fprintf(data->output_file, "    ine\n");
        }

        if (BINOP_TYPE(node) == CT_float)
        {
            fprintf(data->output_file, "    fne\n");
        }
        break;
    case BO_or:
    case BO_and:
        break;
    case BO_NULL:
        DBUG_ASSERT(false, "unknown binop detected!");
    }

    return node;
}

/**
 * @fn CGmonop
 */
node_st *CGmonop(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    // TRAV operand
    TRAVoperand(node);

    // PUSH MONOP instruction
    switch (MONOP_OP(node))
    {
    case MO_not:
        if (MONOP_TYPE(node) == CT_bool)
        {
            fprintf(data->output_file, "    bnot\n");
        }
        break;
    case MO_neg:
        if (MONOP_TYPE(node) == CT_int)
        {
            fprintf(data->output_file, "    ineg\n");
        }

        if (MONOP_TYPE(node) == CT_float)
        {
            fprintf(data->output_file, "    fneg\n");
        }
        break;
    case MO_NULL:
        DBUG_ASSERT(false, "unknown unary detected!");
    }

    return node;
}

/**
 * @fn CGvar
 */
node_st *CGvarlet(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    node_st *ste = CGlookup_symtbl(FUNDEF_SYMTBL(data->current_scope), VARLET_NAME(node));
    int index = CGindex_symtbl(FUNDEF_SYMTBL(data->current_scope), VARLET_NAME(node));

    // depending on STE type:

    if (ste != NULL)
    {
        // int - istore [index from symbol table]
        if (STE_TYPE(ste) == CT_int)
        {
            fprintf(data->output_file, "    istore %d\n", index);
        }

        // float - fstore [index from symbol table]
        if (STE_TYPE(ste) == CT_float)
        {
            fprintf(data->output_file, "    fstore %d\n", index);
        }

        // bool - bstore [index from symbol table]
        if (STE_TYPE(ste) == CT_bool)
        {
            fprintf(data->output_file, "    bstore %d\n", index);
        }
    }

    return node;
}

/**
 * @fn CGvar
 */
node_st *CGvar(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    node_st *ste = CGlookup_symtbl(FUNDEF_SYMTBL(data->current_scope), VAR_NAME(node));
    int index = CGindex_symtbl(FUNDEF_SYMTBL(data->current_scope), VAR_NAME(node));

    // depending on STE type:

    if (ste != NULL)
    {
        // int - iload [index from symbol table]
        if (STE_TYPE(ste) == CT_int)
        {
            fprintf(data->output_file, "    iload %d\n", index);
        }

        // float - fload [index from symbol table]
        if (STE_TYPE(ste) == CT_float)
        {
            fprintf(data->output_file, "    fload %d\n", index);
        }

        // bool - bload [index from symbol table]
        if (STE_TYPE(ste) == CT_bool)
        {
            fprintf(data->output_file, "    bload %d\n", index);
        }
    }

    return node;
}

/**
 * @fn CGnum
 */
node_st *CGnum(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    // get index from constant table (if none we add it)
    int index = CGindex_constbl(data->constbl, node);

    if (index != -1) // There is a constant field.
    {
        fprintf(data->output_file, "    iloadc %d\n", index);
    }
    else // There is none so add
    {
        CGinsert_constbl(data->constbl, CT_int, node);
        int index = CGindex_constbl(data->constbl, node);
        fprintf(data->output_file, "    iloadc %d\n", index);
    }

    return node;
}

/**
 * @fn CGfloat
 */
node_st *CGfloat(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    // get index from constant table (if none we add it)
    int index = CGindex_constbl(data->constbl, node);

    if (index != -1) // There is a constant field.
    {
        fprintf(data->output_file, "    floadc %d\n", index);
    }
    else // There is none so add
    {
        CGinsert_constbl(data->constbl, CT_float, node);
        int index = CGindex_constbl(data->constbl, node);
        fprintf(data->output_file, "    floadc %d\n", index);
    }

    return node;
}

/**
 * @fn CGbool
 */
node_st *CGbool(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    if (BOOL_VAL(node) == true)
    { // bloadc_t - if true
        fprintf(data->output_file, "    bloadc_t\n");
    }
    else
    { // bloadc_f - if false
        fprintf(data->output_file, "    bloadc_f\n");
    }

    return node;
}
