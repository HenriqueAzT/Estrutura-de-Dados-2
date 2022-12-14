#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"

void preenche(int *i, int val){
	int a;
	for(a = 0; a < 10; a++){
		*(i + a) = val;
		printf("%d\n", *(i + a));
	}
}




