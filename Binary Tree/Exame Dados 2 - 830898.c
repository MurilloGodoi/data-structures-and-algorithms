/* Murillo Godoi Pedroso
		830898 */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define TAMANHO_ALFABETO 26
#define TAMANHO_MAX_PALAVRA 26

struct No {
    struct No *caminhos[TAMANHO_ALFABETO];
    int final_palavra;
};
typedef struct No No;

No *criar_no() {
    int i;
    No *novo_no = (No *) malloc(sizeof(No));
    novo_no->final_palavra = 0;
    for (i = 0; i < TAMANHO_ALFABETO; i++) {
        novo_no->caminhos[i] = NULL;
    }
    return novo_no;
}

int buscar_palavra(char palavra[TAMANHO_MAX_PALAVRA], No *raiz) {
    int i;
    No* no_atual = raiz;
    char letra;

    for (i = 0; palavra[i] != 0; i++) {
        letra = palavra[i] - 'a';
        if (letra < 0 || letra >= TAMANHO_ALFABETO) {
            return 0;
        }
        if (no_atual->caminhos[letra] == NULL) {
            return 0;
        }
        no_atual = no_atual->caminhos[letra];
    }
    if (no_atual->final_palavra == 1) {
        return 1;
    }
    return 0;
}

char *formatar_palavra(char *palavra) {
    int i;

    for (i = 0; palavra[i] != 0; i++) {
        if (palavra[i] == '/' || palavra[i] == '\n') {
            palavra[i] = 0;
        }
    }
}

int palavra_valida(char palavra[TAMANHO_MAX_PALAVRA]) {
    int i;
    char letra;

    for (i = 0; palavra[i] != 0; i++) {
        letra = palavra[i] - 'a';
        if (letra < 0 || letra >= TAMANHO_ALFABETO) {
            return 0;
        }
    }

    return 1;
}

void inserir_palavra(char palavra[TAMANHO_MAX_PALAVRA], No* raiz) {
    int indice_atual = 0;
    No* no_atual = raiz;
    char letra_atual;

    while (1) {
        letra_atual = palavra[indice_atual];
        if (letra_atual == 0) {
            break;
        }
        int indice_letra_atual = letra_atual - 'a';
        if (no_atual->caminhos[indice_letra_atual] != NULL) {
            no_atual = no_atual->caminhos[indice_letra_atual];
        } else {
            no_atual->caminhos[indice_letra_atual] = criar_no();
            no_atual = no_atual->caminhos[indice_letra_atual];
        }
        indice_atual++;
    }

    no_atual->final_palavra = 1;
}

void salvar_no(No *no, char *buffer, int nivel,  FILE *arquivo) {
    int i;
    if (no->final_palavra) {
        buffer[nivel] = '\n';
        buffer[nivel+1] = '\0';
        fprintf(arquivo, buffer);
    }
    for (i = 0; i < TAMANHO_ALFABETO; ++i) {
        if (no->caminhos[i] != NULL) {
            buffer[nivel] = i + 'a';
            salvar_no(no->caminhos[i], buffer, nivel+1, arquivo);
        }
    }
}

void salvar_dicionario(No *raiz) {
    FILE *arquivo = fopen("pt_BR.dic", "w");
    int i, nivel=0;
    char buffer[TAMANHO_MAX_PALAVRA+1];

    salvar_no(raiz, buffer, 0, arquivo);
}

void destruir_arvore(No *raiz) {
    int i;
    for (i = 0; i < TAMANHO_ALFABETO; i++) {
        if (raiz->caminhos[i] != NULL) {
            destruir_arvore(raiz->caminhos[i]);
        }
    }
    free(raiz);
}

int main() {
	
    FILE *arquivo = fopen("pt_BR.dic", "r");
    char linha[TAMANHO_MAX_PALAVRA], palavra_buscada[TAMANHO_MAX_PALAVRA];
    size_t len = 0;
    No *raiz = criar_no();
    int escolha, novas_palavras = 0, opcao=-9;

    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo");
        exit(1);
    }

   
    fgets(linha, sizeof(linha), arquivo);
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        formatar_palavra(linha);
        if (palavra_valida(linha)) {
            inserir_palavra(linha, raiz);
        }
    }
    fclose(arquivo);

	do {
		system("cls");
        printf("Escolha uma opcao:\n\n");
        printf("(-1) Buscar Palavra no Dicionario\n\n");
        printf("(-2) Sair\n\n");
        scanf("%i", &opcao);
        system("cls");
        switch (opcao) {
            case 1:
                printf("Informe a palavra a ser buscada no dicionario:\t");
                fgets(palavra_buscada, sizeof(palavra_buscada), stdin);
                fgets(palavra_buscada, sizeof(palavra_buscada), stdin);
                formatar_palavra(palavra_buscada);
                
                if (!palavra_valida(palavra_buscada)) {
                	system("cls");
                    printf("Palavra possui caractere invalido\n");
                    sleep(2);
                } else {
                    if (buscar_palavra(palavra_buscada, raiz)) {
                    	system("cls");
                        printf("Palavra encontrada no dicionario\n");
                        sleep(2);
                    } else {
                    	system("cls");
                        printf("Palavra nao encontrada no dicionario\n\n");
                        printf("Deseja inserir essa palavra no dicionario?\n\n");
                        printf("(-1) Sim\n");
                        printf("(-2) Nao\n");
                        scanf("%i", &opcao);
                        
                        if (opcao == 1) {
                            inserir_palavra(palavra_buscada, raiz);
                            novas_palavras = 1;
                            system("cls");
                            printf("Palavra inserida no dicionario\n\n\n");
                            printf("Voltando para o menu...");
                            sleep(2);
                        } else {
                        	system("cls");
                            printf("Palavra nao inserida no dicionario\n\n\n");
                            printf("Voltando para o menu...");
                            sleep(2);
                        }
                    }
                }
                break;
                
            case 2:
                if (novas_palavras) {
                    salvar_dicionario(raiz);
                }
                destruir_arvore(raiz);
                exit(0);
                break;
            default:
                printf("\nEscolha uma opcao valida\n");
        }
    }  while(opcao != 9);
    return 1;
}
