
#include "genco.h"


TAC* tac_create(int type, HASH_NODE* res, HASH_NODE* op1,  HASH_NODE* op2)
{
  TAC* new;
  new = (TAC*) calloc(1, sizeof(TAC));
  new->type = type;
  new->res = res;
  new->op1 = op1;
  new->op2 = op2;
  new->prev = 0;
  new->next = 0;
  return new;
}

TAC* tac_join(TAC* l1, TAC* l2)
{
  TAC* tac = l2;
  if(!l1) return l2;
  if(!l2) return l1;
  while(tac->prev)
  {
    tac = tac->prev;
  }
  tac->prev = l1;
  return l2;
}

void tac_print_back(TAC* last)
{
  TAC* tac;
  for (tac = last; tac; tac = tac->prev)
  {
    tac_print_single(tac);
  }
}
void tac_print_single(TAC* tac)
{
  if(!tac) return;
  if(tac->type == TAC_SYMBOL) return;
  fprintf(stderr,"TAC(");
  switch (tac->type)
  {
    case TAC_ADD: fprintf(stderr, "TAC_ADD" ); break;
    case TAC_MUL: fprintf(stderr, "TAC_MUL" ); break;
    case TAC_SUB: fprintf(stderr, "TAC_SUB" ); break;
    case TAC_DIV: fprintf(stderr, "TAC_DIV" ); break;
    case TAC_ASS: fprintf(stderr, "TAC_ASS" ); break;
    case TAC_LABEL: fprintf(stderr, "TAC_LABEL" ); break;
    case TAC_INPUT: fprintf(stderr, "TAC_INPUT" ); break;
    case TAC_VECREAD: fprintf(stderr, "TAC_VECREAD" ); break;
    case TAC_JZ: fprintf(stderr, "TAC_JZ" ); break;
    case TAC_LESS: fprintf(stderr, "TAC_LESS" ); break;
    case TAC_GREATER: fprintf(stderr, "TAC_GREATER" ); break;
    case TAC_NOT: fprintf(stderr, "TAC_NOT" ); break;
    case TAC_LE: fprintf(stderr, "TAC_LE" ); break;
    case TAC_GE: fprintf(stderr, "TAC_GE" ); break;
    case TAC_EQ: fprintf(stderr, "TAC_EQ" ); break;
    case TAC_NE: fprintf(stderr, "TAC_NE" ); break;
    case TAC_AND: fprintf(stderr, "TAC_AND" ); break;
    case TAC_OR: fprintf(stderr, "TAC_OR" ); break;
    case TAC_VECWRITE: fprintf(stderr, "TAC_VECWRITE" ); break;
    case TAC_OUTPUT: fprintf(stderr, "TAC_OUTPUT" ); break;
    case TAC_BEGINFUN: fprintf(stderr, "TAC_BEGINFUN" ); break;
    case TAC_ENDFUN: fprintf(stderr, "TAC_ENDFUN" ); break;
    case TAC_JMP: fprintf(stderr, "TAC_JMP" ); break;
    case TAC_FUNCALL: fprintf(stderr, "TAC_FUNCALL" ); break;
    case TAC_ARG: fprintf(stderr, "TAC_ARG" ); break;
    case TAC_RETURN: fprintf(stderr, "TAC_RETURN" ); break;
    
    default:  fprintf(stderr, "UNKOWN" ); break;
  }

  if(tac->res) fprintf(stderr, ",%s", tac->res->text); else fprintf(stderr, ",null");
  if(tac->op1) fprintf(stderr, ",%s", tac->op1->text); else fprintf(stderr, ",null");
  if(tac->op2) fprintf(stderr, ",%s", tac->op2->text); else fprintf(stderr, ",null");
  fprintf(stderr, ")\n");
}

