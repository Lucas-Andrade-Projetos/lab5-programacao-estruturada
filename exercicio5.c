/*
Escreva a função swap(a, b). Essa função recebe como parâmetro dois arrays de inteiros 
a e b e não tem nenhum retorno. O comportamento dessa função deve ser o seguinte: após a
execução da mesma, os valores de a e b devem estar trocados, como ilustra o exemplo a seguir. Você
deve realizar essa tarefa apenas usando manipulação de ponteiro, não copie os elementos de um
vetor no outro!
*/

#include <stdio.h>
#include <stdlib.h>

void le_numeros(int *array, int n);
void display(int *array, int n);
void swap(int **a, int **b);

int main() {
	
	//pedindo a variavel para o user
	int n=0, m=0; 
    scanf("%d", &n);
	scanf("%d", &m);
	int *a;
	int *b;
	a = calloc(n, sizeof(int));
	b = calloc(m, sizeof(int));

	if(a == NULL || b == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

	//adicionando os valores
	le_numeros(a, n);
	le_numeros(b, m);

	printf("Conteúdo de a antes da troca: ");
    display(a, n);
    printf("\n");

    printf("Conteúdo de b antes a troca: ");
	display(b, m);
    printf("\n");
    
	swap(&a, &b);

    printf("Conteúdo de a depois da troca: ");
    display(a, n);
    printf("\n");

    printf("Conteúdo de b depois da troca: ");
	display(b, m);
    printf("\n");

	//Libera a memória alocada
	free(a);
	free(b);
    return 0;
}

void le_numeros(int *array, int n){
	
	for (int i = 0; i < n; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

void display(int *array, int n){
	
	for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}

void swap(int **a, int **b){
    
	int *temp = *a;
	*a = *b;
	*b = temp;
}
