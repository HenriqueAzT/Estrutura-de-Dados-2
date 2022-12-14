#include "Arvores-Binarias-de-Busca.h"

void Inicializa(TipoDicionario *Dic) {
  *Dic = NULL;
}

TipoApontador* Localiza(TipoChave chave, TipoApontador *p) {

  if ( (*p == NULL) || (chave == (*p)->Registro.Chave) ) {
    return p;
  }

  if (chave < (*p)->Registro.Chave) {
    Localiza(chave, &(*p)->Esq);    
  } 
  else {
    Localiza(chave, &(*p)->Dir);  
  } 

}

TipoApontador* Insere(TipoRegistro x, TipoApontador *p) {

  TipoApontador* a = Localiza(x.Chave, p);

  if (*a == NULL) {
    *a = (TipoApontador) malloc (sizeof(TipoNo));
    (*a)->Registro = x;
    (*a)->Esq = NULL;
    (*a)->Dir = NULL;      
    return a;  
  }
  else if (x.Chave == (*a)->Registro.Chave) {
    return NULL;
  }  
}

void TravessiaEmOrdem(TipoApontador *p) {  
  
  if (*p != NULL) {
    TravessiaEmOrdem(&(*p)->Esq);
    printf("------------------------------------\n");
    printf("%-8d\n", (*p)->Registro.Chave);
    TravessiaEmOrdem(&(*p)->Dir);  
  }

}

void TravessiaPosOrdem(TipoApontador *p) {  
  
  if (*p != NULL) {
    TravessiaPosOrdem(&(*p)->Esq);
    TravessiaPosOrdem(&(*p)->Dir);
    printf("------------------------------------\n");
    printf("%-8d\n", (*p)->Registro.Chave);  
  }

}

void TravessiaPreOrdem(TipoApontador *p){ 
	TipoApontador atual = *p;
	 
	int i = 0;
  	if (*p != NULL) {
    	if(atual->Esq != NULL && atual->Dir != NULL){
			i = 2;
		}else{
			if(atual->Esq != NULL || atual->Dir != NULL){
				i = 1;
			}else{
				i = 0;
			}
		}
//   getchar();

    	printf("------------------------------------\n");
    	printf("%-8d (GRAU: %d) \n", (*p)->Registro.Chave, i); 
	
    	TravessiaPreOrdem(&(*p)->Esq);
    	TravessiaPreOrdem(&(*p)->Dir);
	}
}


void ImprimeDicionario(TipoApontador *p, const char* tipo) {
 
  if (*p != NULL) {

 printf("\n%-8s\n", "CODIGO");
 
 if (!strcmp(tipo, "Em Ordem"))
  TravessiaEmOrdem(p);
 else if (!strcmp(tipo, "Pre-Ordem"))
  TravessiaPreOrdem(p);
 else
  TravessiaPosOrdem(p);
} else {
  printf("------------------------------------\n");
  printf("A tabela esta vazia!\n");
  printf("------------------------------------\n");
}

}

TipoApontador* Minimo(TipoApontador *p) {

  if ((*p)->Esq == NULL)
    return p;  
  else Minimo(&(*p)->Esq);

}

TipoApontador* Maximo(TipoApontador *p) {

  if ((*p)->Dir == NULL)
    return p;  
  else Maximo(&(*p)->Dir);

}

TipoApontador* Sucessor(TipoApontador *p) {

  TipoApontador* a = p;
  TipoApontador* s = &(*a)->Dir;

  if (*s == NULL)
    return NULL;

  while(*s != NULL) {
    a = s;
    s = &(*s)->Esq;
  }

  return a;

}

TipoApontador* BuscaPai(TipoChave chave, TipoApontador *p) {

  if ( (*p == NULL) || ( ((*p)->Esq != NULL) && 
      (chave == (*p)->Esq->Registro.Chave) ) || 
      ( ((*p)->Dir != NULL) && (chave == (*p)->Dir->Registro.Chave) ) 
    ) {
    return p;
  }

  if (chave < (*p)->Registro.Chave) {
    BuscaPai(chave, &(*p)->Esq);    
  } 
  else {
    BuscaPai(chave, &(*p)->Dir);  
  } 

}

