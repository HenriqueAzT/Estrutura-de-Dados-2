#include <stdio.h>
#include <stdlib.h>

/*
Numero 2 - LETRA A
*/
int f2(int vetor[]){
	int i = 0;
	for(i; i<5; i++){
		if(vetor[i] % 5 == vetor[i+1] % 5){
			printf("O vetor tem um cluster\n");
		}else{
			printf("O vetor nao tem cluster\n");	
		}
	}
	
	
}
int main(){
	int vetor[5] = {5, 10, 15, 20, 30};
	f2(vetor);
	return 0;
}
