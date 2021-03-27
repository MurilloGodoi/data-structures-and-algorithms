struct agenda {
	char nome[40];
	int  idade;
	char email[40];
	char telefone[15];
	struct agenda *prox;
	struct agenda *ant;
};
typedef struct agenda contato;


void load(){
	
    char ascii = 178;
    printf("\n");
    
    for(int i = 0;i<50;i++){
        printf("%c%",ascii);
        Sleep(50);
    }
}

void limpaTela() {
	system("cls");
}


contato *cria_ponteiro() {
	contato *p=(contato*)malloc(sizeof(contato));
	
	if(!p) {
		printf("Erro!");
	}
	else {
		p->nome[0]=NULL;
		p->idade=NULL;
		p->email[0]=NULL;
		p->telefone[0]=NULL;
		p->prox=NULL;
		p->ant=NULL;
	}
	return p;
}

bool eh_vazia(contato *inicio){
	if(inicio->prox == NULL) {
		return true;
	} else {
		return false;
	}
}

void inserir(contato *inicio) {
	
	contato *nova = cria_ponteiro();
	
	printf("Informe o nome do contato: ");
	fflush(stdin);
	gets(nova->nome);
	printf("Idade: ");
	scanf("%d",&nova->idade);
	printf("E-mail: ");
	fflush(stdin);
	gets(nova->email);
	printf("Telefone: ");
	fflush(stdin);
	gets(nova->telefone);
	
	if(inicio->prox == NULL) {
		inicio->prox = nova;
		nova->ant = inicio;
	} else {
		contato *temp;
		temp = inicio;
		while(temp->prox != NULL) {
			temp = temp->prox;
		}
		temp->prox = nova;
		nova->ant = temp;
	}
	
	printf("\nAgurde enquanto cadastramos o contato no sistema!!");
	load();
	limpaTela();
}

void imprimir_todos(contato *inicio) {
	if(!eh_vazia(inicio)) {
		contato *temp;
		temp = inicio;
		while(temp->prox != NULL) {
			temp = temp->prox;
			printf("###################################\n");
			printf("Nome do contato: %s\n",temp->nome);
			printf("Idade: %d\n",temp->idade);
			printf("E-mail: %s\n",temp->email);
			printf("Telefone: %s\n",temp->telefone);
			printf("###################################\n");
		}
	} else {
		printf("A agenda esta vazia!!\n");
	}
}

void bubble_sort(contato *inicio) {
	contato *fim;
	fim=inicio->prox;
	contato *bolha;
	contato *aux;
	
	while(fim->prox != NULL){
		fim = fim->prox;
	}
	
	bolha = inicio->prox;
	aux= bolha->prox;
	while(fim->ant != NULL){
		bolha = inicio->prox;
		aux= bolha->prox;
		while(bolha->prox != NULL){
			if(bolha->idade > aux->idade){
				bolha->ant->prox=bolha->prox;
				aux->ant=bolha->ant;
				bolha->prox = aux->prox;
				if(aux->prox==NULL){
					aux = fim;
				}
				else{
					bolha->prox->ant=aux;
				}
				aux->prox= bolha;
				bolha->ant=aux;
				aux = bolha->prox;
			}
			else{
				bolha = bolha->prox;
				aux = aux->prox;
			}
		}
		fim = fim->ant;
	}
}

void selection_sort(contato *inicio) {
	contato *ref, *aux, *temp;
	ref = inicio->prox;
	while(ref != NULL && inicio->prox != NULL){
		if(ref->prox == NULL){
			aux = ref;
		}
		else {
			aux = ref->prox;
		}
		if(aux->idade < ref->idade && ref==inicio->prox){ 
			ref->ant->prox = aux;
			ref->prox = aux->prox;
			aux->ant = ref->ant;
			ref->ant = aux;
			if(ref->prox != NULL) {
				aux->prox->ant = ref;	
			}
			aux->prox = ref;
			aux = ref->prox;
		}
		else {
			if(aux != NULL && aux->idade < ref->idade){
				if(aux->prox == NULL){
					temp = ref->ant;
					ref->ant->prox = aux;
					aux->ant = ref->ant;
					ref->ant = aux;
					aux->prox = ref;
					ref->prox = NULL;
				}
				else {
					temp = ref->ant;
					ref->ant->prox = aux;
					ref->prox = aux->prox;
					aux->ant = ref->ant;
					ref->ant = aux;
					aux->prox->ant = ref;
					aux->prox = ref;
				}
			}
			else{
				if(ref->prox == NULL){
					break;
				}
				ref = ref->prox;
			}
			while(aux->idade < ref->idade && temp != inicio){
				if(temp->idade > aux->idade){
					temp->ant->prox = aux;
					temp->prox = aux->prox;
					aux->ant = temp->ant;
					temp->ant = aux;
					aux->prox->ant = temp;
					aux->prox = temp;
					temp = aux->ant;
				}
				else
					temp = temp->ant;
			}
		}
	}
}

void insertion_sort(contato *inicio) {
	contato *ref, *aux, *temp;
	ref = inicio->prox;
	while(ref != NULL && inicio->prox != NULL){
		if(ref->prox == NULL){
			aux = ref;
		}
		else {
			aux = ref->prox;
		}
		if(aux->idade < ref->idade && ref==inicio->prox){
			ref->ant->prox = aux;
			ref->prox = aux->prox;
			aux->ant = ref->ant;
			ref->ant = aux;
			if(ref->prox != NULL) {
				aux->prox->ant = ref;	
			}
			aux->prox = ref;
			aux = ref->prox;
		}
		else {
			if(aux != NULL && aux->idade < ref->idade){
				if(aux->prox == NULL){
					temp = ref->ant;
					ref->ant->prox = aux;
					aux->ant = ref->ant;
					ref->ant = aux;
					aux->prox = ref;
					ref->prox = NULL;
				}
				else {
					temp = ref->ant;
					ref->ant->prox = aux;
					ref->prox = aux->prox;
					aux->ant = ref->ant;
					ref->ant = aux;
					aux->prox->ant = ref;
					aux->prox = ref;
				}
			}
			else{
				if(ref->prox == NULL){
					break;
				}
				ref = ref->prox;
			}
			while(aux->idade < ref->idade && temp != inicio){
				if(temp->idade > aux->idade){
					temp->ant->prox = aux;
					temp->prox = aux->prox;
					aux->ant = temp->ant;
					temp->ant = aux;
					aux->prox->ant = temp;
					aux->prox = temp;
					temp = aux->ant;
				}
				else
					temp = temp->ant;
			}
		}
	}
}
