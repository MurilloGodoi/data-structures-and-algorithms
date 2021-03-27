/*
  Atividade 07/05/2020
  Murillo Godoi Pedroso
  C�digo: 830898
*/

#include <stdio.h>
#include <stdlib.h>

struct no {
	int valor;
	struct no* direita;
	struct no* esquerda;
};

typedef struct no arv;

//Fun��o para criar �rvore vazia
arv* cria_arv_vazia() {
	return NULL;
}

//Fun��o para criar �rvore
arv* criar_arv(int valor, arv* direita, arv* esquerda) {
	
	arv* arvore = (arv*) malloc(sizeof(arv));
	
	arvore->valor = valor;
	arvore->direita = direita;
	arvore->esquerda = esquerda;
	
	return arvore;
}

//Fun��o para inserir valores inteiros na �rvore
arv* insere(arv* arvore, int valor) {
	if (arvore==NULL) {
		arvore = criar_arv(valor, NULL, NULL);
	} else if (valor < arvore->valor) {
		arvore->esquerda = insere(arvore->esquerda, valor);
		
	} else {
		arvore->direita = insere(arvore->direita, valor);
	}
	
	return arvore;
}
//Fun��o para calcular a altura 
int altura(arv* raiz) {

    if(raiz->esquerda == NULL && raiz->direita == NULL) {
        return 0;
    }

    int altura_esquerda = 0, altura_direita = 0;

    if(raiz->esquerda != NULL) {
        1 + altura(raiz->esquerda);
    }
    
    if(raiz->direita != NULL) {
        1 + altura(raiz->direita);
    }

    if (altura_esquerda > altura_direita) {
        return altura_direita + 1;

    } else {
        return altura_direita + 1;

    }
}

//Fum��o para calcular o valor de balanceamento
int fator_de_balanceamento(arv* raiz) {
    int altura_esquerda = altura(raiz->esquerda);
    int altura_direita = altura(raiz->direita);

    return altura_direita - altura_esquerda; 
}

//Fun��o para Verificar se a �rvore � AVL OU N�O
int verificar_avl(arv* raiz) {
    int fator_raiz, avl_esquerda=1, avl_direita=1;

    if (fator_raiz < -1 || fator_raiz > 1) {
        return 0;
    }
    
    if (raiz->esquerda != NULL) {
        avl_esquerda = verificar_avl(raiz->esquerda);
    }
    
    if (raiz->direita != NULL) {
        avl_direita = verificar_avl(raiz->direita);
    }

    if (!avl_esquerda || !avl_direita) {
        return 0;
    }

    return 1;
}

//Fun��o para mostrar os valores inteiros inseridos na �rvore, em ordem.
void print_arvore_em_ordem(arv* arvore){


    if (arvore!=NULL){
        print_arvore_em_ordem(arvore->esquerda);
        print_arvore_em_ordem(arvore->direita);
        printf("%d\n",arvore->valor);
       
    }
}

int main() {
	//Inserindo valores inteiros na �rvore
	arv* arvore = criar_arv(50, NULL, NULL);
	arvore = insere(arvore, 30);
	arvore = insere(arvore, 20);
	arvore = insere(arvore, 10);
	arvore = insere(arvore, 40);
	
	//Mostrar valores inteiros inseridos na �rvore, em ordem.
	print_arvore_em_ordem(arvore);
	
}
