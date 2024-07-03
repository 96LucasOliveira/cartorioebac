#include <stdio.h> //Biblioteca de comunicação com o usuario 
#include <stdlib.h> //biblioteca de alocação de esaço em memoria 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das string 

int registro() //função responsável por cadastrar usuários no sistema
{
	//inicio criação de variaveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final criação de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string (usamos toda vez que salvamos uma variavel/string)
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
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
	file = fopen(cpf,"r"); // "r" ler o que esta no banco de dados e verificar se há um arquivo dado pelo cpf escrito pelo usuário.
	
	if(file == NULL)
	{
		printf("Não foi possivel lozalizar o arquivo!. \n");
	}
	
	printf("\nEssas são as informações do usuario: \n\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	FILE* file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("O usuário não se encontra no sistema!. \n");
		system("pause");
	}

	
}

int main ()
	{
	int opcao=0; //definindo variaveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system ("cls"); //responsável por limpar a tela 
		
		setlocale(LC_ALL, "Portuguese");
		
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu 
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção:");//fim do menu
		
		scanf("%d", & opcao); //armazenando escolha do usuario 
		
		system("cls"); //responsável por limpar a tela 
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
				registro(); //chamada de funções 
			break;	
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;
			
			default:
				printf("Essa opção não está disponivel!\n\n");
				system("pause");
			break;
				
				
		}
		
	}  
	}
