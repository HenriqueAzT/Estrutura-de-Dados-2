#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash-ListaDin.h"

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

void CargaInicialParaTeste(TipoTabela *T) {
  TipoRegistro a1 = {49, "Renan", 32};
  Insere(a1, T);

  TipoRegistro a2 = {53, "Maria", 65};
  Insere(a2, T);  

  /*
  * Colisão. 
  */
  TipoRegistro a3 = {23, "Carla", 18};
  Insere(a3, T);

  TipoRegistro a4 = {19, "Pedro", 25};
  Insere(a4, T);
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
  
  Insere(a, T);
  printf("O registro foi inserido com sucesso.");
  
  
  printf("\n------------------------------------");

  getchar();
  getchar();

}

int main(int argc, char *argv[]) {
	int opcao;
	TipoTabela Tabela;

	Inicializa(&Tabela);
	CargaInicialParaTeste(&Tabela); 

	do {
	    opcao = LerOpcaoMenu();
	
	    switch(opcao) {    
		//  case 2: OpcaoPesquisarRegistro(&Tabela); break; // Tarefa: implementar
	     case 3: OpcaoInserirRegistro(&Tabela); break;
	   	//  case 4: OpcaoExcluirRegistro(&Tabela); break; // Tarefa: implementar
	     default: Imprime(&Tabela);  
	    }
	
	} while (opcao != -1);  

	return 0;
}

