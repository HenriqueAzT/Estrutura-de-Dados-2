#include <stdio.h>
#include "Arvores-Binarias-de-Busca.h"


void OpcaoMostrarMinimo(TipoApontador *p) {
  
  TipoApontador* a = Minimo(p);
  
  printf("\n%-8s\n", "CODIGO");
  printf("------------------------------------\n");  
  if (*a != NULL)
    printf("%-8d\n", (*a)->Registro.Chave);  
  else
    printf("O dicionario esta vazio!");
  printf("------------------------------------\n");

}

void OpcaoSucessor(TipoDicionario *Dic) {
  TipoChave a;

  printf("Digite a Chave: ");
  scanf("%d", &a);


  TipoApontador* p = Localiza(a, Dic);

  printf("\n------------------------------------\n");

  if (*p != NULL) {   

    TipoApontador* q = Sucessor(p);
    
    if (q != NULL) {
        printf("%-8s\n", "CODIGO");
        printf("%-8d\n", (*q)->Registro.Chave); 
    } 
    else
       printf("Nao existe sucessor!\n");

        
  } else {
    printf("O registro nao foi encontrado!\n");
  }
  
  printf("------------------------------------");

}

void OpcaoMostrarMaximo(TipoApontador *p) {
  
  TipoApontador* a = Maximo(p);
  
  printf("\n%-8s\n", "CODIGO");
  printf("------------------------------------\n");
  if (*a != NULL)
    printf("%-8d\n", (*a)->Registro.Chave);  
  else
    printf("A tabela esta vazia!");
  printf("------------------------------------\n");

}

void CargaInicialParaTeste(TipoDicionario *Dic) { 

  TipoRegistro a1 = {41};
  Insere(a1, Dic);

  TipoRegistro a2 = {1};
  Insere(a2, Dic);

  TipoRegistro a3 = {0};
  Insere(a3, Dic);

  TipoRegistro a4 = {38};
  Insere(a4, Dic);

  TipoRegistro a5 = {36};
  Insere(a5, Dic);

  TipoRegistro a6 = {10};
  Insere(a6, Dic);

  TipoRegistro a7 = {37};
  Insere(a7, Dic);

  TipoRegistro a8 = {40};
  Insere(a8, Dic);

  TipoRegistro a9 = {71};
  Insere(a9, Dic);

  TipoRegistro a10 = {44};
  Insere(a10, Dic);

  TipoRegistro a11 = {43};
  Insere(a11, Dic);

  TipoRegistro a12 = {51};
  Insere(a12, Dic);

  TipoRegistro a13 = {50};
  Insere(a13, Dic);

  TipoRegistro a14 = {57};
  Insere(a14, Dic);

  TipoRegistro a15 = {76};
  Insere(a15, Dic);

  TipoRegistro a16 = {73};
  Insere(a16, Dic);

  TipoRegistro a18 = {72};
  Insere(a18, Dic);

  TipoRegistro a19 = {83};
  Insere(a19, Dic);

  TipoRegistro a20 = {80};
  Insere(a20, Dic);
 
  TipoRegistro a22 = {97};
  Insere(a22, Dic);
}

int LerOpcaoMenu() {
  int opcao;
 
  printf("\n1: Pesquisar\n");
  printf("2: Inserir\n");
  printf("3: Remover\n");
  printf("4: Listar: Em Ordem\n");
  printf("5: Listar: Pre-Ordem\n");
  printf("6: Listar: Pos-Ordem\n");
  printf("7: Mostrar Valor Minimo\n");
  printf("8: Mostrar Valor Maximo\n");
  printf("9: Busca Pai\n");
  printf("10: Sucessor\n");
  printf("11: Imprimir Nos Nao Folha\n");
  printf("12: Imprimir Todos os Nos\n");
  printf("13: Verifica se Binaria\n");

  printf("Escolha uma opcao, ou -1 para sair: ");
  scanf("%d", &opcao);
  return opcao;

}

void OpcaoInserirRegistro(TipoDicionario *Dic) {
  TipoRegistro a;
  
  printf("Digite a Chave: ");
  scanf("%d", &a.Chave);


  printf("\n------------------------------------\n");
  
  TipoApontador* p = Insere(a, Dic);

  if (*p != NULL) 
    printf("O registro foi inserido com sucesso.");
  else
    printf("O registro não foi inserido. \nA chave informada ja existe.");  
  
  printf("\n------------------------------------"); 

}

