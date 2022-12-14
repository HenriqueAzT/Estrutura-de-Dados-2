#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"

void preenche(int **mat, int val){
	int i, j;
	
	mat = malloc(4 * sizeof(int));
	
	for(i = 0; i < 4; i++){
		mat[i] = malloc(3 * sizeof(int));
	}
	
	for(i = 0; i < 4; i++){
		for(j = 0; j < 3; j++){
			*(*(mat + i) + j) = 0;
		}
	}
	
	for(i = 0; i < 4; i++){
		for(j = 0; j < 3; j++){
			printf("%d ", *(*(mat + i) + j));
		}
		printf("\n");
	}
}




