#include <stdio.h>
#include <stdlib.h>


int tabelaHash(int vet[]){
	int i = 1, j=0, m=1;
	int chaves[6];
	int chave1, chave2, chave3, chave4, chave5;
	
	printf("\nCHAVES: %d %d %d %d %d\n", vet[i]%7, vet[i+1]%7, vet[i+2]%7, vet[i+3]%7, vet[i+4]%7);

	for(j; j<6; j++){
		chaves[j] = vet[i]%7;
		i++;
		if(chaves[m] == chaves[j]){
			printf("As chaves iguais sao: %d e %d\n", chaves[m], chaves[j]);
		}
	}	
}

int main(){
	int vet[6] = {24, 53, 68, 71, 19, 3};
	tabelaHash(vet);
	return 0;
}
