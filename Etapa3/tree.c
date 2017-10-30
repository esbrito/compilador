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
      fprintf(stderr, ">");
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
    case TREE_DECLARATION_VECTOR_NUMBER:
      fprintf(stderr, "DECLARATION_VECTOR_NUMBER");
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
    case TREE_VECTOR:
      fprintf(stderr, "VECTOR");
      break;
    case TREE_VECTOR_VALUES:
      fprintf(stderr, "VECTOR_VALUES");
      break;
    case TREE_VECTOR_VALUES_POSITION:
      fprintf(stderr, "VECTOR_VALUES_POSITION");
      break;
    case TREE_DECLARATION_SYMBOL_VECTOR:
      fprintf(stderr, "DECLARATION_SYMBOL_VECTOR");
      break;
    case TREE_CMD_BLOCK:
      fprintf(stderr, "CMD_BLOCK");
      break;
    case TREE_DECLARATION_SYMBOL:
      fprintf(stderr, "DECLARATION_SYMBOL");
      break;
    case TREE_PRINTABLE:
      fprintf(stderr, "TREE_PRINTABLE");
      break;
    case PROGRAM:
      fprintf(stderr, "PROGRAM");
      break;
    case DECLARATIONS:
      fprintf(stderr, "DECLARATION");
      break;
      case TREE_PAR:
      fprintf(stderr, "PARENTHESES");
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

