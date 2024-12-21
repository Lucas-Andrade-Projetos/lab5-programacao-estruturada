/*
Escreva a função cartesiano(v1, n1, v2, n2). Essa função recebe como parâmetro
dois vetores de inteiro, v1 e v2, e os seus respectivos tamanhos, n1 e n2. O retorno dessa função deve
ser um array com os elementos do conjunto obtido pelo produto cartesiano de v1 por v2.
*/

#include <stdio.h>
#include <stdlib.h>

void le_numeros(int* array, int n);
void display(int* array, int n1, int n2);
int* cartesiano(int* v1, int n1, int* v2, int n2);

int main() {

	int n = 0, m = 0;

	scanf("%d", &n);
	scanf("%d", &m);

	int *v1 = calloc(n, sizeof(int));
	int *v2 = calloc(m, sizeof(int));

	if (v1 == NULL || v2 == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

	le_numeros(v1, n);
	le_numeros(v2, m);

    int* resultado = cartesiano(v1, n, v2, m);
	
	display(resultado, n, m);
	
	free(resultado);
    free(v1);
    free(v2);

    return 0;
}

void le_numeros(int* array, int n){

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
}

void display(int* array, int n1, int n2) {

	int tamanho = n1 * n2 * 2; 
    for (int i = 0; i < tamanho; i += 2) {
        printf("(%d, %d)\n", array[i], array[i + 1]);
    }
}

int* cartesiano(int* v1, int n1, int* v2, int n2) {
    
	int tamanho = n1 * n2 * 2; 
    int* resultado = calloc(tamanho, sizeof(int));

    if (!resultado) {
        printf("Erro ao alocar memória.\n");
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