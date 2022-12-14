#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TipoChave;

typedef struct TipoRegistro {
  TipoChave Chave;    
} TipoRegistro;

typedef struct TipoNo* TipoApontador;

typedef struct TipoNo {
  TipoRegistro Registro;
  TipoApontador Esq, Dir;
} TipoNo;

typedef TipoApontador TipoDicionario;

void Inicializa(TipoDicionario *Dic);
TipoApontador* Localiza(TipoChave chave, TipoApontador *p);
TipoApontador* Insere(TipoRegistro x, TipoApontador *p);
void TravessiaEmOrdem(TipoApontador *p);
void TravessiaPosOrdem(TipoApontador *p);
void TravessiaPreOrdem(TipoApontador *p);
TipoApontador* Minimo(TipoApontador *p);
TipoApontador* Maximo(TipoApontador *p);
TipoApontador* Sucessor(TipoApontador *p);
TipoApontador* BuscaPai(TipoChave chave, TipoApontador *p); 
void Remove (TipoApontador *p, TipoDicionario *Dic);
void ImprimeDicionario(TipoApontador *p, const char* tipo);
int ImprimeNoEIrmao(TipoApontador* p, TipoDicionario *Dic);