char *getType(char *type)
{
}
void decompile(FILE *file, TREE *node)
{
  char *buffer;
  int i = 0;
  if (node)
  {
    switch (node->type)
    {
    case TREE_ADD:
      decompile(file, node->son[0]);
      fprintf(file, "+");
      decompile(file, node->son[1]);
      break;
    case TREE_SUB:
      decompile(file, node->son[0]);
      fprintf(file, "-");
      decompile(file, node->son[1]);
      break;
    case TREE_MUL:
      decompile(file, node->son[0]);
      fprintf(file, "*");
      decompile(file, node->son[1]);
      break;
    case TREE_DIV:
      decompile(file, node->son[0]);
      fprintf(file, "/");
      decompile(file, node->son[1]);
      break;
    case TREE_LESS:
      decompile(file, node->son[0]);
      fprintf(file, "<");
      decompile(file, node->son[1]);
      break;
    case TREE_GREATER:
      decompile(file, node->son[0]);
      fprintf(file, ">");
      decompile(file, node->son[1]);
      break;
    case TREE_NOT:
      decompile(file, node->son[0]);
      fprintf(file, "!");
      decompile(file, node->son[1]);
      break;
    case TREE_LE:
      decompile(file, node->son[0]);
      fprintf(file, "<=");
      decompile(file, node->son[1]);
      break;
    case TREE_GE:
      decompile(file, node->son[0]);
      fprintf(file, ">=");
      decompile(file, node->son[1]);
      break;
    case TREE_EQ:
      decompile(file, node->son[0]);
      fprintf(file, "==");
      decompile(file, node->son[1]);
      break;
    case TREE_NE:
      decompile(file, node->son[0]);
      fprintf(file, "!=");
      decompile(file, node->son[1]);
      break;
    case TREE_AND:
      decompile(file, node->son[0]);
      fprintf(file, "&&");
      decompile(file, node->son[1]);
      break;
    case TREE_OR:
      decompile(file, node->son[0]);
      fprintf(file, "||");
      decompile(file, node->son[1]);
      break;
    case TREE_ASSIGN:
      fprintf(file, "%s=", node->symbol->text);
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      break;
    case TREE_IF:
      fprintf(file, "if (");
      decompile(file, node->son[0]);
      fprintf(file, ") then {\n");
      decompile(file, node->son[1]);
      fprintf(file, "\n}");
      decompile(file, node->son[2]);
      break;
    case TREE_WHILE:
      fprintf(file, "while (");
      decompile(file, node->son[0]);
      fprintf(file, ") {\n");
      decompile(file, node->son[1]);
      fprintf(file, "\n}");
      break;
    case TREE_PRINT:
      fprintf(file, "print ");
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      break;
    case TREE_READ:
      fprintf(file, "read > %s", node->symbol->text);
      break;
    case TREE_RETURN:
      fprintf(file, "return ");
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      break;
    case TREE_ELSE:
      fprintf(file, "else {\n");
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      fprintf(file, "\n}");
      break;
    case TREE_DECLARATION_SYMBOL:
      fprintf(file, "=%s", node->symbol->text);
      break;
    case TREE_DECLARATION_SYMBOL_VECTOR:
      fprintf(file, "%s", node->symbol->text);
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      break;
    case TREE_DECLARATION_SCALAR:
      fprintf(file, "%s: ", node->symbol->text);
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      fprintf(file, ";");
      break;
    case TREE_DECLARATION_VECTOR:
      fprintf(file, "%s: ", node->symbol->text);
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      fprintf(file, ";");
      break;
    case TREE_DECLARATION_VECTOR_NUMBER:
      fprintf(file, "[%s]", node->symbol->text);
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      break;
    case TREE_VECTOR_VALUES:
      fprintf(file, " ");
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      break;
    case TREE_VECTOR_VALUES_POSITION:
      fprintf(file, "[");
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      fprintf(file, "]");
      break;
    case TREE_VECTOR:
      fprintf(file, "%s[", node->symbol->text);
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      fprintf(file, "]");
      break;
    case TREE_FUNCTION:
      switch (node->son[0]->type)
      {
      case TREE_KW_BYTE:
        fprintf(file, "(byte)");
        break;
      case TREE_KW_SHORT:
        fprintf(file, "(short)");
        break;
      case TREE_KW_LONG:
        fprintf(file, "(long)");
        break;
      case TREE_KW_FLOAT:
        fprintf(file, "(float)");
        break;
      case TREE_KW_DOUBLE:
        fprintf(file, "(double)");
        break;
      }
      fprintf(file, " %s (", node->symbol->text);

      if (node->son[1] == 0)
      {
        fprintf(file, ")");
      }
      decompile(file, node->son[1]);
      fprintf(file, "{\n");
      decompile(file, node->son[2]);
      fprintf(file, "\n}");
      break;
    case TREE_KW_BYTE:
      fprintf(file, "byte");
      break;
    case TREE_KW_SHORT:
      fprintf(file, "short");
      break;
    case TREE_KW_LONG:
      fprintf(file, "long");
      break;
    case TREE_KW_FLOAT:
      fprintf(file, "float");
      break;
    case TREE_KW_DOUBLE:
      fprintf(file, "double");
      break;
    case TREE_PARAMS:
      decompile(file, node->son[0]);
      if (node->son[1] != 0)
      {
        fprintf(file, ",");
      }
      decompile(file, node->son[1]);
      if (node->son[1] == 0)
      {
        fprintf(file, ")");
      }
      break;
    case TREE_CMD_LIST:
      fprintf(file, ";\n");
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      break;
    case TREE_ASSIGN_VECTOR:
      fprintf(file, "%s", node->symbol->text);
      decompile(file, node->son[0]);
      fprintf(file, "=");
      decompile(file, node->son[1]);
      break;
    case TREE_PRINTABLE:
      decompile(file, node->son[0]);
      if (node->son[1] != 0)
      {
        fprintf(file, ",");
      }
      decompile(file, node->son[1]);
      break;
    case TREE_FUNCTION_CALL:
      fprintf(file, "%s(", node->symbol->text);
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      break;
    case TREE_PARAM:
      fprintf(file, "%s:", node->symbol->text);
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      break;
    case TREE_CMD_BLOCK:
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      break;
    case PROGRAM:
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
      }
      break;
    case DECLARATIONS:
      for (i = 0; i < MAX_SONS; ++i)
      {
        decompile(file, node->son[i]);
        fprintf(file, "\n");
      }
      break;
    case TREE_SYMBOL:
      fprintf(file, "%s", node->symbol->text);
      break;
    case TREE_PAR:
	  fprintf(file, "(");
	  decompile(file, node->son[0]);
	  fprintf(file,")");
	  break;
	default:
      fprintf(file, "UNKOWN");
      break;
    }
  }
}