void OpcaoRemoverRegistro(TipoDicionario *Dic) {
  TipoChave a;

  printf("Digite a Chave: ");
  scanf("%d", &a);


  TipoApontador* p = Localiza(a, Dic);

  printf("\n------------------------------------\n");

  if (*p != NULL) {   

    Remove(p, Dic);
    printf("O registro foi removido.\n");    
    
  } else {
    printf("O registro nao foi encontrado!\n");
  }
  
  printf("------------------------------------");

}

void OpcaoBuscar(TipoDicionario *Dic) {
  
  TipoChave a;

  printf("Digite a Chave: ");
  scanf("%d", &a);


  TipoApontador* p = Localiza(a, Dic);

  printf("\n------------------------------------\n");

  if (*p != NULL) {
    printf("O registro foi encontrado.");
    printf("\n------------------------------------\n");

    printf("%-8s\n", "CODIGO");
    printf("%-8d\n", (*p)->Registro.Chave);

  } else {
    printf("O registro nao foi encontrado!\n");
  }
  
  printf("------------------------------------");

}

void OpcaoBuscarPai(TipoDicionario *Dic) {
  
  TipoChave a;

  printf("Digite a Chave: ");
  scanf("%d", &a);


  TipoApontador* p = Localiza(a, Dic);

  printf("\n------------------------------------\n");

  if (*p != NULL) {

    TipoApontador* pai = BuscaPai(a, Dic);

    if (*pai != NULL) {

      printf("O registro Pai foi encontrado.");
      printf("\n------------------------------------\n");

      printf("%-8s\n", "CODIGO");
      printf("%-8d\n", (*pai)->Registro.Chave);

    } else {
      printf("O registro nao possui pai!\n");
    }

  } else {
    printf("O registro nao foi encontrado!\n");
  }
  
  printf("------------------------------------");

}
// --------------------Número 1 - Letra B--------------------
void OpcaoImprimirNosNaoFolha(TipoDicionario *Dic){
	TipoApontador* p = Localiza(41, Dic);
	ImprimirNosNaoFolha(p);
}
// --------------------Número 1 - Letra C--------------------
void OpcaoImprimirTodosNosFolha(TipoDicionario *Dic){
	TipoApontador* p = Localiza(41, Dic);
	ImprimirTodosNosFolha(p);
}
// --------------------Número 1 - Letra D--------------------
void OpcaoVerificarBinaria(TipoDicionario *Dic){
	TipoApontador* p = Localiza(41, Dic);
	VerificarBinaria(p);
}

int main(int argc, char *argv[]) {
 	
  int opcao;

  TipoDicionario Dic;
	
  Inicializa(&Dic);

  CargaInicialParaTeste(&Dic);

 do {
    opcao = LerOpcaoMenu();

    switch(opcao) {       
     case 1: OpcaoBuscar(&Dic); break;
     case 2: OpcaoInserirRegistro(&Dic); break;  
     case 3: OpcaoRemoverRegistro(&Dic); break; 
     case 4: ImprimeDicionario(&Dic, "Em Ordem");  break;    
     case 5: ImprimeDicionario(&Dic, "Pre-Ordem"); break;   
     case 6: ImprimeDicionario(&Dic, "Pos-Ordem"); break;  

     case 7: OpcaoMostrarMinimo(&Dic); break; 
     case 8: OpcaoMostrarMaximo(&Dic); break;  
     case 9: OpcaoBuscarPai(&Dic); break;       
     case 10: OpcaoSucessor(&Dic); break;
     // ------Número 1 - Letra B------
	 case 11: OpcaoImprimirNosNaoFolha(&Dic); break; 
	 // ------Número 1 - Letra C------    
     case 12: OpcaoImprimirTodosNosFolha(&Dic); break;
     // ------Número 1 - Letra D------
     case 13: OpcaoVerificarBinaria(&Dic); break;
    }

  if (opcao != -1) {  
    getchar();
    getchar();    
  }

  } while (opcao != -1);   

	return 0;
}
