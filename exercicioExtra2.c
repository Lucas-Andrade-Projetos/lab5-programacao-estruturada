#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void le_numeros(int* array, int n);
int menor_numero(int* array, int n);

int main(){

	int n = 0;
	scanf("%d", &n);

	int* vetor = calloc(n, sizeof(int));
	if(vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
	le_numeros(vetor, n);

	int resultado = menor_numero(vetor, n);

	printf("%d", resultado);

	free(vetor);
	return 0;
}

void le_numeros(int* array, int n){

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
}

int menor_numero(int* array, int n)
{
	if(n == 1) return array[0];
	
	int menor = menor_numero(array+1, n-1);

	if(array[0] < menor)
	{
		return array[0];
	}else{
		return menor;
	}
}
