#include <stdio.h>
#include "Arvores-Binarias-de-Busca.h"


void OpcaoMostrarMinimo(TipoApontador *p) {
  
  TipoApontador* a = Minimo(p);
  
  printf("\n%-8s %-15s %-8s\n", "CODIGO", "NOME", "IDADE");
  printf("------------------------------------\n");  
  if (*a != NULL)
    printf("%-8d %-15s %-8d\n", (*a)->Registro.Chave, (*a)->Registro.Nome, (*a)->Registro.Idade);  
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
        printf("%-8s %-15s %-8s\n", "CODIGO", "NOME", "IDADE");
        printf("%-8d %-15s %-8d\n", (*q)->Registro.Chave, (*q)->Registro.Nome, (*q)->Registro.Idade); 
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
  
  printf("\n%-8s %-15s %-8s\n", "CODIGO", "NOME", "IDADE");
  printf("------------------------------------\n");
  if (*a != NULL)
    printf("%-8d %-15s %-8d\n", (*a)->Registro.Chave, (*a)->Registro.Nome, (*a)->Registro.Idade);  
  else
    printf("A tabela esta vazia!");
  printf("------------------------------------\n");

}

void CargaInicialParaTeste(TipoDicionario *Dic) { 

  TipoRegistro a1 = {50, "Maria", 25};
  Insere(a1, Dic);

  TipoRegistro a2 = {20, "Joao", 57};
  Insere(a2, Dic);

  TipoRegistro a3 = {80, "Sara", 19};
  Insere(a3, Dic);

  TipoRegistro a4 = {60, "Elisa", 31};
  Insere(a4, Dic);

  TipoRegistro a5 = {71, "Renan", 32};
  Insere(a5, Dic);

  TipoRegistro a6 = {33, "Thais", 19};
  Insere(a6, Dic);

  TipoRegistro a7 = {92, "Ana", 12};
  Insere(a7, Dic);

  TipoRegistro a8 = {95, "Silvia", 21};
  Insere(a8, Dic);

  TipoRegistro a9 = {84, "Lucio", 45};
  Insere(a9, Dic);

  TipoRegistro a10 = {15, "Lucas", 15};
  Insere(a10, Dic);

  TipoRegistro a11 = {87, "Lara", 19};
  Insere(a11, Dic);

  TipoRegistro a12 = {17, "Julia", 51};
  Insere(a12, Dic);

  TipoRegistro a13 = {82, "Simone", 40};
  Insere(a13, Dic);

  TipoRegistro a14 = {26, "Carla", 18};
  Insere(a14, Dic);

  TipoRegistro a15 = {96, "Mario", 65};
  Insere(a15, Dic);

  TipoRegistro a16 = {55, "Gabriela", 65};
  Insere(a16, Dic);

  TipoRegistro a18 = {83, "Thiago", 65};
  Insere(a18, Dic);

  TipoRegistro a19 = {10, "Elizabeth", 65};
  Insere(a19, Dic);

  TipoRegistro a20 = {5, "Martha", 65};
  Insere(a20, Dic);
 
  TipoRegistro a22 = {40, "Manoel", 65};
  Insere(a22, Dic);

  TipoRegistro a23 = {47, "Ruan", 65};
  Insere(a23, Dic);

  TipoRegistro a24 = {49, "Janaina", 65};
  Insere(a24, Dic);

  TipoRegistro a25 = {45, "Marcela", 65};
  Insere(a25, Dic);

  TipoRegistro a27 = {29, "Karita", 65};
  Insere(a27, Dic);
  
  TipoRegistro a26 = {28, "Gabriel", 65};
  Insere(a26, Dic);

  TipoRegistro a28 = {30, "Beto", 65};
  Insere(a28, Dic);
  
  TipoRegistro a21 = {12, "Romario", 65};
  Insere(a21, Dic);
  
  TipoRegistro a17 = {93, "Monica", 65};
  Insere(a17, Dic);

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

  printf("Escolha uma opcao, ou -1 para sair: ");
  scanf("%d", &opcao);
  return opcao;

}

void OpcaoInserirRegistro(TipoDicionario *Dic) {
  TipoRegistro a;
  
  printf("Digite a Chave: ");
  scanf("%d", &a.Chave);

  printf("Digite o Nome: ");
  scanf("%s", a.Nome);

  printf("Digite a Idade: ");
  scanf("%d", &a.Idade);

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

    printf("%-8s %-15s %-8s\n", "CODIGO", "NOME", "IDADE");
    printf("%-8d %-15s %-8d\n", (*p)->Registro.Chave, (*p)->Registro.Nome, (*p)->Registro.Idade);

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

      printf("%-8s %-15s %-8s\n", "CODIGO", "NOME", "IDADE");
      printf("%-8d %-15s %-8d\n", (*pai)->Registro.Chave, (*pai)->Registro.Nome, (*pai)->Registro.Idade);

    } else {
      printf("O registro nao possui pai!\n");
    }

  } else {
    printf("O registro nao foi encontrado!\n");
  }
  
  printf("------------------------------------");

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
     
    }

  if (opcao != -1) {  
    getchar();
    getchar();    
  }

  } while (opcao != -1);   

	return 0;
}
