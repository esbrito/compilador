int main(int argc, char** argv)
{

  if(argc < 2)
  {
    fprintf(stderr, "Erro, falta 1 argumento! Indique o nome do arquivo a ser lido");
    exit(1);
  }

  FILE* file = fopen(argv[1],"r");
	if(file == NULL)
	{
    fprintf(stderr, "Erro, ao ler arquivo!");
    exit(1);
	}
	else
	{
		yyin = file;
	}

  initMe();

  while(running)
  {
    yyparse();
    printf("Token detectado: %d ---- Linha: %d\n", token, getLineNumber());
  }
  hash_table_print();
  //Se chegou aqui é porque a sintasse está correta
  printf("Sintaxe correta!\n");
  exit(0);
}
