
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

int prefix_counter = 0; // Used to give labels a unique name.

char *CGimportfun(node_st *fundef)
{
    char *instruction = "";

    char *type = NULL;

    switch (FUNDEF_TYPE(fundef))
    {
    case CT_bool:
        type = "bool";
        break;
    case CT_float:
        type = "float";
        break;
    case CT_int:
        type = "int";
        break;
    case CT_void:
        type = "void";
        break;
    case CT_NULL:
        DBUG_ASSERT(false, "unknown type detected!");
    }

    char *params = "";

    if (FUNDEF_PARAMS(fundef) != NULL)
    {
        node_st *temp = FUNDEF_PARAMS(fundef);

        while (temp != NULL)
        {
            switch (PARAM_TYPE(temp))
            {
            case CT_bool:
                params = STRcat(params, " bool");
                break;
            case CT_float:
                params = STRcat(params, " float");
                break;
            case CT_int:
                params = STRcat(params, " int");
                break;
            case CT_void:
                params = STRcat(params, " void");
                break;
            case CT_NULL:
                DBUG_ASSERT(false, "unknown type detected!");
            }

            temp = PARAM_NEXT(temp);
        }
    }

    // If fun does not have a body - and types

    instruction = STRcat(instruction, ".importfun ");
    instruction = STRcat(instruction, "\"");
    instruction = STRcat(instruction, FUNDEF_NAME(fundef));
    instruction = STRcat(instruction, "\" ");
    instruction = STRcat(instruction, type);
    instruction = STRcat(instruction, params);
    instruction = STRcat(instruction, "\n");

    return instruction;
}

char *CGexportfun(node_st *fundef)
{
    char *instruction = "";

    char *type = NULL;

    switch (FUNDEF_TYPE(fundef))
    {
    case CT_bool:
        type = "bool";
        break;
    case CT_float:
        type = "float";
        break;
    case CT_int:
        type = "int";
        break;
    case CT_void:
        type = "void";
        break;
    case CT_NULL:
        DBUG_ASSERT(false, "unknown type detected!");
    }

    char *params = "";

    if (FUNDEF_PARAMS(fundef) != NULL)
    {
        node_st *temp = FUNDEF_PARAMS(fundef);

        while (temp != NULL)
        {
            switch (PARAM_TYPE(temp))
            {
            case CT_bool:
                params = STRcat(params, " bool");
                break;
            case CT_float:
                params = STRcat(params, " float");
                break;
            case CT_int:
                params = STRcat(params, " int");
                break;
            case CT_void:
                params = STRcat(params, " void");
                break;
            case CT_NULL:
                DBUG_ASSERT(false, "unknown type detected!");
            }

            temp = PARAM_NEXT(temp);
        }
    }

    instruction = STRcat(instruction, ".exportfun ");
    instruction = STRcat(instruction, "\"");
    instruction = STRcat(instruction, FUNDEF_NAME(fundef));
    instruction = STRcat(instruction, "\" ");
    instruction = STRcat(instruction, type);
    instruction = STRcat(instruction, params);
    instruction = STRcat(instruction, " ");
    instruction = STRcat(instruction, FUNDEF_NAME(fundef));
    instruction = STRcat(instruction, "\n");

    return instruction;
}

// Generate a unique signature for a given function definition node
char *CGgeneratesignature(node_st *function_definition)
{
    // Copy the function name to a new string in memory
    char *signature = STRcpy(FUNDEF_NAME(function_definition));

    // Initialize a counter variable for the number of parameters
    int parameter_count = 0;

    // Check if there are any parameters in the function definition
    if (FUNDEF_PARAMS(function_definition) != NULL)
    {

        // Count the number of parameters
        node_st *parameter = FUNDEF_PARAMS(function_definition);
        while (parameter != NULL)
        {
            parameter_count++;
            parameter = PARAM_NEXT(parameter);
        }
    }

    // Append the parameter count to the signature string
    char parameter_count_string[10];
    snprintf(parameter_count_string, 10, "_%d", parameter_count);
    signature = STRcat(signature, parameter_count_string);

    return signature;
}

