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
        Sleep(1);
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

bool eh_vazia(contato *topo){
	if(topo->ant == NULL) {
		return true;
	} else {
		return false;
	}
}

contato *inserir(contato *topo) {
	
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
	
	if(topo->prox==NULL){
		topo->prox=nova;
		nova->ant=topo;
		topo=nova;
	}
	
	printf("\nAgurde enquanto cadastramos o contato no sistema!!");
	load();
	limpaTela();
	return topo;
}

void editar(contato *topo) {
	char editar[40];
	
	printf("Informe o nome do contato para edicao: ");
	fflush(stdin);
	gets(editar);
	
	contato *temp;
	temp = topo;
	while(temp->ant != NULL) {
		if(strcmp(editar, temp->nome) == 0) {
			printf("Informe o nome do contato: ");
			fflush(stdin);
			gets(temp->nome);
			printf("Idade: ");
			scanf("%d",&temp->idade);
			printf("E-mail: ");
			fflush(stdin);
			gets(temp->email);
			printf("Telefone: ");
			fflush(stdin);
			gets(temp->telefone);
		}
		temp = temp->ant;
	}
}

void imprimir_todos(contato *topo) {
	if(eh_vazia(topo) == false) {
		contato *temp;
		temp = topo;
		while(temp->ant != NULL) {
			printf("###################################\n");
			printf("Nome do contato: %s\n",temp->nome);
			printf("Idade: %d\n",temp->idade);
			printf("E-mail: %s\n",temp->email);
			printf("Telefone: %s\n",temp->telefone);
			printf("###################################\n");
			temp = temp->ant;
		}
	} else {
		printf("A agenda esta vazia!!\n");
	}
}

void imprimir_especifico(contato *topo) {
	if(!eh_vazia(topo)) {
		int consultaInt;
		char consultaChar[40];
		int op=-9;
		printf("Informe o metodo de busca na agenda:\n");
		printf("1- Nome\n");
		printf("2- Idade\n");
		printf("3- E-mail\n");
		printf("4- Telefone\n");
		printf("5- Sair da funcao\n");
		scanf("%d",&op);
		
		switch(op) {
			case 1: {
		
					printf("Digite o nome para consulta: ");
					fflush(stdin);
					gets(consultaChar);
			
					contato *temp;
					temp = topo;
					while(temp->ant != NULL) {
						if(strcmp(consultaChar, temp->nome) == 0) {
							printf("###################################\n");
							printf("Nome do contato: %s\n",temp->nome);
							printf("Idade: %d\n",temp->idade);
							printf("E-mail: %s\n",temp->email);
							printf("Telefone: %s\n",temp->telefone);
							printf("###################################\n");
						}
						temp = temp->ant;
					}
					break;
				}
			case 2: {
				
					printf("Digite a idade para consulta: ");
					scanf("%d",&consultaInt);
					
					contato *temp;
					temp = topo;
					while(temp->ant != NULL) {
						if(consultaInt == temp->idade) {
							printf("###################################\n");
							printf("Nome do contato: %s\n",temp->nome);
							printf("Idade: %d\n",temp->idade);
							printf("E-mail: %s\n",temp->email);
							printf("Telefone: %s\n",temp->telefone);
							printf("###################################\n");	
						}
						temp = temp->ant;
					}
					break;
				}
			case 3: {
				
					printf("Digite o e-mail para consulta: ");
					fflush(stdin);
					gets(consultaChar);
					
					contato *temp;
					temp = topo;
					while(temp->ant != NULL) {
						if(strcmp(consultaChar, temp->email) == 0) {
							printf("###################################\n");
							printf("Nome do contato: %s\n",temp->nome);
							printf("Idade: %d\n",temp->idade);
							printf("E-mail: %s\n",temp->email);
							printf("Telefone: %s\n",temp->telefone);
							printf("###################################\n");
						}
						temp = temp->ant;
					}
					break;
				}
			case 4: {
				
					printf("Digite o telefone para consulta: ");
					fflush(stdin);
					gets(consultaChar);
					
					contato *temp;
					temp = topo;
					while(temp->ant != NULL) {
						if(strcmp(consultaChar, temp->telefone) == 0) {
							printf("###################################\n");
							printf("Nome do contato: %s\n",temp->nome);
							printf("Idade: %d\n",temp->idade);
							printf("E-mail: %s\n",temp->email);
							printf("Telefone: %s\n",temp->telefone);
							printf("###################################\n");
						}
						temp = temp->ant;
					}
					break;
				}
			case 5:
				printf("Voltando ao menu principal!!");
				Sleep(1500);
				limpaTela();
				break;
			default: {
				printf("Opcao invalida!!");
				printf("Por favor digite uma opcao valida");
				Sleep(1500);
				limpaTela();
				break;
			}
		}
	} else {
		printf("A agenda esta vazia!!\n");
	}
}

contato *remover_pilha(contato *topo) {
	
	while(topo->ant !=NULL){
		topo=topo->ant;
		free(topo->prox);
		topo->prox=NULL;
	}
	
	return topo;
}

void remover_especifico(contato *topo) {
	char removeChar[40];
	contato *topoaux = cria_ponteiro();
	
	printf("Informe o codigo para remocao: ");
	scanf("%s",&removeChar);
	
	while(topo->ant != NULL){
		if(strcmp(removeChar, topo->nome) == 0){
			topo=topo->ant;
			free(topo->prox);
			topo->prox=NULL;
			break;
		}
		else{
			topo=topo->ant;
			topoaux->prox=topo->prox;
			topo->prox->ant=topoaux;
			topoaux=topoaux->prox;
			topo->prox=NULL;
		}
	}
	
	while(topoaux->ant != NULL){
		topo->prox=topoaux;
		topoaux=topoaux->ant;
		topo->prox->ant=topo;
		topoaux->prox=NULL;
		topo=topo->prox;
	}
}

