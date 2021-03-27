#include <stdio.h>
#include <stdlib.h>

struct no {
	int conteudo;
	struct no* direita;
	struct no* esquerda;
	
};
typedef struct no arv;

arv*cria_arv_vazia(){
	return NULL;
}
arv* criar_arv(int conteudo,arv* direita, arv* esquerda){
	arv* arvore = (arv*) malloc(sizeof(arv));
	arvore->conteudo=conteudo;
	arvore->direita=direita;
	arvore->esquerda=esquerda;
	
	return arvore;
}
arv* insere(arv* arvore,int conteudo){
	if(arvore==NULL){
	arvore=	criar_arv(conteudo,NULL,NULL);
	}else if (conteudo<arvore->conteudo){
		arvore->esquerda=insere(arvore->esquerda,conteudo);
	
	}else{
		arvore->direita=insere(arvore->direita,conteudo);
	}
	return arvore;
}

void print_arvore_pre(arv* arvore){
	if (arvore!=NULL){
		printf("%d\n",arvore->conteudo);
		
		print_arvore_pre(arvore->esquerda);
		print_arvore_pre(arvore->direita);
	}
}
void print_arvore_em_ordem(arv* arvore){
	if (arvore!=NULL){
		
		print_arvore_em_ordem(arvore->esquerda);
		printf("%d\n",arvore->conteudo);
		print_arvore_em_ordem(arvore->direita);
	}
}
void print_arvore_pos(arv* arvore){
	if (arvore!=NULL){
		
		
		print_arvore_pos(arvore->esquerda);
		print_arvore_pos(arvore->direita);
		printf("%d\n",arvore->conteudo);
	}
}



int main(){
	arv* arvore=criar_arv(6,NULL,NULL);
	arvore = insere(arvore, 4);
	arvore = insere(arvore, 2);
	arvore = insere(arvore, 1);
	arvore = insere(arvore, 3);
	arvore = insere(arvore, 5);
	arvore = insere(arvore, 8);
	arvore = insere(arvore, 7);
	arvore = insere(arvore, 9);

	printf("\n");
	printf("Pre Ordem");printf("\n");printf("\n");
	print_arvore_pre(arvore);printf("\n");
	printf("Em ordem");printf("\n");printf("\n");
	print_arvore_em_ordem(arvore);printf("\n");
	printf("Pos Ordem");printf("\n");printf("\n");
	print_arvore_pos(arvore);printf("\n");
}
