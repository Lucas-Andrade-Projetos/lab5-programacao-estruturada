/* 
Escreva um programa que, dado um inteiro n fornecido pelo usuário, leia n números
inteiros fornecidos pelo usuário e compute a média desses números.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    //Alocação dinâmica de memória para o vetor
    int* vetor = (int*)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int soma = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    double media = (double)soma / n;
    printf("A média é: %.2f\n", media);

    free(vetor);
    return 0;
}
