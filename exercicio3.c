/*
Escreva a funçãoswap(a, b). Essa função recebe como parâmetro dois inteiros a e b
e não tem nenhum retorno.O comportamento dessa função deve ser o seguinte: após a execução da
mesma, os valores de a e b devem estar trocados, como ilustra o exemplo a seguir.
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);

int main() {
    int a;
    int b;

	scanf("%d", &a);
	scanf("%d", &b);
    
	printf("a = %d, b = %d\n", a, b);
    
	swap(&a, &b);

    printf("a = %d, b = %d\n", a, b);
   
    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}