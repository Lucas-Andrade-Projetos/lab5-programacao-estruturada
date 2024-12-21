/* 
Escreva um programa que, dado um inteiro n fornecido pelo usuário, leia n números
inteiros fornecidos pelo usuário e compute a média desses números.
*/

#include <stdio.h>
#include <stdlib.h>

void le_numeros(int *array, int n);
void calcularSomaMedia(int *array, int tamanho, int *soma, double *media);

int main() {
    int n; 
    int soma; 
    double media; 

    printf("Digite a quantidade de números: ");
    scanf("%d", &n);

    //Aloca memória dinamicamente para armazenar os números
    int *numero = calloc(n, sizeof(int));
    if (numero == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    le_numeros(numero, n);

    calcularSomaMedia(numero, n, &soma, &media);

    printf("A soma é %d e a média é %.2lf\n", soma, media);

    // Libera a memória alocada
    free(numero);

    return 0;
}

//Função que calcula a soma e a média de um array
void calcularSomaMedia(int *array, int tamanho, int *soma, double *media) {
    *soma = 0; // Inicializa a soma
    for (int i = 0; i < tamanho; i++) {
        *soma += array[i]; //Soma os elementos do array
    }
    *media = (double)*soma / tamanho; //Calcula a média
}

//Função que lê os números fornecidos pelo usuário
void le_numeros(int *array, int n){
	
    for (int i = 0; i < n; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}
