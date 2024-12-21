/*
Implemente as funções:
 • matriz_le(n, m) essa função lê e retorna uma matriz M de números inteiros fornecida pelo
 usuário. Ela recebe dois parâmetros n e m, onde n é o número de linhas e m, o de colunas. Essa
 função é responsável por alocar a memória para M e por ler todo o conteúdo de M, que deverá ser
 fornecido pelo usuário.
 • matriz_print(M, n, m) essa função imprime na tela do usuário a matriz M que tem n linhas
 e m colunas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Protótipos das funções
int** matriz_le(int n, int m);
void matriz_print(int** M, int n, int m);
void matriz_destroy(int** M, int n); 

int main() {
    int n, m;

    printf("Digite o número de linhas (n): ");
    scanf("%d", &n);
    printf("Digite o número de colunas (m): ");
    scanf("%d", &m);

    int** matriz = matriz_le(n, m);

    printf("\nMatriz fornecida:\n");
    matriz_print(matriz, n, m);

    matriz_destroy(matriz, n); 
    return 0;
}

//Função para ler uma matriz de tamanho n x m fornecida pelo usuário
int** matriz_le(int n, int m) {
    
    int** M = (int**)malloc(n * sizeof(int*));
    if (!M) {
        perror("Erro ao alocar memória para as linhas");
        exit(EXIT_FAILURE);
    }

    
    for (int i = 0; i < n; i++) {
        M[i] = (int*)malloc(m * sizeof(int));
        if (!M[i]) {
            perror("Erro ao alocar memória para uma linha");
            // Libera memória já alocada antes de sair
            for (int j = 0; j < i; j++) {
                free(M[j]);
            }
            free(M);
            exit(EXIT_FAILURE);
        }
    }

    printf("Digite os elementos da matriz (%d linhas x %d colunas):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &M[i][j]);
        }
    }

    return M;
}

//Função para imprimir uma matriz de tamanho n x m
void matriz_print(int** M, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

//Função opcional para liberar a memória alocada para a matriz
void matriz_destroy(int** M, int n) {
    for (int i = 0; i < n; i++) {
        free(M[i]);
    }
    free(M);
}
