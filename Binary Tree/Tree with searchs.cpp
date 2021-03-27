#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct agenda {
	char nome[30];
	char email[30];
	char endereco[30];
	char data_aniversario[30];
	int idade;
	struct agenda* dir;
	struct agenda* esq;
};
typedef struct agenda agenda;

agenda* cria_arvore_vazia() {
	return NULL;
}

agenda* criar_arvore(agenda* dir, agenda* esq, int idade,char nome[30],char email[30], char endereco[30], char data_aniversario[30]){
		agenda* arvore = (agenda*) malloc(sizeof(agenda));
		strcpy(arvore->nome,nome);
		strcpy(arvore->email,email);
		strcpy (arvore->endereco,endereco);
		strcpy (arvore->data_aniversario,data_aniversario);
		arvore->dir=dir;
		arvore->esq=esq;
		arvore->idade=idade;
	
	return arvore;
}

agenda* inserir(agenda* arvore,int idade,char nome[30],char email[30],char endereco[30],char data_aniversario[30]){
	
	if(arvore==NULL){
	arvore=	criar_arvore(NULL,NULL,idade,nome,email,endereco,data_aniversario);
	
	}else if (strcmp(email,arvore->email)<0){
		arvore->esq=inserir(arvore->esq,idade,nome,email,endereco,data_aniversario);
	
	}else{
		arvore->dir=inserir(arvore->dir,idade,nome,email,endereco,data_aniversario);
	}
	
	return arvore;
}

void print_arvore_pos(agenda* arvore){
	if (arvore!=NULL){	
	
		print_arvore_pos(arvore->esq);
		print_arvore_pos(arvore->dir);
		printf("\n%d\n%s\n%s\n%s\n%s\n",arvore->idade,arvore->nome,arvore->email,arvore->endereco,arvore->data_aniversario);
	}
}

void print_arvore_em(agenda* arvore){
	if (arvore!=NULL){
		
		print_arvore_em(arvore->esq);
		printf("\n%d\n%s\n%s\n%s\n%s\n",arvore->idade,arvore->nome,arvore->email,arvore->endereco,arvore->data_aniversario);
		print_arvore_em(arvore->dir);
		
	}
}

void print_arvore_pre(agenda* arvore){
	if (arvore!=NULL){
		
		printf("\n%d\n%s\n%s\n%s\n%s\n",arvore->idade,arvore->nome,arvore->email,arvore->endereco,arvore->data_aniversario);
		print_arvore_pre(arvore->esq);
		print_arvore_pre(arvore->dir);
	}
}


agenda* busca(agenda* arvore, char email[30]) {

	agenda* resultado = NULL;

	if (arvore == NULL) {
		return NULL;
	}
	
	int cmp = strcmp(email,arvore->email);
	
	if (cmp == 0) {
		resultado = arvore;
	
	} else if (cmp < 0) {
		resultado = busca(arvore->esq,email);
	
	} else if (cmp > 0) {
		resultado = busca(arvore->dir, email);
	}

	return resultado;
}

void salvar_agenda(agenda* arvore, FILE * arquivo){
	if (arvore != NULL){
		fwrite(arvore, sizeof (agenda),1,arquivo);
		salvar_agenda(arvore->esq,arquivo);
		salvar_agenda(arvore->dir,arquivo);
		free(arvore);
	}	
}
	
void salvar(agenda* arvore){
	FILE * arquivo = fopen("agenda","wb");
	
	if (arquivo != NULL) {
		salvar_agenda (arvore, arquivo);
		fclose (arquivo);			
	}			
}

agenda* carregar_agenda(agenda* arvore){
	FILE *arquivo = fopen("agenda","rb");
	
	if (arquivo != NULL){
		agenda* arvore_carregada = (agenda*) malloc(sizeof (agenda));
		while (fread(arvore_carregada,sizeof(agenda),1,arquivo)){
		
			arvore=inserir(arvore, arvore_carregada->idade,arvore_carregada->nome,arvore_carregada->email,arvore_carregada->endereco,arvore_carregada->data_aniversario);
		}
		fclose(arquivo);
		free(arvore_carregada);
	}	
	
	return arvore; 
}

int main() {
	int idade;
	int tipo;
	char nome[30],email[30],endereco[30],data_aniversario[30];
	
	agenda *arvore = cria_arvore_vazia();
	agenda *arvore_busca;
	arvore= carregar_agenda(arvore);
	
	int opcao=-9;
	do {
		
		printf("\nEscolha uma das opcoes abaixo:");
		printf("\n\n(1-) Inserir Contatos\n");
		printf("(2-) Buscar Contato Por Email\n");
		printf("(3-) Listar Todos os Contatos\n");
		printf("(4-) Sair\n");
		
		scanf("%d",&opcao);
		
		switch(opcao) {
			
			case 1:
				printf("\nInsira seu Nome:");
				scanf ("%s",nome);
				printf("\nInsira seu E-mail:");
				scanf ("%s",email);
				printf("\nInsira seu Endereco:");
				scanf ("%s",endereco);
				printf("\nInsira sua Idade:");
				scanf ("%d",&idade);
				printf("\nInsira sua Data de Aniversario:");
				scanf ("%s",data_aniversario);
				arvore=inserir(arvore,idade,nome,email,endereco,data_aniversario);
				
				break;
				
			case 2:
				printf("\nInsira o E-mail para Realizar a Busca:");
				scanf("%s",email);
				arvore_busca = busca(arvore,email);
				printf("%d\n%s\n%s\n%s\n%s\n",arvore_busca->idade,arvore_busca->nome,arvore_busca->email,arvore_busca->endereco,arvore_busca->data_aniversario);
				break;							
				
			case 3:
				printf("\nSelecione o Tipo de Listagem \n\n(1-)Pos-ordem\n (2-)Em-Ordem\n (3-)Pre-Ordem):\n");
				scanf("%d",&tipo);
				
				if (tipo==1){
					print_arvore_pos(arvore);
					 
				}
				else if (tipo==2){
					 print_arvore_em(arvore);
				}
				
				else if (tipo==3){
					 print_arvore_pre(arvore);
				}
				
				break;
				
			case 4:
				salvar(arvore);
				exit(0);
				break;
			default: {
				
				printf("\nDigite uma opcao valida\n");
				break;
			}
		}	
	} while(opcao != 9);
	
}



