#include "genco.h"

void asm_generator(char *filename, TAC *code)
{
    FILE *fout;
    TAC *tac = code;

    if (!(fout = fopen(filename, "w")))
    {
        fprintf(stderr, "Cant open output file.. ");
        exit(2);
    }
    //TODO fixed fprint of data segment

    //TODO fprints every variable in hashtable



    //TODO fixed fprint of segment

    //fprints every tac with corresponding assembly
    for (tac = code; tac; tac = tac->next)
    {
        switch (tac->type)
        {
        case TAC_ADD:
            fprintf(fout, " ");
            break;
        }
    }

    fclose(fout);
}