#define MAX_VERT 20
#include<stdbool.h>

typedef struct {
	char Nome[1];
} TipoRegistro;

typedef struct {
	int Ordem;
	TipoRegistro Item;
	int FoiVisitado;
} TipoVertice;

typedef struct {
	TipoVertice Reg[50];    
	int n;
} TipoPilha;

typedef struct {
	TipoVertice ListaVertices[MAX_VERT];   
	int MatrizAdj[MAX_VERT][MAX_VERT];
	TipoPilha Pilha;
	int n;
} TipoGrafo;

void CaminhoMaisCurto(TipoGrafo *grafo, int origem, int destino);
bool PassaEmTodos(TipoGrafo *grafo, int origem);
void testarTodosOsNos(TipoGrafo *grafo);
void InicializaGrafo (TipoGrafo *Grafo);  
void adicionaVertice(TipoGrafo *Grafo, TipoRegistro Reg);
void ListaGrafo(TipoGrafo* Grafo);
void adicionarAresta(TipoGrafo* Grafo, int inicio, int fim);
TipoVertice* AdjNaoVisitado(TipoGrafo* Grafo, TipoVertice* v);
void ArvoreGeradoraMinima(TipoGrafo* Grafo, int inicio, int fim);
int VerificaCaminho(TipoGrafo *Grafo, int X, int Y);
