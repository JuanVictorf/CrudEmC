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

int tamanhoAgenda = 2;
Agenda vetAgenda[10];

int cadastrarAgenda(Agenda *vetAgenda){
	
	int i;
	for(i = 0; i < tamanhoAgenda; i++){
		printf("Digite o nome da pessoa: \n");
		scanf("%s", &vetAgenda[i].nome);
		printf("Digite o telefone da pessoa: \n");
		scanf("%s", &vetAgenda[i].telefone);
		printf("Digite a empresa da pessoa: \n");
		scanf("%s", &vetAgenda[i].empresa);
	}
}

int consultarAgenda(Agenda *vetAgenda){
	int i;
	char opcao[100];
	
	printf("Digite Todo para listar agenda completa ou Nome: \n");
	scanf("%s", opcao);
	
	if(strcmp(opcao, "Todo") == 0){
		for(i = 0; i < tamanhoAgenda; i++){
			printf("Nome da pessoa: %s\n", vetAgenda[i].nome);
			printf("Telefone da pessoa: %s\n", vetAgenda[i].telefone);
			printf("Empresa da pessoa: %s\n", vetAgenda[i].empresa);
		}
	}
	
	if(strcmp(opcao, "Nome") == 0){
		char nomeConsulta[50];
		printf("Digite o nome que deseja alterar: \n");
		scanf("%s", &nomeConsulta);
		for(i = 0; i < tamanhoAgenda; i++){
			if(strcmp(vetAgenda[i].nome, nomeConsulta) == 0){
				printf("Nome da pessoa: %s\n", vetAgenda[i].nome);
				printf("Telefone da pessoa: %s\n", vetAgenda[i].telefone);
				printf("Empresa da pessoa: %s\n", vetAgenda[i].empresa);
			}
		}
	}
}

int alteraAgenda(Agenda *vetAgenda){
	char nomeConsulta[50];
	printf("Digite o nome que deseja alterar: \n");
	scanf("%s", &nomeConsulta);
	int retornoString;
	
	int i;
	for(i = 0; i < tamanhoAgenda; i++){
		retornoString = strcmp(vetAgenda[i].nome, nomeConsulta);
		if(retornoString == 0){
			char alteracao[50];
			printf("Registro existe, o que deseja alterar?\n");
			printf("Nome: %s\n", vetAgenda[i].nome);
			printf("Telefone: %s\n", vetAgenda[i].telefone);
			printf("Empresa: %s\n", vetAgenda[i].empresa);
			scanf("%s", &alteracao);
			if(strcmp(alteracao, "Nome") == 0){
				printf("Digite o novo nome: \n");
				scanf("%s", &vetAgenda[i].nome);
			} else if(strcmp(alteracao, "Telefone") == 0){
				printf("Digite o novo telefone: \n");
				scanf("%s", &vetAgenda[i].telefone);
			} else if(strcmp(alteracao, "Empresa") == 0){
				printf("Digite o novo nome da empresa: \n");
				scanf("%s", &vetAgenda[i].empresa);
			} else{
				printf("Nao existe essa opcao.\n");
			}
		}
	}
	
}

int deletaAgenda(Agenda *vetAgenda){
	char nomeConsulta[50];
	printf("Deseja deletar qual registro, insira o nome: ");
	scanf("%s", &nomeConsulta);
	
	int retornoString;
	int i, j;
	for(i = 0; i < tamanhoAgenda; i++){
		retornoString = strcmp(vetAgenda[i].nome, nomeConsulta);
		if(retornoString == 0){
			for(j = i; j < tamanhoAgenda - 1; j++){
				vetAgenda[j] = vetAgenda[j + 1];
				// Posicao que ele achou recebe a próxima posicao do vetor
			}
		} 
	}
	tamanhoAgenda--;
	printf("Registro excluido!\n");
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
			alteraAgenda(&vetAgenda);
			break;
		case 4:
			deletaAgenda(&vetAgenda);
			break;
		case 5:
			break;
		default:
			printf("Escolha uma opcao valida!");
	}
	
	}while(opcao != 5);
	
	return 0;
}