int ImprimeNoEIrmao(TipoApontador* p, TipoDicionario *Dic){
	TipoApontador atual = *p;
	TipoApontador* pai = BuscaPai((*p)->Registro.Chave, Dic);
//	if(((*pai)->Esq != (*p)->Registro.Chave) && ((*pai)->Esq != 0)){
//		return pai->Esq;
//	}
}

void RemoveNoFolha(TipoApontador *p, TipoApontador *pai) {

  TipoApontador atual = *p;
  TipoApontador paiAtual = *pai;

  if (paiAtual != NULL) {
    if ( (paiAtual->Esq != NULL) && 
       ( paiAtual->Esq->Registro.Chave == atual->Registro.Chave) ) {
        paiAtual->Esq = NULL;
    }
    else {
      paiAtual->Dir = NULL;
    }
  } else {
    *p = NULL;
  }

  free(atual); 

}

void RemoveNoComUmFilho(TipoApontador *p, TipoApontador *pai) {

  TipoApontador atual = *p;
  TipoApontador paiAtual = *pai;
  TipoApontador filho = (atual->Esq != NULL) ? atual->Esq : atual->Dir;
  TipoApontador aux;
  
  if (paiAtual != NULL) {
    if ( (paiAtual->Esq != NULL) && 
       ( paiAtual->Esq->Registro.Chave == atual->Registro.Chave) ) {      
      paiAtual->Esq = filho;
    }
    else {
      paiAtual->Dir = filho;
    }

    aux = atual;

  } else {
    *atual = *filho; 
    aux = filho;
  }

  free(aux);

}

void RemoveOndeSucessorPossuiFilho(TipoApontador *p, TipoApontador *s, 
     TipoApontador *pai, TipoApontador *paiSc) {

  TipoApontador atual = *p;
  TipoApontador sucessor = *s;
  TipoApontador paiAtual = *pai;
  TipoApontador paiSucessor = *paiSc;

  bool menor = (sucessor->Registro.Chave < paiAtual->Registro.Chave);

  if (menor) {
    paiAtual->Esq = sucessor;    
  } else {
    paiAtual->Dir = sucessor;         
  }

  if (atual != paiSucessor) {

    paiSucessor->Esq = sucessor->Dir;
    sucessor->Dir = atual->Dir;
    sucessor->Esq = atual->Esq;  

  } 

  free(atual);

}

void RemoveOndeSucessorSemFilho(TipoApontador* p, TipoApontador* s, 
    TipoApontador* pai, TipoApontador* paiSc) {

  TipoApontador atual = *p;
  TipoApontador sucessor = *s;
  TipoApontador paiAtual = *pai;
  TipoApontador paiSucessor = *paiSc;
  TipoApontador aux;

  if (sucessor == paiSucessor->Esq) {
    paiSucessor->Esq = NULL;
  } else {
    paiSucessor->Dir = NULL;
  }

  sucessor->Dir = atual->Dir;
  sucessor->Esq = atual->Esq;   

  if (paiAtual != NULL) {

    if (atual->Registro.Chave > paiAtual->Registro.Chave) {
      paiAtual->Dir = sucessor;
    } else {
      paiAtual->Esq = sucessor;
    }    

    aux = atual;

  } else {
    
   *atual = *sucessor; 
    aux = sucessor;

  }

  free(aux);
  
}

void Remove (TipoApontador *p, TipoDicionario *Dic) {

  TipoApontador* pai = BuscaPai((*p)->Registro.Chave, Dic);

  if ( ((*p)->Esq == NULL) && ((*p)->Dir == NULL) ) {
    RemoveNoFolha(p, pai);
  } 
  else if ( ((*p)->Esq != NULL) && ((*p)->Dir != NULL) ) {

    TipoApontador* s = Sucessor(p);
    TipoApontador* paiSucessor = BuscaPai((*s)->Registro.Chave, Dic);
    
    if ((*s)->Dir == NULL && (*s)->Esq == NULL) {
       RemoveOndeSucessorSemFilho(p, s, pai, paiSucessor); 
    }  
    else {
      RemoveOndeSucessorPossuiFilho(p, s, pai, paiSucessor);
    }      

  } else {
    RemoveNoComUmFilho(p, pai);   
  }   

}
