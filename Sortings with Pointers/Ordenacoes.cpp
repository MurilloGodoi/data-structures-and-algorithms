#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "funcs-ordenacoes.h"

int main() {
	contato *inicio = cria_ponteiro();
	int op=-9;
	do {
		printf("Bem vindo ao sistema de agendamento\n");
		printf("Escolha 1 das opcoes a seguir:\n");
		printf("1- Inserir contatos no fim da agenda\n");
		printf("2- Odenacao Bublle Sort\n");
		printf("3- Odenacao Selection Sort\n");
		printf("4- Odenacao Insertion Sort\n");
		printf("5- Odenacao Quick Sort\n");
		printf("6- Imprimir todos\n");
		printf("7- Sair\n");
		scanf("%d",&op);
		
		switch(op) {
			case 1:
				inserir(inicio);
				break;
			case 2:
				bubble_sort(inicio);
				break;
			case 3:
				selection_sort(inicio);
				break;
			case 4:
				insertion_sort(inicio);
				break;
			case 5:
				//quick_sort(inicio);
				break;
			case 6:
				imprimir_todos(inicio);
				break;
			case 7:
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
	} while(op != 7);
	return 0;
	system("pause");
}
