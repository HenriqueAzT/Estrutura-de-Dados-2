#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ordenacao.h"
#define TAM 10

int main(int argc, char *argv[]) {
	
	 
    
    TipoTabela tabelaDeAlunos;
    TipoChave chaveDePesquisa;
    TipoIndice indice;
    
    Inicializa(&tabelaDeAlunos);
    
    TipoRegistro a1, a2, a3, a4, a5;
    
    a1.Chave = 10; a1.Idade = 32; strcpy(a1.Nome, "Maria");
    Insere(a1, &tabelaDeAlunos);
    
    a2.Chave = 31; a2.Idade = 21; strcpy(a2.Nome, "Pedro");
    Insere(a2, &tabelaDeAlunos);
    
    a3.Chave = 8; a3.Idade = 15; strcpy(a3.Nome, "Samara");
    Insere(a3, &tabelaDeAlunos);
    
    a4.Chave = 15; a4.Idade = 41; strcpy(a4.Nome, "Joao");
    Insere(a4, &tabelaDeAlunos);
    
    a5.Chave = 4; a5.Idade = 27; strcpy(a5.Nome, "Carla");
    Insere(a5, &tabelaDeAlunos);

    ListaTabela(&tabelaDeAlunos);    
    insertionSort(&tabelaDeAlunos);
    ListaTabela(&tabelaDeAlunos);
    
    
    int posicoes[TAM];
    
    int vetor[TAM] = {17, 42, 9, 33, 12, 33, 17, 9, 42, 33};
    
    busca(vetor, 33, 2, &posicoes[TAM]);
   
	

   
    
    return 0;
}
