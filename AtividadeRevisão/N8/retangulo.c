#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"

void preenche(int *vet, int val){
	int a;
	
	vet = malloc(4 * sizeof(int));
	
	for(a = 0; a < 10; a++){
		*(vet + a) = val;
		printf("%d\n", *(vet + a));
	}
}




