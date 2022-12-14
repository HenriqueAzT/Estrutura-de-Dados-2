#include <stdlib.h>
#include "retangulo.h"

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

void obterBase_e_altura(Retangulo* retangulo, 
	float* base, float* altura) {		
	*base = retangulo->base;
	*altura = retangulo->altura;		
}

void destroi_retangulo(Retangulo* r1) {
	free(r1);
}
void soma(float a, float b){
	printf("A soma de %0.2f com %0.2f e %0.2f", a, b, a+b);
}




