#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100 // Declara o tamanho do vetor;

void fInsertion_Sort(int *pVetor);

int main()
{
    int vVetor[TAM];
    int vAux;

    srand(time(NULL));
    for (vAux=0; vAux < TAM; vAux++)
    {
        vVetor[vAux] = (rand() % 90) + 10; // Preenche o vetor com valores aleat�rios de 10 at� 99;
        printf(" %d,",vVetor[vAux]);
    }

    fInsertion_Sort(vVetor); // Chama a fun��o de Ordena��o;

    printf("\n\n");
    for (vAux=0; vAux < TAM; vAux++)
    {
        printf(" %d,",vVetor[vAux]);
    }

    printf("\n\n ");
    system("pause");
}

void fInsertion_Sort(int *pVetor)
{
    int vAux;
    int vTemp;
    int vTroca;

    for (vAux=1; vAux < TAM; vAux++) // vAux come�a na posi��o 1 do vetor e vai at� a ultima posi��o;
    {
        vTemp = vAux; // vTemp recebe a posi��o que est� passando no "for";

        while (pVetor[vTemp] < pVetor[vTemp-1]) // Enquanto o valor que est� passando na posi��o "vTemp" for menor que a posi��o "vTemp" menos 1, ocorre a troca;
        { // Ocorre a troca;
            vTroca          = pVetor[vTemp];
            pVetor[vTemp]   = pVetor[vTemp-1];
            pVetor[vTemp-1] = vTroca;
            vTemp--; // vTemp decrementa 1;

            if (vTemp == 0) // Quando "vTemp" chegar na posi��o 0, primeira posi��o do vetor, o la�o while para;
                break;
        }

    }
}
