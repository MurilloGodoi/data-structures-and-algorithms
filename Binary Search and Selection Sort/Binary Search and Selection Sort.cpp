#include <stdio.h>
#include <stdlib.h>

void selection_sort(int n, int v[]){
	for (int pos=0; pos<n; pos++){
		int menor = 1000000;
		int indicemenor;
		for (int i=pos; i<n; i++){
			if(v[i] < menor){
				menor = v[i];
				indicemenor = i;
			}
		}
		v[indicemenor] = v[pos];
		v[pos] = menor;
	}
}

void binary_search(int n, int v[], int val){
	int de=0; 
	int ate = n-1;											
	while(de < ate){
		int meio = (de + ate)/2;              								
		if (v[meio] < val){																			
			de = meio + 1;	
			if(v[de] == val){
				break;
			}												
		}												
		else if(v[meio] > val){								
			ate = meio - 1;	
			if(v[ate] == val){
				break;
			}												
		}													
		else{
			ate = meio;
			break;
		}
	}
	printf("Resultado da busca binaria:\n\n");
	if(v[ate] == val or v[de] == val){
		printf("Esse numero %d existe\n\n\n", val);
	}
	else{
		printf("o numero %d não existe\n\n\n",val);
	}
	
}
int main(){
	
	int n=15;
	int v[15] = {2,4,5,7,9,13,14,79,53,15,81,93,98,67,99};
	int val;
	
	selection_sort(n,v);
	
	printf("Resultado do selection sort:\n");
	for(int j=0; j<n; j++){
		printf("%d\n", v[j]);
	}	
	
	printf("Digite o numero a ser pesquisado usando binary search: ");
	scanf("%d", &val);
	
	binary_search(n,v,val);
}
