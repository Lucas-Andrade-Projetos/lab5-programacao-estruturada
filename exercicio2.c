/*
Escreva um programa que, dado um inteiro n fornecido pelo usuário, leia n caracteres
fornecidos pelo usuário e as armazene em um vetor. Na sequência, para cada uma das n entradas
armazenadas no vetor,o seu programa deve imprimir a seguinte linha: “entrada xxx, conteudo
yyy, endereco: zzz”,onde xxx deve ser substituído pelo índice da entrada, yyy pelo conteúdo
dessa entrada no array e zzz pelo endereço de memória dessa entrada em decimal.
*/

#include <stdio.h>
#include <stdlib.h>

void le_caractere(char *array, int n);
void display(char *array, int n);

int main() {
    int n; 
    char *vetor; 

    printf("Digite o número de entradas: ");
    scanf("%d", &n);

    //Aloca dinamicamente memória para armazenar os caracteres
    vetor = calloc(n, sizeof(char));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

	le_caractere(vetor, n);

	display(vetor, n);

    //Libera a memória alocada
    free(vetor);
    return 0;
}

//Função que lê os caracteres fornecidos pelo usuário
void le_caractere(char *array, int n) {
    
	for (int i = 0; i < n; i++) {
        printf("Digite o caractere %d: ", i + 1);
        scanf(" %c", &array[i]); //Espaço antes de %c para ignorar caracteres de nova linha
    }
}

//Função que exibe as informações de cada entrada
void display(char *array, int n) {
    
	for (int i = 0; i < n; i++) {
        printf("entrada %d, conteudo %c, endereco: %p\n", i, array[i], (void*)&array[i]);
    }
}