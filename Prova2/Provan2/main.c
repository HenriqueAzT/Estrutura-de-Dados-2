#include <stdio.h>
#include <stdlib.h>
#include "Tabelas-Hash.h"

void CargaInicialParaTeste(TipoTabela *T) {
  
  
  TipoRegistro a1 = {23, "Carla", 18};
  Insere(a1, T);

  TipoRegistro a2 = {47, "Maria", 65};
  Insere(a2, T);  

  TipoRegistro a3 = {49, "Renan", 51};
  Insere(a3, T);

  TipoRegistro a4 = {57, "Pedro", 25};
  Insere(a4, T);
  
  TipoRegistro a10 = {39, "Cida", 33};
  Insere(a10, T);
  
  TipoRegistro a11 = {21, "Mario", 50};
  Insere(a11, T);
      
  TipoRegistro a5 = {19, "XXXXXXX", 0};  
  Insere(a5, T);
  Exclui(19, T);

  TipoRegistro a6 = {5, "XXXXXXX", 0};   	
  Insere(a6, T);
  Exclui(5, T);
  
  TipoRegistro a17 = {72, "Samara", 11};
  Insere(a17, T);
  
  TipoRegistro a13 = {52, "Luana", 30};
  Insere(a13, T);
  
  TipoRegistro a14 = {75, "Ricardo", 21};
  Insere(a14, T);
  
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

  printf("Digite a Idade: ");
  scanf("%d", &a.Idade);

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
    printf("Chave: %d\nNome: %s\nIdade: %d", T->Item[indice].Chave, T->Item[indice].Nome, T->Item[indice].Idade);
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
	
	}while (opcao != -1);
  
	return 0;
}
