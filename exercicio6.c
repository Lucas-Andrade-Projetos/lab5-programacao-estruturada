/*
 Implemente a função strcat(a, b). Essa função recebe dois parâmetros a e b do tipo
 “string em C”, i.e., array de caracteres, e retorna uma string que é a concatenação da string a com a
 string b. Além disso, a sua função não deve alterar o conteúdo das variáveis a e b, que ainda podem
 ser úteis para o cliente da sua função.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 250

char* strcat_custom(const char* a, const char* b);
void ler_palavra(char *palavra, int tamanho_maximo);


int main() {

 	char p1[max]; 
    ler_palavra(p1, sizeof(p1)); 
	char p2[max]; 
    ler_palavra(p2, sizeof(p2)); 

    char* result = strcat_custom(p1, p2);
    
    if (result != NULL) {
        printf("Resultado da concatenação: %s\n", result);
        free(result);
    }
    
    return 0;
}

// Função para ler uma palavra
void ler_palavra(char *palavra, int tamanho_maximo) {

    if (fgets(palavra, tamanho_maximo, stdin) != NULL) {
        size_t tamanho = strlen(palavra);
        if (palavra[tamanho - 1] == '\n') {
            palavra[tamanho - 1] = '\0'; 
        }
    }
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