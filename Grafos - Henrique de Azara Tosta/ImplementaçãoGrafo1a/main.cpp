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
	
 	TipoRegistro a9 = {'I'};
	adicionaVertice(Grafo, a9);
	
	TipoRegistro a10 = {'J'};
	adicionaVertice(Grafo, a10);
	
	
	adicionarAresta(Grafo, 0, 1);	 	
	adicionarAresta(Grafo, 0, 2);
	adicionarAresta(Grafo, 0, 5);
	adicionarAresta(Grafo, 1, 6);
	adicionarAresta(Grafo, 2, 7);
	adicionarAresta(Grafo, 3, 4);
	adicionarAresta(Grafo, 3, 8);
	adicionarAresta(Grafo, 4, 9);
	adicionarAresta(Grafo, 5, 9);
	adicionarAresta(Grafo, 6, 9);
	adicionarAresta(Grafo, 7, 8);
	
}

int main(int argc, char *argv[]) {
	
	TipoGrafo Grafo;	 
	InicializaGrafo(&Grafo);
	
	InserirItensParaTeste(&Grafo);	
		 	
 	ListaGrafo(&Grafo);
 	
 	ArvoreGeradoraMinima(&Grafo, 0);
 	ArvoreGeradoraMinima(&Grafo, 8);
	return 0;
}


