#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "Grafos.h"


void InicializaPilha (TipoPilha *Pilha) {   
  Pilha->n = 0;
}

void ImprimeVertice(TipoVertice *v){
	printf("%s ",v->Item.Nome);
}

void ListaPilha(TipoPilha* Pilha) {
	int i;
	for(i = Pilha->n-1; i >=0; i--) {
	    ImprimeVertice(&(Pilha->Reg[i]));		
	}
}

int PilhaVazia(TipoPilha* Pilha) {
	if (Pilha->n > 0) 
		return 0;
	else return 1;	
}

void Empilha(TipoPilha* Pilha, TipoVertice* v) {
	Pilha->Reg[Pilha->n] = *v;	
	Pilha->n++;	
}

TipoVertice* Desempilha(TipoPilha* Pilha) {
	TipoVertice* reg = NULL;
	if (Pilha->n > 0) {
		Pilha->n--;
		reg = &Pilha->Reg[Pilha->n];
	}
	return reg;
}

TipoVertice* VerTopo(TipoPilha* Pilha) {
	TipoVertice* reg = NULL;
	if (Pilha->n > 0) {
		reg = &Pilha->Reg[Pilha->n-1];
	}
	return reg;
}

void InicializaGrafo (TipoGrafo *Grafo) {   
  InicializaPilha(&(Grafo->Pilha));
  Grafo->n = 0;  
  	int i, j;
	for(i=0; i<MAX_VERT; i++) {
		for(j=0; j<MAX_VERT; j++) {
			Grafo->MatrizAdj[i][j] = 0;
		}
	}	  
}

void adicionaVertice(TipoGrafo *Grafo, TipoRegistro Reg) {
	
	TipoVertice v;
	v.Ordem = Grafo->n;
	v.Item = Reg;
	v.FoiVisitado = 0;
	
	Grafo->ListaVertices[Grafo->n] = v;
	Grafo->n++;
}

void ListaGrafo(TipoGrafo* Grafo) {
	int i, j;
	printf("\nGRAFO\n   ");	
	for(i=0; i < Grafo->n; i++) {
	    ImprimeVertice(&(Grafo->ListaVertices[i]));
	}
	printf("\n----------------------------------------------------------------------------\n");
	
	printf("%-3s", "");
	for(i=0; i<Grafo->n; i++) {
		printf("%-3d", Grafo->ListaVertices[i].Ordem);
	}
	printf("\n");
	
	for(i=0; i<Grafo->n; i++) {
		printf("%-3d", Grafo->ListaVertices[i].Ordem);
		for(j=0; j<Grafo->n; j++) {
			printf("%-3d", Grafo->MatrizAdj[i][j]);
		}
		printf("\n");
	}
	
}

void adicionarAresta(TipoGrafo* Grafo, int inicio, int fim) {
	Grafo->MatrizAdj[inicio][fim] = 1;
}

TipoVertice* AdjNaoVisitado(TipoGrafo* Grafo, TipoVertice* v) {
	int j;
	for(j=0; j<Grafo->n; j++) {
		if ( (Grafo->MatrizAdj[v->Ordem][j] == 1) && (Grafo->ListaVertices[j].FoiVisitado == 0) ) {
			return &(Grafo->ListaVertices[j]);
		}
	}
	
	return NULL;
}

void ZerarFlagsVisitado(TipoGrafo* Grafo) {
	int j;
	for(j=0; j<Grafo->n; j++) {
		Grafo->ListaVertices[j].FoiVisitado = 0;		
	}
}

bool verificarTodosVisitados(TipoGrafo* Grafo){
	int j;
	for(j=0; j<Grafo->n; j++) {
		if (Grafo->ListaVertices[j].FoiVisitado == 0)
			return false;	
	}
	return true;
}

void ArvoreGeradoraMinima(TipoGrafo* Grafo, int inicio, int fim) {

	
	TipoVertice* vInicio = &(Grafo->ListaVertices[inicio]);
	printf("\nMinimo de arestas: Inicio em ");
	ImprimeVertice(vInicio);
	
	vInicio->FoiVisitado = 1;
	printf("\n(");
	ImprimeVertice(vInicio);
	Empilha(&(Grafo->Pilha), vInicio);
		
	while(!PilhaVazia(&(Grafo->Pilha))) {
		
		TipoVertice *topo = VerTopo(&(Grafo->Pilha));			
		TipoVertice *v = AdjNaoVisitado(Grafo, topo);
		if (v == NULL) {
		 	Desempilha(&(Grafo->Pilha));
		} else {
			v->FoiVisitado = 1;
			ImprimeVertice(v);
			printf("\b\b) (");
			ImprimeVertice(v);
			Empilha(&(Grafo->Pilha), v);
		}		
	}
	printf("\b\b\b\b    ");
	if (verificarTodosVisitados(Grafo)) {
		printf("Todos os nos foram visitados a partir de ");
	} else {
		printf("N�o foi possivel visitar todos os nos a partir de ");
	}
	ImprimeVertice(vInicio);
	ZerarFlagsVisitado(Grafo);
	 
}

void testarTodosOsNos(TipoGrafo *grafo){
	int i;
	for (i=0; i < grafo->n; i++){
		if (PassaEmTodos(grafo, i)){
			printf("\nTodos os nos sao alcancaveis a partir de ");
		}
		else{
			printf("\nNao eh possivel chegar em todos os nos a partir de ");
		}
		ImprimeVertice(&(grafo->ListaVertices[i]));
	}
}

bool PassaEmTodos(TipoGrafo *grafo, int origem){
	int i;
	for (i=0; i < grafo->n; i++){
		if (!CaminhoMaisCurto(grafo, origem, i))
			return false;
		else
			return true;
	}
}

bool CaminhoMaisCurto(TipoGrafo *grafo, int origem, int destino)
{
    int i, vert,k, NovaDist, min;
    int *M, *L, *A, *caminho;
    M = (int *)malloc(grafo->n * sizeof(int));
    L = (int *)malloc(grafo->n * sizeof(int));
    A = (int *)malloc(grafo->n * sizeof(int));
    caminho = (int *)malloc(grafo->n * 3 * sizeof(int));
    for (i=0; i < grafo->n; i++)
    {
        M[i] = 0;
        A[i] = -1;
        L[i] = 300000;
    }
    vert = origem;
    L[vert] = 0;
    while (vert != destino && vert != -1)
    {
        for(i=0; i<grafo->n ; i++)
            if (grafo->MatrizAdj[vert][i] != 0 && M[i]==0)
            {
                NovaDist = L[vert] + grafo->MatrizAdj[vert][i];
                if (NovaDist < L[i])
                {
                    L[i] = NovaDist;
                    A[i] = vert;
                }
            }
            M[vert] = 1;
            min = 300000;
            vert = -1;
            for (i=0; i<grafo->n; i++)
                if (M[i]==0 && L[i] < min)
                {
                    min = L[i];
                    vert = i;
                }
    }
    if (vert == destino)
    {
		return true;
    }
    else return false;
}

