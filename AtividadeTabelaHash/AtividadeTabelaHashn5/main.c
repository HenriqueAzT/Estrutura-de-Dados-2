#include <stdio.h>
#include <stdlib.h>
#include "Tabelas-Hash.h"

void CargaInicialParaTeste(TipoTabela *T) {
  TipoRegistro a1 = {84846523, "Renan", 32452458, 62452458};
  Insere(a1, T);

  TipoRegistro a2 = {98745912, "Maria", 32474558, 72474558};
  Insere(a2, T);  

  TipoRegistro a3 = {23168546, "Carla", 64752458, 34752458};
  Insere(a3, T);

  TipoRegistro a4 = {74621223, "Pedro", 89452456, 59452456};
  Insere(a4, T);
  
  TipoRegistro a5 = {78943253, "Thalita", 68452458, 78452458};
  Insere(a5, T);
  
  TipoRegistro a6 = {84645132, "Mario", 32455558, 12455558};
  Insere(a6, T);
  
  TipoRegistro a7 = {98765412, "Rosana", 12442468, 22442468};
  Insere(a7, T);
  
  TipoRegistro a9 = {96668514, "Ana", 32472458, 62472458};
  Insere(a9, T);  
}

int LerOpcaoMenu() {
  int opcao;
    
  printf("\n1: Listar\n");
  printf("2: Pesquisar\n");
  printf("3: Inserir\n");
  printf("4: Remover\n");

  printf("Escolha uma opcao, ou -1 para sair: ");
  scanf("%d", &opcao);
  return opcao;

}

void OpcaoInserirRegistro(TipoTabela *T) {
  TipoRegistro a;
  
  printf("Digite a Chave: ");
  scanf("%d", &a.Chave);

  printf("Digite o Nome: ");
  scanf("%s", a.Nome);

  printf("Digite seu Celular: ");
  scanf("%d", &a.Celular);
  
  printf("Digite seu Telefone: ");
  scanf("%d", &a.Telefone);

  printf("\n------------------------------------\n");
  
  if (Insere(a, T))
    printf("O registro foi inserido com sucesso.");
  else
    printf("Nao foi possivel inserir o registro.");
  
  printf("\n------------------------------------");

  getchar();
  getchar();

}

void OpcaoPesquisarRegistro(TipoTabela *T) {
  TipoChave chaveDePesquisa;
  printf("Digite a chave de pesquisa: ");
  scanf("%d", &chaveDePesquisa);

  TipoIndice indice = Busca(chaveDePesquisa, T);

  if (T->Item[indice].Chave == chaveDePesquisa) {
    printf("\n------------------------------------\n");
    printf("Registro Encontrado:\n");
    printf("Chave: %d\nNome: %s\nCelular: %d\nTelefone: %d", T->Item[indice].Chave, T->Item[indice].Nome, T->Item[indice].Celular, T->Item[indice].Telefone);
    printf("\n------------------------------------");       
  } else {
    printf("\n---------------------------------------------------------\n");
    printf("Nao foi encontrado nenhum registro com a chave informada.");
    printf("\n---------------------------------------------------------");  
  }
  getchar(); getchar();  

}

int OpcaoExcluirRegistro(TipoTabela *T) {  
  TipoChave chaveDePesquisa;

  printf("Digite a chave de pesquisa: ");
  scanf("%d", &chaveDePesquisa);

  int sucesso = Exclui(chaveDePesquisa, T);

  if (sucesso) {
    printf("\n------------------------------------\n");
    printf("O Registro foi Excluido.");   
    printf("\n------------------------------------");       
  } else {
    printf("\n---------------------------------------------------------\n");
    printf("Nao foi encontrado nenhum registro com a chave informada.");
    printf("\n---------------------------------------------------------");  
  }
  getchar(); getchar(); 
}

int main(int argc, char *argv[]) {
	
	TipoTabela tabelaDeAlunos;  
  	int opcao;

	Inicializa(&tabelaDeAlunos);
    
	CargaInicialParaTeste(&tabelaDeAlunos);

	do {
	 opcao = LerOpcaoMenu();
	
	    switch(opcao) {    
	     case 2: OpcaoPesquisarRegistro(&tabelaDeAlunos); break;   
	     case 3: OpcaoInserirRegistro(&tabelaDeAlunos); break;
	     case 4: OpcaoExcluirRegistro(&tabelaDeAlunos); break;
	     default: ListaTabela(&tabelaDeAlunos);  
	    }
	
	} while (opcao != -1);
  
	return 0;
}
