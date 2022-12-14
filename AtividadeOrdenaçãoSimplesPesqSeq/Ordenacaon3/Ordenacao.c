#include <stdlib.h>
#include <stdio.h>
#include "Ordenacao.h"

typedef int TipoIndice;
struct Tabela {
    TipoRegistro Item[MAXN + 1];
    TipoIndice n;
};

TipoTabela CriaTabela() {
   TipoTabela T = (struct Tabela*) malloc(sizeof(struct Tabela));
    if (T != NULL) {
		T->n = 0;
	} 	
    return T;
}


int PesquisaSequencial(TipoChave x, TipoRegistro* Reg, TipoTabela T) {
    int i ;
    
    T->Item[0].Chave = x;
    i = T->n + 1;
    
    do {
        i--;
    } while (T->Item[i].Chave != x);
    
    (*Reg) = T->Item[i];
    
    return i;
}


void Insere(TipoTabela T, TipoRegistro Reg) {
    
	if (T->n == MAXN)
        printf("Erro: Tabela cheia\n");
    else {
        T->n++;
        T->Item[T->n] = Reg;
    }
}



int PesquisaBinaria(TipoChave x, TipoRegistro* Reg, TipoTabela T) {
    TipoIndice i , Esq, Dir ;
    
    if (T->n == 0)
        return 0;
    else {
        Esq = 1;
        Dir = T->n;
        do {
            
            i = (Esq + Dir ) / 2;
            
            if (x > T->Item[i].Chave)
                Esq = i + 1;
            else Dir = i - 1;
            
        } while (x != T->Item[i].Chave && Esq <= Dir );
        
        if (x == T->Item[i].Chave) {		            
			(*Reg) = T->Item[i];
			return i ;			
		}	
        else
            return 0;
    }
}

void ListaTabela(TipoTabela T) {
    int i;
    printf("\n");
    printf("%-8s %-15s %-8s\n", "CODIGO", "NOME", "CATEGORIA");
    printf("------------------------------------\n");
    for(i=1; i<=T->n; i++) {
        printf("%-8d %-15s %-8d\n", T->Item[i].Chave, T->Item[i].Nome, T->Item[i].Categoria);
    }
    printf("------------------------------------\n\n");
}

void insertionSort(TipoTabela T) {
    int i, j;
    TipoRegistro Key;
    
    for(i=1; i<=T->n; i++) {
        
        Key = T->Item[i];
        j = i-1;
        
        while (j >= 1 && T->Item[j].Chave > Key.Chave) {
            T->Item[j+1] = T->Item[j];
            j = j-1;
        }
        T->Item[j+1] = Key;
    }
}

void buscaVetor(int num, TipoTabela T){
	int pos=0;
	int i, j;
	int var=0;
	TipoRegistro key;
	for(i=1; i<=T->n; i++) {
        
        key = T->Item[i];
        j = i-1;
        pos++;
        while (j >= 1 && T->Item[j].Chave > key.Chave) {
            T->Item[j+1] = T->Item[j];
            j = j-1;
        }
        T->Item[j+1] = key;
        if(pos == num){
        	printf("Voce selecionou: \n-Cod: %d\n-Nome: %s\n-Categoria: %d\n", key.Chave, key.Nome, key.Categoria);
		}else{
			if(pos != num){
				var++;
			}
		}
		if(var==5){
			printf("Esse codigo não esta inserido na tabela!");
		}
    }
}












