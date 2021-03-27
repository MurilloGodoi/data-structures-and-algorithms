/*
  Atividade 16/04/2020
  Murillo Godoi Pedroso
  Código: 830898
*/

#include <stdio.h>
#include <stdlib.h>

struct no {
	int ra;
	float parcial, exame, integrador, media;
	struct no* direita;
	struct no* esquerda;
};

typedef struct no arv;

arv* cria_arv_vazia() {
	return NULL;
}

arv* criar_arv(int ra, float parcial, float exame, float integrador, float media, arv* direita, arv* esquerda) {
	
	arv* arvore = (arv*) malloc(sizeof(arv));
	
	arvore->ra = ra;
	arvore->parcial = parcial;
	arvore->exame = exame;
	arvore->integrador = integrador;
	arvore->media = media;
	arvore->direita = direita;
	arvore->esquerda = esquerda;
	
	return arvore;
}

arv* insere(arv* arvore, int ra, float parcial, float exame, float integrador, float media) {
	if (arvore==NULL) {
		arvore = criar_arv(ra, parcial, exame, integrador, media, NULL, NULL);
	} else if (ra < arvore->ra) {
		arvore->esquerda = insere(arvore->esquerda, ra, parcial, exame, integrador, media);
		
	} else {
		arvore->direita = insere(arvore->direita, ra, parcial, exame, integrador, media);
	}
	
	return arvore;
}

arv* busca(arv* arvore, int ra) {

	arv* resultado = NULL;

	if (arvore == NULL) {
		return NULL;
	}

	if (ra == arvore->ra) {
		resultado = arvore;

	} else if (ra < arvore->ra) {
		resultado = busca(arvore->esquerda, ra);

	} else if (ra > arvore->ra) {
		resultado = busca(arvore->direita, ra);
	}

	return resultado;
}

void print_arvore_em_ordem(arv* arvore){
	if (arvore!=NULL){
		
		print_arvore_em_ordem(arvore->esquerda);
		printf("%d\n",arvore->ra);
		print_arvore_em_ordem(arvore->direita);
	}

}

int main() {
	int ra,escolha, ra_buscado;
	float parcial, exame, integrador, media;

	arv* arvore_buscada;
	arv* arvore = criar_arv(830898, 10, 5, 2,7.6, NULL, NULL);
	arvore = insere(arvore, 830777, 5, 5, 2,5.6 );
	

	while(4) {
		printf("Escolha uma opcao:\n");
		printf("1 - Inserir\n");
		printf("2 - Listar\n");
		printf("3 - Buscar\n");
		printf("4 - Sair\n");
		

		scanf("%d", &escolha);

		printf("\n");

		switch(escolha) {
			case 1:{
				
				printf("Informe o RA: ");
				scanf("%i", &ra);
				printf("Informe a nota parcial: ");
				scanf("%f", &parcial);
				printf("Informe a nota do exame: ");
				scanf("%f", &exame);
				printf("Informe a nota do integrador: ");
				scanf("%f", &integrador);

				media = (parcial * 0.4) + ((exame * 0.8) + integrador) * 0.6;

				arvore = insere(arvore, ra, parcial, exame, integrador, media);
				break; }
					
			case 2:{
				print_arvore_em_ordem(arvore);
				break; }

			case 3:{
				
				printf("Insira um ra:\n");
				scanf("%i", &ra_buscado);

				 arvore_buscada = busca(arvore, ra_buscado);

				if (arvore_buscada != NULL) {
					printf("parcial = %.2f\n", arvore_buscada->parcial);
					printf("exame = %.2f\n", arvore_buscada->exame);
					printf("integrador = %.2f\n", arvore_buscada->integrador);
					printf("media = %.2f\n", arvore_buscada->media);

				} else {
					printf("RA nao encontrado\n");
				}

				break; 

			case 4:{
				exit(0);
				break; }
				
			default:{
			printf("Opcao nao existente");
			break;
		} 
		}
		
		printf("\n --------------------------------------\n\n");
	}	
}}
