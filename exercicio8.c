/*
Implemente a função char* revert(char* s). Essa função recebe uma “string de C”
s e retornar uma nova “string de C” com os caracteres de s revertidos, i.e., listados da direita para a
esquerda.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* revert(char* s) {
    int len = strlen(s);

    //Aloca memória para a string invertida
    char* invertida = malloc((len + 1) * sizeof(char));
    if (!invertida) {
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


int main() {
    char s[] = "Tenta ai!";
    char* resultado = revert(s);

    if (resultado) {
        printf("String original: %s\n", s);
        printf("String invertida: %s\n", resultado);
        free(resultado);
    }

    return 0;
}