node_st *CGlookup(node_st *symtbl, char *identifier)
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

int global_index = 0;    // index for global table
int constant_index = 0;  // index for constant table
int importfun_index = 0; // index for import function table
int importvar_index = 0; // index for import variable table

char *instruction_string = ""; // to be shown in the end

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

    data->current_scope = node;

    // Traverse the children of the current node
    TRAVchildren(node);

    // Reset the parent node as the current scope
    data->current_scope = node;

    // print instructions
    fprintf(data->output_file, "\n%s", instruction_string);

    return node;
}

/**
 * @fn CGvardecl
 */
node_st *CGvardecl(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    node_st *ste = CGlookup(FUNDEF_SYMTBL(data->current_scope), VARDECL_NAME(node));

    // Get index in symbol table.
    int index = 0;

    node_st *temp = SYMTBL_HEAD(FUNDEF_SYMTBL(data->current_scope));

    while (STReq(STE_NAME(temp), VARDECL_NAME(node)) == false)
    {
        index++;
        temp = STE_NEXT(temp);
    }

    STE_ASSEMBLY_INDEX(ste) = index;

    TRAVnext(node);

    return node;
}

/**
 * @fn CGparam
 */
node_st *CGparam(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    node_st *ste = CGlookup(FUNDEF_SYMTBL(data->current_scope), PARAM_NAME(node));

    // printf("\n\n");
    switch (STE_TYPE(node))
    {
    case CT_int:
        printf("CT_int\n");
        break;
    case CT_bool:
        printf(" CT_bool\n");
        break;
    case CT_float:
        printf(" CT_float\n");
        break;
    case CT_NULL:
        printf("CT_NULL\n");
        break;
    case CT_void:
        printf(" CT_void\n");
        break;
    }
    // Get index in symbol table.
    int index = 0;

    node_st *temp = SYMTBL_HEAD(FUNDEF_SYMTBL(data->current_scope));

    while (STReq(STE_NAME(temp), PARAM_NAME(node)) == false)
    {
        index++;
        temp = STE_NEXT(temp);
    }

    STE_ASSEMBLY_INDEX(ste) = index;

    TRAVnext(node);

    return node;
}

/**
 * @fn CGglobdef
 */
node_st *CGglobdef(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    node_st *ste = CGlookup(PROGRAM_SYMTBL(data->current_scope), GLOBDEF_NAME(node));

    // Add to global table
    if (GLOBDEF_TYPE(node) == CT_int)
    {
        instruction_string = STRcat(instruction_string, ".global int\n");
    }

    if (GLOBDEF_TYPE(node) == CT_bool)
    {
        instruction_string = STRcat(instruction_string, ".global bool\n");
    }

    if (GLOBDEF_TYPE(node) == CT_float)
    {
        instruction_string = STRcat(instruction_string, ".global float\n");
    }

    // Add index to STE
    STE_ASSEMBLY_INDEX(ste) = global_index;

    printf("RESULT: %d\n", STE_ASSEMBLY_INDEX(ste));

    // Add to exportvar table
    if (GLOBDEF_EXPORT(node))
    {
        instruction_string = STRcat(instruction_string, ".exportvar \"");
        instruction_string = STRcat(instruction_string, GLOBDEF_NAME(node));
        instruction_string = STRcat(instruction_string, "\" ");
        instruction_string = STRcat(instruction_string, STRitoa(global_index));
        instruction_string = STRcat(instruction_string, "\n");
    }

    // increment value
    global_index++;

    return node;
}

/**
 * @fn CGglobdecl
 */
node_st *CGglobdecl(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    node_st *ste = CGlookup(PROGRAM_SYMTBL(data->current_scope), GLOBDECL_NAME(node));

    // add to importvar
    instruction_string = STRcat(instruction_string, ".importvar \"");
    instruction_string = STRcat(instruction_string, GLOBDECL_NAME(node));
    instruction_string = STRcat(instruction_string, "\" ");

    if (GLOBDECL_TYPE(node) == CT_int)
    {
        instruction_string = STRcat(instruction_string, "int");
    }

    if (GLOBDECL_TYPE(node) == CT_bool)
    {
        instruction_string = STRcat(instruction_string, "bool");
    }

    if (GLOBDECL_TYPE(node) == CT_float)
    {
        instruction_string = STRcat(instruction_string, "float");
    }

    instruction_string = STRcat(instruction_string, "\n");

    // add index to STE

    STE_ASSEMBLY_INDEX(ste) = importvar_index;

    // increment value
    importvar_index++;

    return node;
}

