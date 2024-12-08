/*
Escreva a função cartesiano(v1, n1, v2, n2). Essa função recebe como parâmetro
dois vetores de inteiro, v1 e v2, e os seus respectivos tamanhos, n1 e n2. O retorno dessa função deve
ser um array com os elementos do conjunto obtido pelo produto cartesiano de v1 por v2.
*/

#include <stdlib.h>
#include <stdio.h>

int* cartesiano(int* v1, int n1, int* v2, int n2, int* tamanhoResultado);

int main() {
    int v1[] = {1, 2};
    int v2[] = {3, 4};
    int n1 = 2, n2 = 2;

    int tamanhoResultado;
    int* resultado = cartesiano(v1, n1, v2, n2, &tamanhoResultado);

    if (resultado) {
        for (int i = 0; i < tamanhoResultado * 2; i += 2) {
            printf("(%d, %d)\n", resultado[i], resultado[i + 1]);
        }
        free(resultado);
    }

    return 0;
}

int* cartesiano(int* v1, int n1, int* v2, int n2, int* tamanhoResultado) {

    *tamanhoResultado = n1 * n2;

    // Aloca memória para o array resultado
    int* resultado = calloc(*tamanhoResultado * 2, sizeof(int));
    if (!resultado) {
        printf("Erro ao alocar memória\n");
        return NULL;
    }

    int k = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            resultado[k++] = v1[i];
            resultado[k++] = v2[j];
        }
    }

    return resultado;
}