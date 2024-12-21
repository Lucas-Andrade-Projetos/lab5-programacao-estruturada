/*
Escreva a função inc(x). Essa função recebe apenas um parâmetro do tipo inteiro e
não tem retorno. Seu comportamento é o seguinte: após a execução de inc(x), o valor de x está
incrementado em uma unidade, como ilustra o exemplo a seguir.
*/

#include <stdio.h>
#include <stdlib.h>

void inc(int* x); 

int main() {
	int a;
    scanf("%d", &a);
    inc(&a);  
    printf("%d\n", a);  
    return 0;
}

void inc(int* x) {
    (*x)++;
}