/**
 * @fn CGfundef
 */
node_st *CGfundef(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    char *signature = CGgeneratesignature(node);
    node_st *ste;

    if (NODE_TYPE(data->current_scope) == NT_PROGRAM)
    {
        ste = CGlookup(PROGRAM_SYMTBL(data->current_scope), signature);
    }
    if (NODE_TYPE(data->current_scope) == NT_FUNDEF)
    {
        ste = CGlookup(FUNDEF_SYMTBL(data->current_scope), signature);
    }

    if (STReq(FUNDEF_NAME(node), "__allocate"))
    {
        // If function is allocate we skip doing anything
        return node;
    }

    if (STReq(FUNDEF_NAME(node), "main") || STReq(FUNDEF_NAME(node), "__init") || FUNDEF_EXPORT(node))
    {
        // If function is main or init or export
        // exportfun
        instruction_string = STRcat(instruction_string, CGexportfun(node));
    }

    if (FUNDEF_BODY(node) == NULL)
    {
        // importfun
        instruction_string = STRcat(instruction_string, CGimportfun(node));
        STE_ASSEMBLY_INDEX(ste) = importfun_index;
        importfun_index++;

        return node;
    }

    // write label
    fprintf(data->output_file, "%s:\n", FUNDEF_NAME(node));

    // Make space on the stack with ESR for N elements in symbol table
    int free_amount = 0;

    node_st *temp = SYMTBL_HEAD(FUNDEF_SYMTBL(node));

    while (temp != NULL)
    {
        free_amount++;
        temp = STE_NEXT(temp);
    }

    if (free_amount > 0)
    {
        fprintf(data->output_file, "    esr %d\n", free_amount);
    }

    node_st *outer = data->current_scope;

    // Set this node as the current scope
    data->current_scope = node;

    TRAVparams(node);
    TRAVbody(node);

    // Reset the parent node as the current scope
    data->current_scope = outer;

    if (FUNDEF_TYPE(node) == CT_void)
    {
        fprintf(data->output_file, "    return\n");
    }

    fprintf(data->output_file, "\n");

    return node;
}

/**
 * @fn CGfuncall
 */
node_st *CGfuncall(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    node_st *ste = FUNCALL_ENTRY(node);

    node_st *fundef = STE_DECL(ste);

    fprintf(data->output_file, "    isrg\n");

    TRAVargs(node);

    if (FUNDEF_BODY(fundef) != NULL)
    {

        int count = 0;

        if (FUNCALL_ARGS(node) != NULL)
        {
            node_st *temp = FUNCALL_ARGS(node);

            while (temp != NULL)
            {
                count++;

                temp = EXPRS_NEXT(temp);
            }
        }

        // regularfun
        fprintf(data->output_file, "    jsr %d %s\n", count, FUNDEF_NAME(fundef));
    }

    if (FUNDEF_BODY(fundef) == NULL)
    {
        // importfun
        fprintf(data->output_file, "    jsre %d\n", STE_ASSEMBLY_INDEX(ste));
    }

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
        break;
    case CT_void:
        fprintf(data->output_file, "    return\n");
        break;
    }

    return node;
}

/**
 * @fn CGwhile
 */
node_st *CGwhile(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    char *while_label = STRcat(STRitoa(prefix_counter), "_while");
    prefix_counter++;
    char *end_label = STRcat(STRitoa(prefix_counter), "_end");
    prefix_counter++;

    fprintf(data->output_file, "%s:\n", while_label);

    TRAVcond(node);

    fprintf(data->output_file, "    branch_f %s\n", end_label);

    TRAVblock(node);

    fprintf(data->output_file, "    jump %s\n", while_label);

    fprintf(data->output_file, "%s:\n", end_label);

    return node;
}

