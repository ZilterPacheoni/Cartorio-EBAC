#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de text por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	char arquivo[40];   //vari�vel/string
	char cpf[40];       //vari�vel/string
	char nome[40];      //vari�vel/string
	char sobrenome[40]; //vari�vel/string
	char cargo[40];     //vari�vel/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cpf); // %s se refere a armazenar as strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string. arquivo vai ser igual o cpf.
	
	FILE *file; //Criar o arquivo
	file = fopen(arquivo, "w"); //W cria o arquivo
	fprintf(file,cpf); //Salvo o valor da vari�vel (CPF)
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // vai abrir o arquivo que j� est� salvo na vari�vel
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
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //while � "enquanto". fgets se usa para buscar o arquivo
	{
		printf("\nEssas s�o as informa��es dos usu�rios: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digita o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // R , ler o arquivo
	
	
	if(file == NULL) //Se n�o houver usu�rio (usar isso)
	{
		printf("O usu�rio n�o existe!\n\n");
		
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
	 
	    printf("$$  C�rtorio do Zilter  $$\n\n");
	    printf("Escolha a op��o desejada do menu\n\n");
	    printf("\t1 - Cadastrar dados\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Opcao: ");
	 
	    scanf("%d", &opcao);
	 
	    system("cls"); // Respons�vel por limpar a tela
	 
	    switch(opcao)
	    {
	      case 1:
	      registro(); //Chama as fun��es
          break;
		
          case 2:
	      consulta(); //Chama as fun��es
	      break;
	 	
	      case 3: 
	      deletar(); //Chama as fun��es
	      break;
	      
	      default: 
	      printf("N�o tem essa op��o!\n");
	      system("pause");
	      break;
	    
		}
    
	}
	 
}
