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
  fprintf(fout, "\nformatIntString:	.string \"%%d\\n\" \n");
  fprintf(fout, "\ninsertInt:	.string \"%%d\" \n");
  //TODO fprints every variable in hashtable
  HASH_NODE **hash_table = get_hash_table();
  HASH_NODE *node;
  int i = 0;
  for (i = 0; i < HASH_SIZE; ++i)
  {
    for (node = hash_table[i]; node; node = node->next)
    {
      //EVERY literal is a variable of the literal starting with _
      if (node->type == LIT_INTEGER || node->type == LIT_REAL)
      {
        fprintf(fout, "\n_%s: .long	%s \n", node->text, node->text); //TODO suport string with spaces or special character like ...
      }

      if (node->type == SYMBOL_VAR)
      {
        fprintf(fout, "\n_%s: .long	0 \n", node->text); //TODO Ta sempre declarando zerado!!
      }

      if (node->type == LIT_STRING)
      {
        //String " " from string to name the variable
        fprintf(fout, "\n_%s:	.string	\"%s \\n\" \n", trimEdges(node->text), trimEdges(node->text));
      }

      if (node->type == SYMBOL_FUN)
      {
        fprintf(fout, "\n##  SYMBOL_FUN \n"
                      ".globl	%s \n"
                      ".type	%s, @function\n",
                node->text, node->text); //TODO ver se esse type nao tem que ser só realmente no main
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
                    "movl	_%s(%%rip), %%eax\n"
                    "movl	_%s(%%rip), %%edx\n"
                    "addl	%%edx, %%eax\n"
                    "movl	%%eax, _%s(%%rip)\n",
              tac->op1->text, tac->op2->text, tac->res->text);
      break;
    case TAC_DIV:
      fprintf(fout, "\n##TAC DIV\n"
                    "movl	_%s(%%rip), %%eax\n"
                    "movl	_%s(%%rip), %%edx\n"
                    "divl	%%edx, %%eax\n"
                    "movl	%%eax, _%s(%%rip)\n",
              tac->op1->text, tac->op2->text, tac->res->text);
      break;
    case TAC_MUL:
      fprintf(fout, "\n##TAC MUL\n"
                    "movl	_%s(%%rip), %%eax\n"
                    "movl	_%s(%%rip), %%edx\n"
                    "imull	%%edx, %%eax\n"
                    "movl	%%eax, _%s(%%rip)\n",
              tac->op1->text, tac->op2->text, tac->res->text);
      break;
    case TAC_SUB:
      fprintf(fout, "\n##TAC SUB\n"
                    "movl	_%s(%%rip), %%eax\n"
                    "movl	_%s(%%rip), %%edx\n"
                    "subl	%%edx, %%eax\n"
                    "movl	%%eax, _%s(%%rip)\n",
              tac->op1->text, tac->op2->text, tac->res->text);
      break;
    case TAC_BEGINFUN: //Functions DONT start with _
      fprintf(fout,
              "\n##TAC BEGINFUN \n"
              "%s: \n"
              ".cfi_startproc  \n"
              "pushq	%%rbp \n"
              ".cfi_def_cfa_offset 16 \n"
              ".cfi_offset 6, -16 \n"
              "movq	%%rsp, %%rbp \n"
              ".cfi_def_cfa_register 6 \n",
              tac->res->text);

      int numberOfArgs = tac->res->tree ? tac->res->tree->functionArgs : 0;
      if (numberOfArgs >= 1)
        fprintf(fout, "movl	%%edx, _%s(%%rip) \n", tac->next->res->text);
      if (numberOfArgs >= 2)
        fprintf(fout, "movl	%%esi, _%s(%%rip) \n", tac->next->next->res->text);
      if (numberOfArgs >= 3)
        fprintf(fout, "movl	%%edi, _%s(%%rip) \n", tac->next->next->next->res->text);

      break;
    case TAC_ENDFUN:
      fprintf(fout,
              "\n##TAC ENDFUN \n"
              "popq	%%rbp \n"
              ".cfi_def_cfa 7, 8 \n"
              "ret \n"
              ".cfi_endproc \n");
      break;
    case TAC_OUTPUT:
      if (tac->res->type == LIT_STRING)
      {
        fprintf(fout, "\n##TAC PRINT STRING\n"
                      "	movl	$_%s, %%edi\n"
                      " movl	$0, %%eax\n"
                      " call	printf\n",
                trimEdges(tac->res->text));
      }
      else if (tac->res->type == SYMBOL_VAR) //TODO Ver se é int por exemplo
      {
        fprintf(fout, "\n##TAC PRINT VARIABLE\n"
                      "movl	_%s(%%rip), %%eax\n"
                      "movl	%%eax, %%esi\n"
                      "movl	$formatIntString, %%edi\n"
                      "movl	$0, %%eax\n"
                      "call	printf\n",
                tac->res->text);
      }
      break;
    case TAC_ASS:
      fprintf(fout, "\n ##TAC ASSIGN \n"
                    "movl	_%s(%%rip), %%eax\n"
                    "movl	%%eax, _%s(%%rip)\n",
              tac->op1->text, tac->res->text);
      break;
    case TAC_GREATER:
      fprintf(fout, "\n ##TAC GREATER \n"
                    "movl	_%s(%%rip), %%edx \n"
                    "movl	_%s(%%rip), %%eax \n"
                    "cmpl	%%eax, %%edx\n",
              tac->op1->text, tac->op2->text);
      if (tac->next->type == TAC_JZ)
      {
        fprintf(fout, "\n ##TAC JZ \n"
                      "jle	_%s \n",
                tac->next->res->text);
      }
      break;

    case TAC_LESS:
      fprintf(fout, "\n ##TAC TAC_LESS \n"
                    "movl	_%s(%%rip), %%edx \n"
                    "movl	_%s(%%rip), %%eax \n"
                    "cmpl	%%eax, %%edx\n",
              tac->op1->text, tac->op2->text);
      if (tac->next->type == TAC_JZ)
      {
        fprintf(fout, "\n ##TAC JZ \n"
                      "jge	_%s \n",
                tac->next->res->text);
      }
      break;
    case TAC_GE:
      fprintf(fout, "\n ##TAC TAC_GE \n"
                    "movl	_%s(%%rip), %%edx \n"
                    "movl	_%s(%%rip), %%eax \n"
                    "cmpl	%%eax, %%edx\n",
              tac->op1->text, tac->op2->text);
      if (tac->next->type == TAC_JZ)
      {
        fprintf(fout, "\n ##TAC JZ \n"
                      "jl	_%s \n",
                tac->next->res->text);
      }
      break;

    case TAC_LE:
      fprintf(fout, "\n ##TAC TAC_LE \n"
                    "movl	_%s(%%rip), %%edx \n"
                    "movl	_%s(%%rip), %%eax \n"
                    "cmpl	%%eax, %%edx\n",
              tac->op1->text, tac->op2->text);
      if (tac->next->type == TAC_JZ)
      {
        fprintf(fout, "\n ##TAC JZ \n"
                      "jg	_%s \n",
                tac->next->res->text);
      }
      break;
    case TAC_EQ:
      fprintf(fout, "\n ##TAC TAC_LE \n"
                    "movl	_%s(%%rip), %%edx \n"
                    "movl	_%s(%%rip), %%eax \n"
                    "cmpl	%%eax, %%edx\n",
              tac->op1->text, tac->op2->text);
      if (tac->next->type == TAC_JZ)
      {
        fprintf(fout, "\n ##TAC JZ \n"
                      "jne	_%s \n",
                tac->next->res->text);
      }
      break;

    case TAC_LABEL:
      fprintf(fout, "\n ##TAC LABEL \n"
                    "_%s:\n",
              tac->res->text);
      break;
    case TAC_JMP:
      fprintf(fout, "\n ##TAC JMP \n"
                    "jmp _%s\n",
              tac->res->text);
      break;
    case TAC_INPUT:
      fprintf(fout, "\n ##TAC INPUT \n"
                    "movl	$_%s, %%esi\n"
                    "movl	$insertInt, %%edi\n"
                    "movl	$0, %%eax\n"
                    "call	__isoc99_scanf\n",
              tac->res->text);
      break;
    case TAC_ARG:
      if(tac->prev && tac->prev->type == TAC_SYMBOL && tac->prev->prev && tac->prev->prev->type == TAC_ARG) break;
      fprintf(fout, "\n ##TAC ARG \n"
                    "movl	_%s(%%rip), %%edx\n",
              tac->res->text);
      if (tac->next && tac->next->next && tac->next->next->type == TAC_ARG)
      {
        fprintf(fout, "\n ##TAC ARG \n"
                      "movl	_%s(%%rip), %%ecx\n"
                      "movl	%%ecx, %%esi\n",
                tac->next->next->res->text);
      }
      if (tac->next && tac->next->next && tac->next->next->next &&  tac->next->next->next->next && tac->next->next->next->next->type == TAC_ARG)
      {
        fprintf(fout, "\n ##TAC ARG \n"
                      "movl	_%s(%%rip), %%eax\n"
                      "movl	%%eax, %%edi\n",
                tac->next->next->next->next->res->text);
      }
      break;
    case TAC_FUNCALL:
      fprintf(fout, "\n ##TAC_FUNCALL \n"
                    "call %s\n"
                    "movl	%%eax, _%s(%%rip)\n",
              tac->op1->text, tac->res->text);
      break;
    case TAC_RETURN:
    fprintf(fout, "\n ##TAC_RETURN \n"
                    "movl _%s(%%rip), 	%%eax\n",
              tac->res->text);
      break;
    }
  }
  fclose(fout);
}
