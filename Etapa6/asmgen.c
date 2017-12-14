#include "genco.h"
#include "hash.h"
#include "y.tab.h"

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

      //TODO for string

      //TODO for variables
      
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
    }
  }

  fclose(fout);
}
