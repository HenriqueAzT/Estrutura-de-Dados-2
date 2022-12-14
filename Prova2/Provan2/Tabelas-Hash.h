#define MAXN 23

typedef int TipoChave;

typedef struct {
  TipoChave Chave;  
  char Nome[10];
  int Idade;  
} TipoRegistro;

typedef int TipoIndice;

typedef struct {
  TipoRegistro Item[MAXN + 1] ;
  TipoIndice n;
} TipoTabela;

void ListaTabela(TipoTabela *T);
void Inicializa (TipoTabela *T); 
TipoIndice Hash(TipoChave Chave); 
TipoIndice Insere(TipoRegistro Reg, TipoTabela *T);
TipoIndice Busca(TipoChave Chave, TipoTabela *T);
TipoIndice Exclui(TipoChave Chave, TipoTabela *T);
