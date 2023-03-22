
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

// 1. To create a assembly file  ./civicc ../test/arrays/check_success/scopes.cvc -o [filename]
// 2. Find file in /build-debug folder
// Don't forget to turn on functional tests in the makefile

void CGinit()
{
    // FILE *file = fopen(global.output_file, "w");

    // if (file != NULL)
    // {
    //     struct data_cg *data = DATA_CG_GET();
    //     data->output_file = file;

    //     // fprintf(data->output_file, "Sterkkk\n");
    // }
    // else
    // {
    //     // We sent error if any other expressions mistmatches on type
    //     CTI(CTI_ERROR, true, "\n Error: global file not found. \n");
    //     CCNerrorAction();
    // }

    return;
}
void CGfini()
{
    // struct data_cg *data = DATA_CG_GET();

    // if (data->output_file != NULL)
    // {
    //     fclose(data->output_file);
    // }

    return;
}

/**
 * @fn CGprogram
 */
node_st *CGprogram(node_st *node)
{

    return node;
}
