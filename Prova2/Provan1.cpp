#include <stdio.h>
#include <stdlib.h>


int f2(int vet[], int pos, int i){
	if (vet == 0){
		printf("ZERO");
	}
	else{
		if(i < 10){
			printf("%d ", vet[i]);
			i++;
			f2(vet, pos, i);
			if(pos == i){
				printf("\nO numero %d esta na posicao %d ", vet[i], i);
			}
		}else{
			return 0;
		}
	}
}


int main(){
	int vet[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
	f2(vet, 7, 0);
	return 0;
}
