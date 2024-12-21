/*
Implemente a função char* revert(char* s). Essa função recebe uma “string de C”
s e retornar uma nova “string de C” com os caracteres de s revertidos, i.e., listados da direita para a
esquerda.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 250

void ler_palavra(char *array, int n);
void display(char *array);
char* revert(char* s);

int main() {
    char s[max];
    ler_palavra(s, sizeof(s)); 

	char* resultado = revert(s);

    if (resultado) {
        display(s);
        display(resultado);
        free(resultado);
    }

    return 0;
}

void ler_palavra(char *array, int n)
{
	
	if (fgets(array, n, stdin) != NULL) {
        int n = strlen(array);
        if (array[n - 1] == '\n') {
            array[n - 1] = '\0'; 
        }
    }
}

void display(char *array)
{
	printf("%s\n", array);
}


char* revert(char* s) {
    int len = strlen(s);

    //Aloca memória para a string invertida
    char* invertida = calloc(len + 1 , sizeof(char));
    if (invertida == NULL) {
        printf("Erro ao alocar memória\n");
        return NULL;
    }

    //Copia os caracteres de trás para frente
    for (int i = 0; i < len; i++) {
        invertida[i] = s[len - 1 - i];
    }

    //Adiciona o caractere nulo no final
    invertida[len] = '\0';

    return invertida;
}