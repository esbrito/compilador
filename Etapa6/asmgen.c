#include "genco.h"
#include "hash.h"
#include "y.tab.h"
#include <string.h>

char trimmedString[200];

char *trimEdges(char *text)
{
  strcpy(trimmedString, text);
  size_t len = strlen(trimmedString);
  memmove(trimmedString, trimmedString + 1, len - 2);
  trimmedString[len - 2] = 0;
  return trimmedString;
}

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
  fprintf(fout, "\n## DATA\n .data\n");

  //Fixed string formats
  fprintf(fout, "\nformatIntString:	.string \"%%d\" \n");
  //TODO fprints every variable in hashtable
  HASH_NODE **hash_table = get_hash_table();
  HASH_NODE *node;
  int i = 0;
  for (i = 0; i < HASH_SIZE; ++i)
  {
    for (node = hash_table[i]; node; node = node->next)
    {
      if (node->type == LIT_INTEGER || node->type == LIT_REAL)
      {
        fprintf(fout, "\n_%s: .long	%s \n", node->text, node->text);
      }

      //Nao sei se eh necessario o trecho ainda
      if (node->type == SYMBOL_VAR)
      {
        fprintf(fout, "\n%s: .long	0 \n", node->text); //TODO Ta sempre declarando zerado!!
      }


      if (node->type == LIT_STRING)
      {
        //String " " from string to name the variable
        fprintf(fout, "\n%s:	.string	%s \n", trimEdges(node->text), node->text);
      }

      if (node->type == SYMBOL_FUN)
      {
        fprintf(fout, "\n##  SYMBOL_FUN \n"
                      ".globl	%s \n"
                      ".type	main, @function\n",
                node->text);
      }

        fprintf(stderr, "%s - %d\n", node->text, node->type);
    }
  }

  //TODO fixed fprint of segment

  //fprints every tac with corresponding assembly
  for (tac = code; tac; tac = tac->next)
  {
    switch (tac->type)
    {
    case TAC_ADD:
      fprintf(fout, "\n##TAC ADD\n"
                    "movl	%s(%%rip), %%eax\n"
                    "movl	%s(%%rip), %%edx\n"
                    "addl	%%edx, %%eax\n"
                    "movl	%%eax, %s(%%rip)\n", tac->op1->text, tac->op2->text, tac->res->text);
      break;
    case TAC_BEGINFUN:
      fprintf(fout,
              "\n##TAC BEGINFUN \n"
              "%s: \n"
              ".cfi_startproc  \n"
              "pushq	%%rbp \n"
              ".cfi_def_cfa_offset 16 \n"
              ".cfi_offset 6, -16 \n"
              "movq	%%rsp, %%rbp \n"
              ".cfi_def_cfa_register 6 \n", tac->res->text);
      break;
    case TAC_ENDFUN:
      fprintf(fout,
              "\n##TAC ENDFUN \n"
              "	movl	$0, %%eax \n"
              "popq	%%rbp \n"
              ".cfi_def_cfa 7, 8 \n"
              "ret \n"
              ".cfi_endproc \n");
      break;
    case TAC_OUTPUT:
      if (tac->res->type == LIT_STRING)
      {
        fprintf(fout, "\n##TAC PRINT STRING\n"
                      "	movl	$%s, %%edi\n"
                      " movl	$0, %%eax\n"
                      " call	printf\n",
                trimEdges(tac->res->text));
      }
      else if (tac->res->type == SYMBOL_VAR) //TODO Ver se é int por exemplo
      {
        fprintf(fout, "\n##TAC PRINT VARIABLE\n"
                      "movl	%s(%%rip), %%eax\n"
                      "movl	%%eax, %%esi\n"
                      "movl	$formatIntString, %%edi\n"
                      "movl	$0, %%eax\n"
                      "call	printf\n",
                tac->res->text);
      }
      break;
    }
  }

  fclose(fout);
}
