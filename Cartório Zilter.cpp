#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de text por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	char arquivo[40];   //variável/string
	char cpf[40];       //variável/string
	char nome[40];      //variável/string
	char sobrenome[40]; //variável/string
	char cargo[40];     //variável/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cpf); // %s se refere a armazenar as strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string. arquivo vai ser igual o cpf.
	
	FILE *file; //Criar o arquivo
	file = fopen(arquivo, "w"); //W cria o arquivo
	fprintf(file,cpf); //Salvo o valor da variável (CPF)
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // vai abrir o arquivo que já está salvo na variável
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file =fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // R se usa pra ler o arquivo.
	
	if(file == NULL) //NULL = nulo
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //while é "enquanto". fgets se usa para buscar o arquivo
	{
		printf("\nEssas são as informações dos usuários: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digita o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // R , ler o arquivo
	
	
	if(file == NULL) //Se não houver usuário (usar isso)
	{
		printf("O usuário não existe!\n\n");
		
	}
	 system("pause");
}


int main ()
{
	 int opcao=0;
	 int x=1;
	 
	 for(x=1;x=1;)
	 {
	 	system("cls");
	 	
		setlocale(LC_ALL, "Portuguese");
	 
	    printf("$$  Cártorio do Zilter  $$\n\n");
	    printf("Escolha a opção desejada do menu\n\n");
	    printf("\t1 - Cadastrar dados\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Opcao: ");
	 
	    scanf("%d", &opcao);
	 
	    system("cls"); // Responsável por limpar a tela
	 
	    switch(opcao)
	    {
	      case 1:
	      registro(); //Chama as funções
          break;
		
          case 2:
	      consulta(); //Chama as funções
	      break;
	 	
	      case 3: 
	      deletar(); //Chama as funções
	      break;
	      
	      default: 
	      printf("Não tem essa opção!\n");
	      system("pause");
	      break;
	    
		}
    
	}
	 
}
