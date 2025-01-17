#include <stdio.h> //Biblioteca de comunica��o com o usuario 
#include <stdlib.h> //biblioteca de aloca��o de esa�o em memoria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das string 

int registro() //fun��o respons�vel por cadastrar usu�rios no sistema
{
	//inicio cria��o de variaveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string (usamos toda vez que salvamos uma variavel/string)
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
	
	FILE *file;  // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //salva o valor da variavel 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa atualizar
	fprintf(file,"\nNOME: "); 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,"\nSOBRENOME: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,"\nCARGO: ");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");

	char cpf [40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; 
	file = fopen(cpf,"r"); // "r" ler o que esta no banco de dados e verificar se h� um arquivo dado pelo cpf escrito pelo usu�rio.
	
	if(file == NULL)
	{
		printf("N�o foi possivel lozalizar o arquivo!. \n");
	}
	
	printf("\nEssas s�o as informa��es do usuario: \n\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	FILE* file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("O usu�rio n�o se encontra no sistema!. \n");
		system("pause");
	}

	
}

int main ()
{
	int opcao=0; //definindo variaveis 
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0 )
	{
		for(laco=1;laco=1;)
		{
			system("cls");
			setlocale(LC_ALL, "Portuguese");
		
			printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu 
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar os nomes\n");
			printf("\t3 - Deletar nomes\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o:");//fim do menu
		
			scanf("%d", & opcao); //armazenando escolha do usuario 
		
			system("cls"); //respons�vel por limpar a tela 
		
			switch(opcao) //inicio da sele��o do menu
			{
				case 1:
					registro(); //chamada de fun��es 
				break;	
				
				case 2:
					consulta();
				break;
				
				case 3:
					deletar();
				break;
				
				case 4:
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
					break;
				
				default:
					printf("Essa op��o n�o est� disponivel!\n\n");
					system("pause");
				break;		
			}	
		}
	}
	else
	printf("Senha Incorreta!");
}

	
