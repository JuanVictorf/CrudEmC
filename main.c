#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


typedef struct Agenda{
	char nome[50];
	char telefone[20];
	char empresa[50];
	
} Agenda;

Agenda vetAgenda[10];


int cadastrarAgenda(Agenda *vetAgenda){
	
	int i;
	for(i = 0; i < 2; i++){
		printf("Digite o nome da pessoa: \n");
		scanf("%s", &vetAgenda[i].nome);
		//setbuf(stdin, NULL);
    	//scanf("%99[^\n]", &vetAgenda[i].nome);
		printf("Digite o telefone da pessoa: \n");
		scanf("%s", &vetAgenda[i].telefone);
		//setbuf(stdin, NULL);
    	//scanf("%99[^\n]", &vetAgenda[i].telefone);
		printf("Digite a empresa da pessoa: \n");
		scanf("%s", &vetAgenda[i].empresa);
		//setbuf(stdin, NULL);
    	//scanf("%99[^\n]", &vetAgenda[i].empresa);
	}
}

int consultarAgenda(Agenda *vetAgenda){
	//Agenda vetAgenda[10];
	int i;
	int retornoString;
	
	for(i = 0; i < 2; i++){
		//printf("\nPosicao i: %s\n", vetAgenda[i].nome);
		retornoString = strcmp(vetAgenda[i].nome, "");
		//printf("%i", retornoString);
		if(retornoString != 0){
			printf("Nome da pessoa: %s\n", vetAgenda[i].nome);
			printf("Telefone da pessoa: %s\n", vetAgenda[i].telefone);
			printf("Empresa da pessoa: %s\n", vetAgenda[i].empresa);
		}
	}
	
}


int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");
	
	printf("Atividade da prova\n");
	printf("========================\n");
	
	int opcao;
	char resp;
	do{
	
	printf("1 - Cadastrar\n");
	printf("2 - Consultar\n");
	printf("3 - Alterar\n");
	printf("4 - Deletar\n");
	printf("5 - Sair\n");
	printf("========================\n");
	
	printf("Digite uma opcao para escolha: ");
	scanf("%i", &opcao);
	
	
	
	switch(opcao){
		case 1:
			cadastrarAgenda(&vetAgenda);
			break;
			
		case 2:
			consultarAgenda(&vetAgenda);
			break;
		case 3:
			printf("");
			break;
		case 4:
			printf("");
			break;
		case 5:
			break;
		default:
			printf("Escolha uma opcao valida!");
	}
	
	}while(opcao != 5);
	
	return 0;
}
