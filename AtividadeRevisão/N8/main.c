#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"

int main(int argc, char *argv[]) {

	int vet[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};
	
	
	preenche(vet, 10);
	
	free(preenche);
	system("PAUSE");
	return 0;
}
