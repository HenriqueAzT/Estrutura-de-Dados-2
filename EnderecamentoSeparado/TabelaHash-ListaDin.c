#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash-ListaDin.h"

void Inicializa (TipoTabela *T) { 
	int i;    
  for (i=0; i<MAXN; i++) {      
      T->Item[i].Qtde = 0;
      T->Item[i].Primeiro = NULL;
    }
}

TipoIndice Hash(TipoRegistro Reg) { 
  return (Reg.Chave % MAXN); 
} 

void Insere(TipoRegistro Reg, TipoTabela* T) {
  TipoIndice i = Hash(Reg);
 
  TipoCelula* item = (TipoCelula*) malloc (sizeof(TipoCelula));
  item->Registro = Reg;
  item->Prox = NULL;

  if (T->Item[i].Primeiro != NULL) {
    item->Prox = T->Item[i].Primeiro;
  } 
    
  T->Item[i].Primeiro = item;
  T->Item[i].Qtde++;
}


void Imprime(TipoTabela *T) {  
  int k, i;
  printf("\n    %-4s %-8s %-15s %-8s\n", "#", "CODIGO", "NOME", "IDADE");

  for(i=0; i<MAXN; i++) {
    
    printf("(%d)------------------------------------\n", i);

    TipoCelula* Aux;
    Aux = T->Item[i].Primeiro;  

    k = 0;
    while(Aux != NULL) {
      printf("    %-4d %-8d %-15s %-8d\n", ++k, Aux->Registro.Chave, Aux->Registro.Nome, Aux->Registro.Idade);
      Aux = Aux->Prox;
    }        
  }
  printf("\n");
}

