#include "tree.h"
TREE *tree_create(int type, HASH_NODE *symbol, TREE *s0, TREE *s1, TREE *s2, TREE *s3)
{
  TREE *new;
  new = (TREE *)calloc(1, sizeof(TREE));
  new->type = type;
  new->symbol = symbol;
  new->son[0] = s0;
  new->son[1] = s1;
  new->son[2] = s2;
  new->son[3] = s3;
}

void tree_print(TREE *node, int level)
{
  int i = 0;
  if (node)
  {
    for (i = 0; i < level; ++i)
    {
      fprintf(stderr, "---");
    }
    fprintf(stderr, "TREE(");

    switch (node->type)
    {
    case TREE_SYMBOL:
      fprintf(stderr, "SYMBOL");
      break;
    case TREE_ADD:
      fprintf(stderr, "SOMA");
      break;
    case TREE_SUB:
      fprintf(stderr, "SUB");
      break;
    case TREE_MUL:
      fprintf(stderr, "MULTI");
      break;
    case TREE_DIV:
      fprintf(stderr, "DIV");
      break;
    case TREE_LESS:
      fprintf(stderr, "LESS");
      break;
    case TREE_GREATER:
      fprintf(stderr, "GREATER");
      break;
    case TREE_NOT:
      fprintf(stderr, "NOT");
      break;
    case TREE_LE:
      fprintf(stderr, "LE");
      break;
    case TREE_GE:
      fprintf(stderr, "GE");
      break;
    case TREE_EQ:
      fprintf(stderr, "EQ");
      break;
    case TREE_NE:
      fprintf(stderr, "NE");
      break;
    case TREE_AND:
      fprintf(stderr, "AND");
      break;
    case TREE_OR:
      fprintf(stderr, "OR");
      break;
    case TREE_ASSIGN:
      fprintf(stderr, "ASSIGN");
      break;
    case TREE_IF:
      fprintf(stderr, "IF THEN");
      break;
    case TREE_WHILE:
      fprintf(stderr, "WHILE");
      break;
    case TREE_PRINT:
      fprintf(stderr, "PRINT");
      break;
    case TREE_READ:
      fprintf(stderr, "READ");
      break;
    case TREE_RETURN:
      fprintf(stderr, "RETURN");
      break;
    case TREE_ELSE:
      fprintf(stderr, "ELSE");
      break;
    case TREE_DECLARATION_SCALAR:
      fprintf(stderr, "DECLARATION_SCALAR");
      break;
    case TREE_DECLARATION_VECTOR:
      fprintf(stderr, "DECLARATION_VECTOR");
      break;
    case TREE_FUNCTION:
      fprintf(stderr, "FUNCTION");
      break;
    case TREE_KW_BYTE:
      fprintf(stderr, "KW_BYTE");
      break;
    case TREE_KW_SHORT:
      fprintf(stderr, "KW_SHORT");
      break;
    case TREE_KW_LONG:
      fprintf(stderr, "KW_LONG");
      break;
    case TREE_KW_FLOAT:
      fprintf(stderr, "KW_FLOAT");
      break;
    case TREE_KW_DOUBLE:
      fprintf(stderr, "KW_DOUBLE");
      break;
    case TREE_PARAMS:
      fprintf(stderr, "PARAMS");
      break;
    case TREE_CMD_LIST:
      fprintf(stderr, "CMD_LIST");
      break;
    case TREE_ASSIGN_VECTOR:
      fprintf(stderr, "ASSIGN_VECTOR");
      break;
    case TREE_FUNCTION_CALL:
      fprintf(stderr, "FUNCTION_CALL");
      break;
    case TREE_PARAM:
      fprintf(stderr, "PARAM");
      break;
    case TREE_VECTOR_VALUES:
      fprintf(stderr, "VECTOR_VALUES");
      break;
    case TREE_CMD_BLOCK:
      fprintf(stderr, "CMD_BLOCK");
      break;
    default:
      fprintf(stderr, "UNKOWN");
      break;
    }

    if (node->symbol)
    {
      fprintf(stderr, ",%s\n", node->symbol->text);
    }
    else
    {
      fprintf(stderr, "\n");
    }

    for (i = 0; i < MAX_SONS; ++i)
    {
      tree_print(node->son[i], level + 1);
    }
  }
}
