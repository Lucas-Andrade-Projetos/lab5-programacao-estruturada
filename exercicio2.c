/*
Escreva um programa que, dado um inteiro n fornecido pelo usuário, leia n caracteres
fornecidos pelo usuário e as armazene em um vetor. Na sequência, para cada uma das n entradas
armazenadas no vetor,o seu programa deve imprimir a seguinte linha: “entrada xxx, conteudo
yyy, endereco: zzz”,onde xxx deve ser substituído pelo índice da entrada, yyy pelo conteúdo
dessa entrada no array e zzz pelo endereço dem memória dessa entrada em decimal.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Digite o número de caracteres: ");
    scanf("%d", &n);

    // Alocação dinâmica de memória para o vetor de caracteres
    char* vetor = (char*)malloc(n * sizeof(char));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Digite o caractere %d: ", i + 1);
        scanf(" %c", &vetor[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("entrada %d, conteudo %c, endereco: %p\n", i, vetor[i], (void*)&vetor[i]);
    }

    free(vetor);
    return 0;
}
