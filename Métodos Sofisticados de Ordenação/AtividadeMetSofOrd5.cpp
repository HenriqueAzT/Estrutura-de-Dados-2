#include <stdio.h>
#define max 13

void peneira(int *vet, int raiz, int fundo);

void heapsort(int *vet, int n) {
	int i, tmp;
	
	for (i = (n / 2); i >= 0; i--) {
		peneira(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		peneira(vet, 0, i-1);
	}
}

void peneira(int *vet, int raiz, int fundo) {
	int pronto, filhoMax, tmp, i;

	pronto = 0;
	
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
			for (i = 0; i < max; i++) {
				printf("%d ", vet[i]);
			}
			printf("\n");
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}
		if (vet[raiz] < vet[filhoMax]) {
			tmp = vet[raiz];
			vet[raiz] = vet[filhoMax];
			vet[filhoMax] = tmp;
			raiz = filhoMax;
	    }
		else {
	      pronto = 1;
		}
   }
}

int main() {
	int vetor[max] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4};
	int i;
	heapsort(vetor,max);
	printf("\nVersao final: \n");
	for (i = 0; i < max; i++) {
		printf("%d ", vetor[i]);
	}
	return(0);
}
