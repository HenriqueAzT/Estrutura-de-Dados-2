#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

int busca_divisao_conquista(int *v, int inicio, int final, int chave) {
    int encontrou = -1;
    int lado1, lado2;
    if (inicio == final) {
        if (v[inicio] == chave)  
            encontrou = inicio;
    } else if (inicio < final) {
        int meio = (inicio + final) / 2;
        lado1 = busca_divisao_conquista(v, inicio, meio, chave);
        if (lado1 > -1)
            encontrou = lado1;
        else {
            lado2 = busca_divisao_conquista(v, meio + 1, final, chave); 
            if (lado2 > -1)
                encontrou = lado2; 
        }
    }   
    return encontrou; 
}


int main(int argc, char const *argv[])
{
    int vetor[TAM] = {6, 3, 0, 4, 8, 2, 9, 1, 5, 7};
    int el = -1; 
    int continua = 1; 
    
    printf("Qual elemento voce deseja encontrar? ");
    scanf("%d", &el);

    int pos = busca_divisao_conquista(vetor, 0, TAM-1, el); 
    if(pos == -1){
        printf("Elemento %d nao foi localizado!\n", el);   	
	}else{
        printf("O numero %d foi encontrado na posicao: %d\n", el, pos);
    }
    
	return 0;
    system("PAUSE");
}
