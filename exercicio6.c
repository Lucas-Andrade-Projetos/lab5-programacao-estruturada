/*
 Implemente a função strcat(a, b). Essa função recebe dois parâmetros a e b do tipo
 “string em C”, i.e., array de caracteres, e retorna uma string que é a concatenação da string a com a
 string b. Além disso, a sua função não deve alterar o conteúdo das variáveis a e b, que ainda podem
 ser úteis para o cliente da sua função.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strcat_custom(const char* a, const char* b);

int main() {
    char a[] = "Olá, ";
    char b[] = "mundo!";
    
    char* result = strcat_custom(a, b);
    
    if (result != NULL) {
        printf("Resultado da concatenação: %s\n", result);
        free(result);
    }
    
    return 0;
}

char* strcat_custom(const char* a, const char* b) {
    //Calculando o tamanho das duas strings + 1 para o '\0' final
    int size_a = strlen(a);
    int size_b = strlen(b);
    
    //Alocando memória para a string resultante
    char* result = (char*)malloc((size_a + size_b + 1) * sizeof(char));
    
    if (result == NULL) {
        printf("Erro na alocação de memória!\n");
        return NULL;
    }

    strcpy(result, a);
    
    strcat(result, b);
    
    return result;  
}