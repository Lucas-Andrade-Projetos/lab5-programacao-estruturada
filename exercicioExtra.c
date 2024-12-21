/*
Escreva a função swap(a, b). Essa função recebe como parâmetro dois arrays de inteiros 
a e b e não tem nenhum retorno. O comportamento dessa função deve ser o seguinte: após a
execução da mesma, os valores de a e b devem estar trocados, como ilustra o exemplo a seguir. Você
deve realizar essa tarefa apenas usando manipulação de ponteiro, não copie os elementos de um
vetor no outro!

fazendo isso com chars
*/

#include <stdio.h>
#include <stdlib.h>

void le_numeros(char *array, int n);
void display(char *array);
void swap(char **a, char **b);

int main() {
	
	//pedindo a variavel para o user
	int n=0, m=0; 
    scanf("%d", &n);
	scanf("%d", &m);
	char *a;
	char *b;
	a = calloc(n + 1, sizeof(char));
	b = calloc(m+ 1, sizeof(char));

	if(a == NULL || b == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

	//adicionando os valores
	le_numeros(a, n);
	le_numeros(b, m);

	printf("Conteúdo de a antes da troca: ");
    display(a);
    printf("\n");

    printf("Conteúdo de b antes a troca: ");
	display(b);
    printf("\n");
    
	swap(&a, &b);

    printf("Conteúdo de a depois da troca: ");
    display(a);
    printf("\n");

    printf("Conteúdo de b depois da troca: ");
	display(b);
    printf("\n");

	//Libera a memória alocada
	free(a);
	free(b);
    return 0;
}

void le_numeros(char *array, int n){
	
	for (int i = 0; i < n; i++) {
        printf("Digite o caractere %d: ", i + 1);
        scanf(" %c", &array[i]);
    }
	array[n] = '\0'; // Adiciona terminador de string
}

void display(char *array){
	
    printf("%s", array);
}

void swap(char **a, char **b){
 	//teste   
	char *temp = *a;
	*a = *b;
	*b = temp;

}
