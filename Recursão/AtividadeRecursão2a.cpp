#include <stdio.h>
#include <stdlib.h>

/*
Numero 2 - LETRA A
*/
int f2(int n, int pos, int i){
	if (n == 0){
		printf("ZERO");
	}
	else{
		if(i <= 10){
			printf("%d ",n);
			i++;
			f2(n*2, pos, i);
			if(pos == i){
				printf("\nO numero na posicao %d eh %d", i ,n);
			}
		}else{
			return 0;
		}
		
	}
}
int main(){
	f2(2, 4, 0);
	return 0;
}