TAC* tac_generator(TREE* node)
{
  int i;
  TAC* code[MAX_SONS];
  if(!node) return 0;

  //Gerando filhos
  for(i=0; i < MAX_SONS ; ++i)
  {
    code[i] = tac_generator(node->son[i]);
  }

  switch (node->type) {
    case TREE_SYMBOL: return tac_create(TAC_SYMBOL, node->symbol,0,0); break;
    case TREE_ADD: return tac_join(tac_join(code[0], code[1]), tac_create(TAC_ADD,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_MUL: return tac_join(tac_join(code[0], code[1]), tac_create(TAC_MUL,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_DIV: return tac_join(tac_join(code[0], code[1]), tac_create(TAC_DIV,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_SUB: return tac_join(tac_join(code[0], code[1]), tac_create(TAC_SUB,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_ASSIGN: return tac_join(code[0],tac_create(TAC_ASS,  node->symbol ,code[0]?code[0]->res:0,0)); break;
    case TREE_READ: return tac_join(code[0],tac_create(TAC_INPUT,  node->symbol ,code[0]?code[0]->res:0,0)); break;
    case TREE_PRINTABLE: return tac_join(tac_create(TAC_OUTPUT,  code[0]?code[0]->res:0 , 0,0),tac_join(code[0], code[1])); break;
    case TREE_VECTOR: return tac_join(code[0],tac_create(TAC_VECREAD,   make_temp() ,node->symbol,code[0]?code[0]->res:0)); break;
    case TREE_ASSIGN_VECTOR: return tac_join(tac_join(code[0], code[1]),tac_create(TAC_VECWRITE,   code[1]?code[1]->res:0, node->symbol, code[0]?code[0]->res:0)); break;
    case TREE_IF: return make_if_then_else(code[0],code[1], code[2]); break;
    case TREE_LESS : return tac_join(tac_join(code[0], code[1]), tac_create(TAC_LESS,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_GREATER : return tac_join(tac_join(code[0], code[1]), tac_create(TAC_GREATER,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_NOT : return tac_join(tac_join(code[0], code[1]), tac_create(TAC_NOT,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_LE : return tac_join(tac_join(code[0], code[1]), tac_create(TAC_LE,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_GE : return tac_join(tac_join(code[0], code[1]), tac_create(TAC_GE,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_EQ : return tac_join(tac_join(code[0], code[1]), tac_create(TAC_EQ,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_NE : return tac_join(tac_join(code[0], code[1]), tac_create(TAC_NE,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_AND : return tac_join(tac_join(code[0], code[1]), tac_create(TAC_AND,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_OR : return tac_join(tac_join(code[0], code[1]), tac_create(TAC_OR,  make_temp() ,code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
    case TREE_FUNCTION : return tac_join(tac_join((tac_create(TAC_BEGINFUN, node->symbol , 0 , 0)),tac_join(tac_join(tac_join(code[0], code[1]),code[2]),code[3])), tac_create(TAC_ENDFUN, node->symbol , 0 , 0)); break;
    case TREE_WHILE: return make_while(code[0],code[1]); break;
    case TREE_PARAMS: return tac_join(tac_join(code[0], tac_create(TAC_ARG, node->son[0]->symbol?node->son[0]->symbol:code[0]->res,0,0)), code[1]); break;
    case TREE_FUNCTION_CALL: return tac_join(tac_create(TAC_FUNCALL, make_temp(), node->symbol, 0), code[0]); break;
    case TREE_RETURN: return tac_create(TAC_RETURN, code[0]?code[0]->res:0,0, 0);
                     
  }
  return tac_join(tac_join(tac_join(code[0], code[1]),code[2]),code[3]);
}

TAC* make_if_then_else(TAC* code0, TAC* code1, TAC* code2)
{
  TAC *new_jump_zero_tac = 0;
  TAC *new_label_jz_tac = 0;
  HASH_NODE* new_label_jz = 0;
  TAC *new_jump_tac = 0;
  TAC *new_label_jmp_tac = 0;
  HASH_NODE* new_label_jmp = 0;

  new_label_jz = make_label();
  new_label_jmp = make_label();

  new_jump_zero_tac = tac_create(TAC_JZ, new_label_jz, code0?code0->res:0, 0);
  new_jump_tac = tac_create(TAC_JMP, new_label_jmp, code0?code0->res:0, 0);
  
  new_label_jz_tac = tac_create(TAC_LABEL,new_label_jz, 0, 0);
  new_label_jmp_tac = tac_create(TAC_LABEL,new_label_jmp, 0, 0);
  
  // check for else
  if (!code2) // else is null
    return tac_join(tac_join(tac_join(code0, new_jump_zero_tac), code1), new_label_jz_tac);
  else // else is valid
    return tac_join(tac_join(tac_join(tac_join(tac_join(tac_join(code0, new_jump_zero_tac), code1), new_jump_tac), new_label_jz_tac), code2), new_label_jmp_tac);
}

TAC* make_while(TAC* code0, TAC* code1)
{
  TAC *new_jump_zero_tac = 0;
  TAC *new_jump_tac = 0;
  TAC *new_label_tac = 0;
  TAC *new_label_tac2 = 0;
  HASH_NODE* new_label = 0;
  HASH_NODE* new_label2 = 0;

  //Label to return if while is true
  new_label = make_label();

  //Label to jump if while is false
  new_label2 = make_label();

  new_jump_zero_tac = tac_create(TAC_JZ, new_label2, code0?code0->res:0, 0);
  new_jump_tac = tac_create(TAC_JMP, new_label, 0, 0);

  new_label_tac = tac_create(TAC_LABEL,new_label, 0, 0);
  new_label_tac2 = tac_create(TAC_LABEL,new_label2, 0, 0);

  return tac_join(tac_join(tac_join(tac_join(tac_join(new_label_tac, code0), new_jump_zero_tac), code1), new_jump_tac),new_label_tac2);
}
