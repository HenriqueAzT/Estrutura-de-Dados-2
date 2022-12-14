#include <stdio.h>
#include <stdlib.h>
#include "Ordenacao.h"
#define TAM 10

int main(int argc, char *argv[]) {
        
    TipoTabela T = CriaTabela();
    
    TipoRegistro lista[5] = 
	{
		{10,"Maria", 32},
	    {31,"Pedro", 21},
	    {8,"Samara", 15},
	    {15,"Joao", 41},
	    {4,"Carla", 27}	    
	};
	      
    int vetor[TAM] = {1,2,3,4,5,6,7,8,9,10};
    
	bubble_sort(vetor, 4);
	
	printf("\n----------------------------------------------------------\n");
	
	ordenacaoPorSelecao(vetor, 6);
	
    return 0;
}
