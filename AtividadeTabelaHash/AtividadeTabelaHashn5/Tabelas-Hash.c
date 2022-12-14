#include "Tabelas-Hash.h"

void ListaTabela(TipoTabela *T) {  
	  printf("\n");
	  printf("%-4s %-8s %-8s %-15s %-10s %-10s\n", "#", "HASH", "CODIGO", "NOME", "CELULAR", "TELEFONE");
	  printf("---------------------------------------------------------------------------------\n");   
	  int i;
	  for(i=0; i<MAXN; i++) {   
	  
	  	if (T->Item[i].Chave == -2) 
	    	printf("%-4d %-8s %-8s %-15s %-8s\n", i, "*","*", "*", "*");
	    else if (T->Item[i].Chave != -1)
	      printf("%-4d %-6d %-10d %-15s %-10d %-10d\n", i, Hash(T->Item[i].Chave), T->Item[i].Chave, T->Item[i].Nome, T->Item[i].Celular, T->Item[i].Telefone);    
		else printf("%-4d %-8s %-8s %-15s %-8s\n", i, "", "", "", "");
  }
  printf("---------------------------------------------------------------------------------\n");
}

void Inicializa (TipoTabela *T) {  
	int i;
  T->n = 0;
  for (i=0; i<MAXN; i++) {
      TipoRegistro a = {-1, "", 0};
      T->Item[i] = a;
    }
}

TipoIndice Hash(TipoChave Chave) { 
  return (Chave % MAXN); 
} 


TipoIndice Insere(TipoRegistro Reg, TipoTabela *T) {     
  int sucesso = 0;
	
	if (T->n < MAXN) {
	  
	  TipoIndice i = Hash(Reg.Chave);
	 
	    while ( (T->Item[i].Chave != -1) && (T->Item[i].Chave != -2) ) {
 			i = (i+ 1) % MAXN;	
  		}	
	  
	    T->Item[i] = Reg;
	    T->n++;
	    sucesso = 1;
	  
	}

  return sucesso;
} 

TipoIndice Busca(TipoChave Chave, TipoTabela *T) {  
  TipoIndice i = Hash(Chave);
  
  int k = 0;
  
  while ( (T->Item[i].Chave != -1) && (T->Item[i].Chave != Chave) ) {
  		i = (i+1) % MAXN;
  		
  		if (++k > MAXN) 
  			break;
		  
  }
  
  return (T->Item[i].Chave == Chave) ? i : -1;  	
  
}

TipoIndice Exclui(TipoChave Chave, TipoTabela *T) {
  int sucesso = 0;
  TipoIndice indice = Busca(Chave, T);

   if (T->Item[indice].Chave == Chave) {    
     TipoRegistro a = {-2, "", 0};
    T->Item[indice] = a;
    T->n--;
    sucesso = 1;
  }

  return sucesso;
}
