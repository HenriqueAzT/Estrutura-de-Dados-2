#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafos.h"

void InserirItensParaTeste(TipoGrafo* Grafo) {
	TipoRegistro a1 = {'A'};
	adicionaVertice(Grafo, a1);
	
	TipoRegistro a2 = {'B'};
	adicionaVertice(Grafo, a2);

	TipoRegistro a3 = {'C'};
	adicionaVertice(Grafo, a3);

	TipoRegistro a4 = {'D'};
	adicionaVertice(Grafo, a4);

	TipoRegistro a5 = {'E'};
	adicionaVertice(Grafo, a5);

	TipoRegistro a6 = {'F'};
	adicionaVertice(Grafo, a6);

	TipoRegistro a7 = {'G'};
	adicionaVertice(Grafo, a7);

	TipoRegistro a8 = {'H'};
	adicionaVertice(Grafo, a8);

	adicionarAresta(Grafo,2,0);					
	adicionarAresta(Grafo,7,1);
	adicionarAresta(Grafo,1,2);
	adicionarAresta(Grafo,7,2);
	adicionarAresta(Grafo,2,3);					
	adicionarAresta(Grafo,1,4);						
	adicionarAresta(Grafo,1,5);
	adicionarAresta(Grafo,3,5);
	adicionarAresta(Grafo,6,5);	
	adicionarAresta(Grafo,0,6);
	adicionarAresta(Grafo,1,6);
	adicionarAresta(Grafo,4,6);			
							
}

int main(int argc, char *argv[]) {
	int i, j;
	int caminho;
	TipoGrafo Grafo;	 
	InicializaGrafo(&Grafo);
	
	InserirItensParaTeste(&Grafo);	
		 	
 	ListaGrafo(&Grafo);
 	
 	caminho = VerificaCaminho(&Grafo, 1, 7);
 	if(caminho == 1){
 		printf("\nExiste um caminho!\n");
	}else{
		printf("\nNao Existe um caminho!\n");
	}
	return 0;
}

