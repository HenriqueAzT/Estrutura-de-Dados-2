typedef struct retangulo Retangulo;

Retangulo* cria_retangulo(float base, float altura);

float obterBase(Retangulo* retangulo);

void obterBase_e_altura(Retangulo* retangulo, 
	float* base, float* altura);

int altera_retangulo(Retangulo* retangulo, 
	float base, float altura);

void destroi_retangulo(Retangulo* r1);