/**
 * @fn CGdowhile
 */
node_st *CGdowhile(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    char *dowhile_label = STRcat(STRitoa(prefix_counter), "_dowhile");
    prefix_counter++;

    fprintf(data->output_file, "%s:\n", dowhile_label);
    TRAVblock(node);
    TRAVcond(node);
    fprintf(data->output_file, "    branch_t %s\n", dowhile_label);

    return node;
}

/**
 * @fn CGifelse
 */
node_st *CGifelse(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    char *else_label = STRcat(STRitoa(prefix_counter), "_else");
    prefix_counter++;
    char *end_label = STRcat(STRitoa(prefix_counter), "_end");
    prefix_counter++;

    TRAVcond(node);

    fprintf(data->output_file, "    branch_f %s\n", else_label);

    TRAVthen(node);

    fprintf(data->output_file, "    jump %s\n", end_label);

    fprintf(data->output_file, "%s:\n", else_label);

    TRAVelse_block(node);

    fprintf(data->output_file, "%s:\n", end_label);

    return node;
}

/**
 * @fn CGternary
 */
node_st *CGternary(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    char *else_label = STRcat(STRitoa(prefix_counter), "_false_expr");
    prefix_counter++;
    char *end_label = STRcat(STRitoa(prefix_counter), "_end");
    prefix_counter++;

    TRAVcond(node);

    fprintf(data->output_file, "    branch_f %s\n", else_label);

    TRAVthen(node);

    fprintf(data->output_file, "    jump %s\n", end_label);

    fprintf(data->output_file, "%s:\n", else_label);

    TRAVelse_block(node);

    fprintf(data->output_file, "%s:\n", end_label);

    return node;
}

/**
 * @fn CGcast
 */
