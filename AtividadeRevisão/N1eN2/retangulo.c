#include <stdio.h>
#include <stdlib.h>
#include "Retangulo.h"

struct retangulo {
	float base;
	float altura;
};

Retangulo* cria_retangulo(float base, float altura) {	
	
	if ( (base <= 0) || (altura <= 0) ) 
		return NULL;
	
	Retangulo *p = (Retangulo*)malloc(sizeof(Retangulo));
	
	if (p == NULL)
		return NULL;	
	
	p->base = base;
	p->altura = altura;	
	return p;			
}

float obterBase(Retangulo* retangulo) {
	return retangulo->base;
}

int altera_retangulo(Retangulo* retangulo, 
	float base, float altura) {
		
	if ( (base <= 0) || (altura <= 0) ) 
		return 0;
		
	retangulo->base = base;
	retangulo->altura = altura;	
	return 1;		
}

void obterBase_e_altura(Retangulo* retangulo, float* base, float* altura) {		
	
	
	*base = retangulo->base;
	*altura = retangulo->altura;		
}

void destroi_retangulo(Retangulo* r1) {
	free(r1);
}

void area(Retangulo* r1, float base, float altura){
	
	printf("Area: %f\n", base * altura);
}

void operacoes (int a, int b, int *soma, int *subtracao){
	
	soma = a + b;
	subtracao = a - b;
	
	printf("Soma: %d\n", soma);
	printf("Subtracao: %d\n", subtracao);
}




