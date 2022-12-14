#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ordenacao.h"


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
    
    printf("\n--------------------------------Acessar registro pela posicao------------------------------------------\n");
	acessarRegistro(5, &tabelaDeAlunos);
	printf("\n-------------------------------------------------------------------------------------------------------\n\n");
	
	printf("\n--------------------------------Verificar se esta em ordem crescente-----------------------------------\n");
	ListaTabela(&tabelaDeAlunos);
	verificarOrdem(&tabelaDeAlunos);
	printf("\n--------------------------------Retirar um registro----------------------------------------------------\n\n");
	ListaTabela(&tabelaDeAlunos);
	retirarRegistro(5, &tabelaDeAlunos);
	ListaTabela(&tabelaDeAlunos);
	printf("\n--------------------------------------------------------------------------------------------------------\n");
	

   
    
    return 0;
}
