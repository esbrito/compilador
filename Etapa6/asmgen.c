#include "genco.h"
#include "hash.h"
#include "y.tab.h"
#include <string.h>

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
fprintf(fout, "## DATA\n .data\n");
  //TODO fprints every variable in hashtable
  HASH_NODE** hash_table = get_hash_table();
  HASH_NODE *node;
  int i = 0;
  for (i = 0; i < HASH_SIZE; ++i)
  {
    for (node = hash_table[i]; node; node = node->next)
    {
      if(node->type == LIT_INTEGER || node->type == LIT_REAL){
        fprintf(fout, "_%s: .long	%s \n", node->text, node->text);
      }

      //Nao sei se eh necessario o trecho ainda
      if(node->type == SYMBOL_VAR && node->tree &&
          node->tree->type == TREE_DECLARATION_SCALAR &&
          node->tree->son[1]->type == TREE_DECLARATION_SYMBOL){
        fprintf(fout, "_%s: .long	%s \n", node->text, node->tree->son[1]->symbol->text);
      }
      //TODO for string
      if(node->type == LIT_STRING){
        //String " " from string to name the variable
        char str[200];
        strcpy(str, node->text);
        size_t len = strlen(str);
        memmove(str, str+1, len-2);
        str[len-2] = 0;
        fprintf(fout, "_%s:	.string	%s \n", str, node->text);
      }

      if(node->type == SYMBOL_FUN){
        fprintf(fout, "##  SYMBOL_FUN \n"
        	".globl	%s \n"
        	".type	main, @function\n", node->text);
      }




    //  fprintf(stderr, "%s - %d\n", node->text, node->type);
    }
  }



  //TODO fixed fprint of segment

  //fprints every tac with corresponding assembly
  for (tac = code; tac; tac = tac->next)
  {
    switch (tac->type)
    {
      case TAC_ADD:
        fprintf(fout, " ");
        break;
      case TAC_BEGINFUN:
        fprintf(fout,
          "##TAC BEGINFUN \n"
          "main: \n"
        		".cfi_startproc  \n"
        	"pushq	%%rbp \n"
        	".cfi_def_cfa_offset 16 \n"
        	".cfi_offset 6, -16 \n"
        	"movq	%%rsp, %%rbp \n"
        	".cfi_def_cfa_register 6 \n");
        break;
      case TAC_ENDFUN:
        fprintf(fout,
          "##TAC ENDFUN \n"
          "	movl	$0, %%eax \n"
        	"popq	%%rbp \n"
        	".cfi_def_cfa 7, 8 \n"
        	"ret \n"
        	".cfi_endproc \n");
        break;
      case TAC_OUTPUT:
        fprintf(fout, " ");
      break;
    }
  }

  fclose(fout);
}
