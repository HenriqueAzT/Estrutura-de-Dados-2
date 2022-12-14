#define MAXN 100
#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
    char Nome[10];
    int Idade;
} TipoRegistro;

typedef int TipoIndice;

typedef struct {
    TipoRegistro Item[MAXN + 1];
    TipoIndice n;
} TipoTabela;

void Inicializa (TipoTabela *T);
void Insere(TipoRegistro Reg, TipoTabela *T);
void ListaTabela(TipoTabela *T);
void insertionSort(TipoTabela *T);
void acessarRegistro(int num, TipoTabela *T);
void retirarRegistro(int num, TipoTabela *T);
void verificarOrdem(TipoTabela *T);
