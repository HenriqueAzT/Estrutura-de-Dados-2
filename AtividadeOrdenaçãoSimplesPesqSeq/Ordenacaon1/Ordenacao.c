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

void acessarRegistro(int num, TipoTabela *T){
	TipoRegistro Key;
	TipoRegistro var;
	int i = 0;
	int j = 0;
	int pos = 0;
	for(i=1; i<=T->n; i++) {
        
        Key = T->Item[i];
        j = i-1;
        pos++;
        while (j >= 1 && T->Item[j].Chave > Key.Chave) {
            T->Item[j+1] = T->Item[j];
            j = j-1;
        }
        
        T->Item[j+1] = Key;
        if(num == pos){
        	printf("Voce Selecionou o(a): %s, que tem %d anos \n", T->Item[j + 1].Nome, T->Item[j + 1].Idade );
		}
    }
}
void retirarRegistro(int num, TipoTabela *T){
	TipoRegistro Key;
	TipoRegistro var;
	int i = 0;
	int j = 0;
	int pos = 0;
	int nulo = 0;
	for(i=1; i<=T->n; i++) {
        
        Key = T->Item[i];
        j = i-1;
        pos++;
        while (j >= 1 && T->Item[j].Chave > Key.Chave) {
            T->Item[j+1] = T->Item[j];
            j = j-1;
        }
        
        T->Item[j+1] = Key;
        if(num == pos){
        	printf("\nVoce Excluiu o(a): %s, que tem %d anos \n", T->Item[j + 1].Nome, T->Item[j + 1].Idade );
        	T->Item[j+1] = var;
        	T->Item[j+1].Chave = 0;
		}
    }
}
void verificarOrdem(TipoTabela *T){
	TipoRegistro Key;
	int i = 0;
	int j = 0;
	for(i=1; i<=T->n; i++) {
        
        Key = T->Item[i];
        j = i-1;
        
        while (j >= 1 && T->Item[j].Chave > Key.Chave) {
            T->Item[j+1] = T->Item[j];
            j = j-1;
        }
        
        T->Item[j+1] = Key;
        if(T->Item[j+1].Chave <= T->Item[j+2].Chave  && T->Item[j+2].Chave <= T->Item[j+3].Chave 
		&& T->Item[j+3].Chave <= T->Item[j+4].Chave && T->Item[j+4].Chave <= T->Item[j+5].Chave){
			printf("A Lista esta em ordem crescente");
			return;
		}else{
			printf("A lista nao esta em ordem crescente");
			return;
		}
	}
	
}









