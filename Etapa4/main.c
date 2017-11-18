
extern TREE* ast_tree;

int main(int argc, char** argv)
{

  if(argc < 2)
  {
    fprintf(stderr, "Erro, faltao argumentos! Indique o nome do arquivo a ser lido");
    exit(99);
  }

  FILE* file = fopen(argv[1],"r");
	if(file == NULL)
	{
    fprintf(stderr, "Erro, ao ler arquivo!");
    exit(99);
	}
	else
	{
		yyin = file;
	}

  initMe();

  while(isRunning())
  {
    yyparse();
    printf("Token detectado: %d ---- Linha: %d\n", token, getLineNumber());
  }

    //hash_table_print();
  
  // Testa para erros semanticos
  if ( foundSemanticErr() )
  {
    fprintf(stderr, "Semantic ERROR(s) found: unable to compile\n");
    exit(4);
  }
  
  //Se chegou aqui é porque a sintasse está correta
  printf("Sintaxe correta!\n");
  exit(0);
}
