#include <stdio.h>
#include <stdlib.h>
#include "Retangulo.h"

void ordenaValores(int a, int b, int c){
	if(a > c && a > b && b > c){ //se A for o maior e C o menor
		printf("ANTES: A: %d, B: %d, C: %d\n", a, b, c);
		int aux;
		aux = a;
		a = c;
		c = aux;
		printf("DEPOIS: A: %d, B: %d, C: %d\n", a, b, c);
		
	}else{
		if(b > a && b > c && c > a){ //se B for o maior e A o menor
			printf("ANTES: A: %d, B: %d, C: %d\n", a, b, c);
			int aux;
			aux = b;
			b = c;
			c = aux;
			printf("DEPOIS: A: %d, B: %d, C: %d\n", a, b, c);
		}else{
			if(c > a && c > b && b > a){ //se C for o maior e A o menor
				printf("ANTES: A: %d, B: %d, C: %d\n", a, b, c);
				printf("DEPOIS: A: %d, B: %d, C: %d\n", a, b, c);
			}else{
				if(a > c && a > b && c > b) { //se A for o maior e B o menor
					printf("ANTES: A: %d, B: %d, C: %d\n", a, b, c);
					int aux;
					int aux2;
					aux2 = b;
					aux = a;
					b = c;
					a = aux2;
					c = aux;
					printf("DEPOIS: A: %d, B: %d, C: %d\n", a, b, c);
				}else{
					if(a == b || a == c || b == c) {
						printf("Insira valores diferentes!\n");
					}
				}
			}
		}
	}
}




