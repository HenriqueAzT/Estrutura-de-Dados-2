#include <stdio.h>
#include <stdlib.h>
#include "Ordenacao.h"


int main(int argc, char *argv[]) {
        
    TipoTabela T = CriaTabela();
    
    TipoRegistro lista[5] = 
	{
		{1,"Maria", 21},
	    {2,"Pedro", 12},
	    {3,"Samara", 33},
	    {4,"Joao", 84},
	    {5,"Carla", 75}	    
	};
	    
    int i;
    for(i=0; i < 5; i++)
        Insere(T, lista[i]);
    
   	ListaTabela(T);   
	    
   	TipoRegistro Reg;
//   	if (PesquisaSequencial(8, &Reg, T)) {
//   		printf("Registro localizado: %s\n", Reg.Nome);
//	} else {
//		printf("Registro NAO localizado\n");
//	}
   	
   	insertionSort(T);
   	ListaTabela(T); 
	   
//	if (PesquisaBinaria(15, &Reg, T)) {
//   		printf("Registro localizado: %s\n", Reg.Nome);
//	} else {
//		printf("Registro NAO localizado\n");
//	}      
    buscaVetor(5, T);
	
    return 0;
}
