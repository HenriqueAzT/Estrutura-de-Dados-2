#include <stdio.h>
#include <stdlib.h>
#define MAXN 13

typedef int TipoChave;

typedef struct TipoRegistro {
  TipoChave Chave;  
  char Nome[10];
  int Idade;  
} TipoRegistro;

typedef struct TipoCelula {
	TipoRegistro Registro;
    TipoRegistro* Prox;
}TipoCelula;

typedef struct TipoLista {
  int Qtde;
  TipoCelula* Primeiro;
} TipoLista;

typedef int TipoIndice;

typedef struct TipoTabela {
  TipoLista Item[MAXN]; 
} TipoTabela;

void Inicializa (TipoTabela *T);
TipoIndice Hash(TipoRegistro Reg);
void Insere(TipoRegistro Reg, TipoTabela* T);
void Imprime(TipoTabela *T);