node_st *CGcast(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    // get index from constant table (if none we add it)
    if (CAST_TYPE(node) == CT_bool)
    {

        if (NODE_TYPE(CAST_EXPR(node)) == NT_FLOAT)
        {
            if (FLOAT_VAL(CAST_EXPR(node)) > 0)
            {
                fprintf(data->output_file, "    bloadc_t\n");
            }
            else
            {
                fprintf(data->output_file, "    bloadc_f\n");
            }
        }

        if (NODE_TYPE(CAST_EXPR(node)) == NT_NUM)
        {
            if (NUM_VAL(CAST_EXPR(node)) > 0)
            {
                fprintf(data->output_file, "    bloadc_t\n");
            }
            else
            {
                fprintf(data->output_file, "    bloadc_f\n");
            }
        }
    }

    if (CAST_TYPE(node) == CT_int)
    {
        TRAVexpr(node); // Traverse expression

        if (NODE_TYPE(CAST_EXPR(node)) == NT_FLOAT)
        {
            fprintf(data->output_file, "    f2i\n");
        }

        if (NODE_TYPE(CAST_EXPR(node)) == NT_BINOP && BINOP_TYPE(CAST_EXPR(node)) == CT_float)
        {
            fprintf(data->output_file, "    f2i\n");
        }

        if (NODE_TYPE(CAST_EXPR(node)) == NT_VAR)
        {
            node_st *ste = CGlookup(FUNDEF_SYMTBL(data->current_scope), VAR_NAME(CAST_EXPR(node)));

            if (STE_TYPE(ste) == CT_float)
            {
                fprintf(data->output_file, "    f2i\n");
            }
        }
    }

    if (CAST_TYPE(node) == CT_float)
    {
        TRAVexpr(node); // Traverse expression

        if (NODE_TYPE(CAST_EXPR(node)) == NT_NUM)
        {
            fprintf(data->output_file, "    i2f\n");
        }

        if (NODE_TYPE(CAST_EXPR(node)) == NT_BINOP && BINOP_TYPE(CAST_EXPR(node)) == CT_int)
        {
            fprintf(data->output_file, "    i2f\n");
        }

        if (NODE_TYPE(CAST_EXPR(node)) == NT_VAR)
        {
            node_st *ste = CGlookup(FUNDEF_SYMTBL(data->current_scope), VAR_NAME(CAST_EXPR(node)));

            if (STE_TYPE(ste) == CT_int)
            {
                fprintf(data->output_file, "    i2f\n");
            }
        }
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

        if (BINOP_TYPE(node) == CT_bool)
        {
            fprintf(data->output_file, "    badd\n");
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

        if (BINOP_TYPE(node) == CT_bool)
        {
            fprintf(data->output_file, "    bmul\n");
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
            fprintf(data->output_file, "    irem\n");
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

        if (BINOP_TYPE(node) == CT_bool)
        {
            fprintf(data->output_file, "    beq\n");
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

        if (BINOP_TYPE(node) == CT_bool)
        {
            fprintf(data->output_file, "    bne\n");
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

    node_st *ste = VARLET_ENTRY(node);

    // depending on STE type:
    if (ste != NULL)
    {
        // int - istore [index from symbol table]
        if (STE_TYPE(ste) == CT_int)
        {
            if (NODE_TYPE(STE_DECL(ste)) == NT_GLOBDECL)
            {
                fprintf(data->output_file, "    istoree %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_GLOBDEF)
            {
                fprintf(data->output_file, "    istoreg %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_VARDECL)
            {
                fprintf(data->output_file, "    istore %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_PARAM)
            {
                fprintf(data->output_file, "    istore %d\n", STE_ASSEMBLY_INDEX(ste));
            }
        }

        // float - fstore [index from symbol table]
        if (STE_TYPE(ste) == CT_float)
        {
            if (NODE_TYPE(STE_DECL(ste)) == NT_GLOBDECL)
            {
                fprintf(data->output_file, "    fstoree %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_GLOBDEF)
            {
                fprintf(data->output_file, "    fstoreg %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_VARDECL)
            {
                fprintf(data->output_file, "    fstore %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_PARAM)
            {
                fprintf(data->output_file, "    fstore %d\n", STE_ASSEMBLY_INDEX(ste));
            }
        }

        // bool - bstore [index from symbol table]
        if (STE_TYPE(ste) == CT_bool)
        {
            if (NODE_TYPE(STE_DECL(ste)) == NT_GLOBDECL)
            {
                fprintf(data->output_file, "    bstoree %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_GLOBDEF)
            {
                fprintf(data->output_file, "    bstoreg %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_VARDECL)
            {
                fprintf(data->output_file, "    bstore %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_PARAM)
            {
                fprintf(data->output_file, "    bstore %d\n", STE_ASSEMBLY_INDEX(ste));
            }
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

    node_st *ste = VAR_ENTRY(node);

    // depending on STE type:
    if (ste != NULL)
    {
        // int - iload [index from symbol table]
        if (STE_TYPE(ste) == CT_int)
        {
            if (NODE_TYPE(STE_DECL(ste)) == NT_GLOBDECL)
            {
                fprintf(data->output_file, "    iloade %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_GLOBDEF)
            {
                fprintf(data->output_file, "    iloadg %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_VARDECL)
            {
                fprintf(data->output_file, "    iload %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_PARAM)
            {
                fprintf(data->output_file, "    iload %d\n", STE_ASSEMBLY_INDEX(ste));
            }
        }

        // float - fload [index from symbol table]
        if (STE_TYPE(ste) == CT_float)
        {
            if (NODE_TYPE(STE_DECL(ste)) == NT_GLOBDECL)
            {
                fprintf(data->output_file, "    floade %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_GLOBDEF)
            {
                fprintf(data->output_file, "    floadg %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_VARDECL)
            {
                fprintf(data->output_file, "    fload %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_PARAM)
            {
                fprintf(data->output_file, "    fload %d\n", STE_ASSEMBLY_INDEX(ste));
            }
        }

        // bool - bload [index from symbol table]
        if (STE_TYPE(ste) == CT_bool)
        {
            if (NODE_TYPE(STE_DECL(ste)) == NT_GLOBDECL)
            {
                fprintf(data->output_file, "    bloade %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_GLOBDEF)
            {
                fprintf(data->output_file, "    bloadg %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_VARDECL)
            {
                fprintf(data->output_file, "    bload %d\n", STE_ASSEMBLY_INDEX(ste));
            }

            if (NODE_TYPE(STE_DECL(ste)) == NT_PARAM)
            {
                fprintf(data->output_file, "    bload %d\n", STE_ASSEMBLY_INDEX(ste));
            }
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

    // Add to constant table
    instruction_string = STRcat(instruction_string, ".const int ");
    instruction_string = STRcat(instruction_string, STRitoa(NUM_VAL(node)));
    instruction_string = STRcat(instruction_string, "\n");

    fprintf(data->output_file, "    iloadc %d\n", constant_index);

    constant_index++;

    return node;
}

/**
 * @fn CGfloat
 */
node_st *CGfloat(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    // Add to constant table
    instruction_string = STRcat(instruction_string, ".const float ");
    instruction_string = STRcat(instruction_string, STRitoa(FLOAT_VAL(node)));
    instruction_string = STRcat(instruction_string, "\n");

    fprintf(data->output_file, "    floadc %d\n", constant_index);

    constant_index++;

    return node;
}

/**
 * @fn CGbool
 */
node_st *CGbool(node_st *node)
{
    struct data_cg *data = DATA_CG_GET();

    // get index from constant table (if none we add it)
    if (BOOL_VAL(node))
    {
        fprintf(data->output_file, "    bloadc_t\n");
    }
    else
    {
        fprintf(data->output_file, "    bloadc_f\n");
    }

    return node;
}

// instruction_string = STRcat(instruction_string, ".exportfun ");
// instruction_string = STRcat(instruction_string, "\"");
// instruction_string = STRcat(instruction_string, FUNDEF_NAME(fundef));
// instruction_string = STRcat(instruction_string, "\" ");
// instruction_string = STRcat(instruction_string, type);
// instruction_string = STRcat(instruction_string, params);
// instruction_string = STRcat(instruction_string, " ");
// instruction_string = STRcat(instruction_string, FUNDEF_NAME(fundef));
// instruction_string = STRcat(instruction_string, "\n");

// instruction_string = STRcat(instruction_string, ".const float ");
// instruction_string = STRcat(instruction_string, STRitoa(FLOAT_VAL(node)));
// instruction_string = STRcat(instruction_string, "\n");

// instruction_string = STRcat(instruction_string, ".const int ");
// instruction_string = STRcat(instruction_string, STRitoa(NUM_VAL(node)));
// instruction_string = STRcat(instruction_string, "\n");

//  fprintf(data->output_file, "    isrg\n");

//     TRAVargs(node);

//     int count = 0;

//     if (FUNCALL_ARGS(node) != NULL)
//     {
//         node_st *temp = FUNCALL_ARGS(node);

//         while (temp != NULL)
//         {
//             count++;
//             temp = EXPRS_NEXT(temp);
//         }
//     }

//     // If fun does not have a body - and types
//     if (FUNDEF_BODY(STE_DECL(entry)) == NULL)
//     {
//         if (STE_ASSEMBLY_INDEX(entry) == NULL)
//         {
//             STE_ASSEMBLY_INDEX(entry) = constant_index;

//             CGappend(STE_DECL(entry));

//             constant_index++;
//         }

//         fprintf(data->output_file, "    jsre %d\n", STE_ASSEMBLY_INDEX(entry));
//     }
//     else
//     {
//         fprintf(data->output_file, "    jsr %d %s\n", count, FUNDEF_NAME(STE_DECL(entry)));
//     }

// /**
//  * @fn CGglobdef
//  */
// node_st *CGglobdef(node_st *node)
// {

//     struct data_cg *data = DATA_CG_GET();

//     switch (GLOBDEF_TYPE(node))
//     {
//     case CT_int:
//         instruction_string = STRcat(instruction_string, ".global int\n");
//         break;
//     case CT_bool:
//         instruction_string = STRcat(instruction_string, ".global bool\n");
//         break;
//     case CT_float:
//         instruction_string = STRcat(instruction_string, ".global float\n");
//         break;
//     case CT_NULL:
//         break;
//     case CT_void:
//         break;
//     }
//     // Return the current node
//     return node;
// }

// /**
//  * @fn CGglobdecl
//  */
// node_st *CGglobdecl(node_st *node)
// {

//     struct data_cg *data = DATA_CG_GET();

//     switch (GLOBDECL_TYPE(node))
//     {
//     case CT_int:
//         instruction_string = STRcat(instruction_string, ".global int\n");
//         break;
//     case CT_bool:
//         instruction_string = STRcat(instruction_string, ".global bool\n");
//         break;
//     case CT_float:
//         instruction_string = STRcat(instruction_string, ".global float\n");
//         break;
//     case CT_NULL:
//         break;
//     case CT_void:
//         break;
//     }

//     // Return the current node
//     return node;
// }

// void CGappend(node_st *fundef)
// {
//     char *type = NULL;

//     switch (FUNDEF_TYPE(fundef))
//     {
//     case CT_bool:
//         type = "bool";
//         break;
//     case CT_float:
//         type = "float";
//         break;
//     case CT_int:
//         type = "int";
//         break;
//     case CT_void:
//         type = "void";
//         break;
//     case CT_NULL:
//         DBUG_ASSERT(false, "unknown type detected!");
//     }

//     char *params = "";

//     if (FUNDEF_PARAMS(fundef) != NULL)
//     {
//         node_st *temp = FUNDEF_PARAMS(fundef);

//         while (temp != NULL)
//         {
//             switch (PARAM_TYPE(temp))
//             {
//             case CT_bool:
//                 params = STRcat(params, " bool");
//                 break;
//             case CT_float:
//                 params = STRcat(params, " float");
//                 break;
//             case CT_int:
//                 params = STRcat(params, " int");
//                 break;
//             case CT_void:
//                 params = STRcat(params, " void");
//                 break;
//             case CT_NULL:
//                 DBUG_ASSERT(false, "unknown type detected!");
//             }

//             temp = PARAM_NEXT(temp);
//         }
//     }

//     // If fun does not have a body - and types
//     if (FUNDEF_BODY(fundef) == NULL)
//     {
//         instruction_string = STRcat(instruction_string, ".importfun ");
//         instruction_string = STRcat(instruction_string, "\"");
//         instruction_string = STRcat(instruction_string, FUNDEF_NAME(fundef));
//         instruction_string = STRcat(instruction_string, "\" ");
//         instruction_string = STRcat(instruction_string, type);
//         instruction_string = STRcat(instruction_string, params);
//         instruction_string = STRcat(instruction_string, "\n");
//     }
//     // If fun has export - and types
//     if (FUNDEF_EXPORT(fundef) || STReq(FUNDEF_NAME(fundef), "__init"))
//     {
//         instruction_string = STRcat(instruction_string, ".exportfun ");
//         instruction_string = STRcat(instruction_string, "\"");
//         instruction_string = STRcat(instruction_string, FUNDEF_NAME(fundef));
//         instruction_string = STRcat(instruction_string, "\" ");
//         instruction_string = STRcat(instruction_string, type);
//         instruction_string = STRcat(instruction_string, params);
//         instruction_string = STRcat(instruction_string, " ");
//         instruction_string = STRcat(instruction_string, FUNDEF_NAME(fundef));
//         instruction_string = STRcat(instruction_string, "\n");
//     }
// }

// int add_to_glob(node_st *globdef)
// {
//     switch (GLOBDEF_TYPE(globdef))
//     {
//     case CT_int:
//         instruction_string = STRcat(instruction_string, ".global int\n");
//         break;
//     case CT_bool:
//         instruction_string = STRcat(instruction_string, ".global bool\n");
//         break;
//     case CT_float:
//         instruction_string = STRcat(instruction_string, ".global float\n");
//         break;
//     case CT_NULL:
//         break;
//     case CT_void:
//         break;
//     }
// }

// int add_to_importvar(node_st *globdecl)
// {
// }

// int add_to_exportvar(node_st *globdef)
// {
// }

// int add_to_importfun(node_st *fundef)
// {
// }

// int add_to_exportfun(node_st *fundef)
// {
// }