/*
Escreva a função swap(a, b). Essa função recebe como parâmetro dois arrays de inteiros 
a e b e não tem nenhum retorno. O comportamento dessa função deve ser o seguinte: após a
execução da mesma, os valores de a e b devem estar trocados, como ilustra o exemplo a seguir. Você
deve realizar essa tarefa apenas usando manipulação de ponteiro, não copie os elementos de um
vetor no outro!
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main() {
    int a[] = {5, 6, 7};
    int b[] = {1, 2, 0, 8};

    //Calculando o tamanho de cada array
    int size_a = sizeof(a) / sizeof(a[0]);
    int size_b = sizeof(b) / sizeof(b[0]);

    swap(a, b);

    printf("Conteúdo de a após a troca: ");
    for (int i = 0; i < size_b; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Conteúdo de b após a troca: ");
    for (int i = 0; i < size_a; i++) {
        printf("%d ", b[i]);
    }

    printf("\n");

    return 0;
}

void swap(int *a, int *b) {
    int temp;
    
    for (int i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
        temp = *(a + i);
        *(a + i) = *(b + i);
        *(b + i) = temp;
    }
}
