#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "funcs-pilha.h"

int main() {
	contato *topo = cria_ponteiro();
	int op=-9;
	do {
		printf("Bem vindo ao sistema de agendamento\n");
		printf("Escolha 1 das opcoes a seguir:\n");
		printf("1- Inserir contatos na pilha\n");
		printf("2- Imprimir todos os contatos\n");
		printf("3- Imprimir um contato especifico\n");
		printf("4- Remover um contato\n");
		printf("5- Imprimir em ordem inversa\n");
		printf("6- Editar um contato\n");
		printf("7- Remover a pilha\n");
		printf("8- Sair\n");
		scanf("%d",&op);
		
		switch(op) {
			case 1:
				topo = inserir(topo);
				break;
			case 2:
				imprimir_todos(topo);
				break;
			case 3:
				imprimir_especifico(topo);
				break;
			case 4:
				remover_especifico(topo);
				break;
			case 5:
				//imprimir_inverso(topo);
				break;
			case 6:
				editar(topo);
				break;
			case 7:
				topo = remover_pilha(topo);
				break;
			case 8:
				printf("FIM DO PROGRAMA!!");
				break;
			default: {
				printf("Opcao invalida!!");
				printf("Por favor digite uma opcao valida\n");
				Sleep(1500);
				limpaTela();
				break;
			}
		}	
	} while(op != 8);
	return 0;
	system("pause");
}
