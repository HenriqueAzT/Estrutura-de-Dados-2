#include "Ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

void Inicializa (TipoTabela *T) {
    T->n = 0;
}

TipoIndice PesquisaSequencial(TipoChave x , TipoTabela *T) {
    int i ;
    
    T->Item[0].Chave = x;
    i = T->n + 1;
    
    do {
        i--;
    } while (T->Item[i].Chave != x);
    
    return i ;
}

void Insere(TipoRegistro Reg, TipoTabela *T) {
    if (T->n == MAXN)
        printf ("Erro: Tabela cheia\n");
    else {
        T->n++;
        T->Item[T->n] = Reg;
    }
}

TipoIndice PesquisaBinaria(TipoChave x , TipoTabela *T) {
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
        
        if (x == T->Item[i].Chave)
            return i ;
        else
            return 0;
    }
}

void ListaTabela(TipoTabela *T) {
    
    printf("\n");
    printf("%-8s %-15s %-8s\n", "CHAVE", "NOME", "IDADE");
    printf("------------------------------------\n");
    int i = 0;
    for(i=1; i<=T->n; i++) {
        printf("%-8d %-15s %-8d\n", T->Item[i].Chave, T->Item[i].Nome, T->Item[i].Idade);
    }
    printf("------------------------------------\n\n");
}

void insertionSort(TipoTabela *T) {
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


void busca(int vetor[], int n, int chave, int posicoes[]){
	int i;
	int var = 0;
	for(i=0; i < 10;i++){
		if (vetor[i] == n){
			var++;
			posicoes[i] = vetor[i];
			printf("ocorrencias: %d %d\n", var, posicoes[i]);
		}
	}
}












