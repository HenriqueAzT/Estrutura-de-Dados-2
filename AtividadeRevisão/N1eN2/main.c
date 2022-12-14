#include <stdio.h>
#include <stdlib.h>
#include "Retangulo.h"

int main(int argc, char *argv[]) {
	
	
	int* soma;
	int* subtracao;
	Retangulo* r1 = cria_retangulo(9, 6);
//	Retangulo* r2 = cria_retangulo(78, 32);
//	
//	if (r1 != NULL) {
//		printf("Base: %f\n", obterBase(r1));		
//		
//		if (altera_retangulo(r1, 5, -8))
//			printf("Base: %f\n", obterBase(r1));
//		else
//			printf("ERRO AO ALTERAR!!!\n");		
//	}
//	else {
//		printf("ERRO AO CRIAR!!!\n");
//	}	
//	
//	if (r2 != NULL) {
//		float b, a;
//		obterBase_e_altura(r2, &b, &a);
//		printf("%f %f\n", b, a);
//	}
	area(r1, 5, 4);
	
	
	operacoes(5, 3, soma, subtracao);
	
		
	destroi_retangulo(r1);
	return 0;
}
