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

  TipoRegistro a1 = {79};
  Insere(a1, Dic);

  TipoRegistro a2 = {55};
  Insere(a2, Dic);

  TipoRegistro a3 = {50};
  Insere(a3, Dic);

  TipoRegistro a4 = {30};
  Insere(a4, Dic);

  TipoRegistro a5 = {54};
  Insere(a5, Dic);

  TipoRegistro a6 = {77};
  Insere(a6, Dic);

  TipoRegistro a7 = {56};
  Insere(a7, Dic);

  TipoRegistro a8 = {94};
  Insere(a8, Dic);

  TipoRegistro a9 = {86};
  Insere(a9, Dic);

  TipoRegistro a10 = {97};
  Insere(a10, Dic);

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
  printf("13: Busca no e o irmao\n");
  printf("14: Travessia em PreOrdem por Nivel\n");

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

void OpcaoImprimeNoEIrmao(TipoDicionario *Dic){
	TipoChave a;

  printf("Digite a Chave: ");
  scanf("%d", &a);
  TipoApontador* p = Localiza(a, Dic);
  int irmao = ImprimeNoEIrmao(p, Dic);

  printf("\n------------------------------------\n");

  if (*p != NULL) {
    printf("O registro foi encontrado.");
    printf("\n------------------------------------\n");

    printf("%-8s\n%-8s\n", "VALOR" "VALOR DO IRMAO");
    printf("%-8d\n", (*p)->Registro.Chave, irmao);

  }else {
    printf("O registro nao foi encontrado!\n");
  }
  
  printf("------------------------------------");
}
void OpcaoTravessiaEmOrdemNivel(TipoDicionario *Dic){
	TipoApontador* p = Localiza(79, Dic);
	TravessiaEmOrdemNivel(p, 0);
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
     case 13: OpcaoImprimeNoEIrmao(&Dic); break;
     case 14: OpcaoTravessiaEmOrdemNivel(&Dic); break;
    }

  if (opcao != -1) {  
    getchar();
    getchar();    
  }

  } while (opcao != -1);   

	return 0;
}
