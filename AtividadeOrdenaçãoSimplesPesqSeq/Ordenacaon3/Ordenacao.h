#define MAXN 100

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
    char Nome[10];
    int Categoria;
} TipoRegistro;

typedef struct Tabela* TipoTabela;

TipoTabela CriaTabela();
void Insere(TipoTabela T, TipoRegistro Reg);
void ListaTabela(TipoTabela T);
int PesquisaSequencial(TipoChave x, TipoRegistro* Reg, TipoTabela T);
int PesquisaBinaria(TipoChave x, TipoRegistro* Reg, TipoTabela T);
void insertionSort(TipoTabela T);

void buscaVetor(int num, TipoTabela T);
	

