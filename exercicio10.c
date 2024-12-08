#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição do tipo VectorInt
typedef struct {
    int* data;
    int capacity;   
    int nelements; 
} *VectorInt;

// Protótipos das funções
VectorInt vectorint(void);
void vectorint_insert(VectorInt v, int a);
void vectorint_remove(VectorInt v, int a);
int vectorint_at(VectorInt v, int i);
bool vectorint_contains(VectorInt v, int a);
int vectorint_size(VectorInt v);
void vectorint_destroy(VectorInt v);

int main() {
    VectorInt v = vectorint();

    vectorint_insert(v, 10);
    vectorint_insert(v, 20);
    vectorint_insert(v, 30);
    vectorint_insert(v, 10);

    printf("Elementos no vetor: ");
    for (int i = 0; i < vectorint_size(v); i++) {
        printf("%d ", vectorint_at(v, i));
    }
    printf("\n");

    printf("O vetor contém 20? %s\n", vectorint_contains(v, 20) ? "Sim" : "Não");

    printf("Removendo o elemento 10...\n");
    vectorint_remove(v, 10);

    printf("Elementos no vetor após a remoção: ");
    for (int i = 0; i < vectorint_size(v); i++) {
        printf("%d ", vectorint_at(v, i));
    }
    printf("\n");

    vectorint_destroy(v);
    printf("Memória liberada.\n");

    return 0;
}

// Cria um novo VectorInt
VectorInt vectorint(void) {
    VectorInt v = (VectorInt)malloc(sizeof(*v));
    if (!v) {
        perror("Erro ao alocar memória para VectorInt");
        exit(EXIT_FAILURE);
    }

    v->data = (int*)malloc(sizeof(int)); // Capacidade inicial de 1
    if (!v->data) {
        perror("Erro ao alocar memória para o array de dados");
        free(v);
        exit(EXIT_FAILURE);
    }

    v->capacity = 1;
    v->nelements = 0;

    return v;
}

// Insere um elemento no VectorInt
void vectorint_insert(VectorInt v, int a) {
    if (!v) return;

    if (v->nelements == v->capacity) {
        int new_capacity = v->capacity * 2;
        int* new_data = realloc(v->data, new_capacity * sizeof(int));
        if (!new_data) {
            printf("Erro ao redimensionar memória\n");
            return;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }

    v->data[v->nelements] = a;
    v->nelements++;
}

// Remove todas as ocorrências de um elemento do VectorInt
void vectorint_remove(VectorInt v, int a) {
    if (!v) return;

    int new_size = 0;

    for (int i = 0; i < v->nelements; i++) {
        if (v->data[i] != a) {
            v->data[new_size] = v->data[i];
            new_size++;
        }
    }
    v->nelements = new_size;

    if (v->nelements < v->capacity / 2) {
        int new_capacity = v->capacity / 2;
        int* new_data = realloc(v->data, new_capacity * sizeof(int));
        if (!new_data) {
            printf("Erro ao redimensionar memória\n");
            return;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
}

// Retorna o elemento na posição `i` do VectorInt
int vectorint_at(VectorInt v, int i) {
    if (!v || i < 0 || i >= v->nelements) {
        printf("Índice fora dos limites\n");
        return -1; // Valor de erro
    }
    return v->data[i];
}

// Verifica se um elemento pertence ao VectorInt
bool vectorint_contains(VectorInt v, int a) {
    if (!v) return false;

    for (int i = 0; i < v->nelements; i++) {
        if (v->data[i] == a) {
            return true;
        }
    }
    return false;
}

// Retorna a quantidade de elementos no VectorInt
int vectorint_size(VectorInt v) {
    if (!v) return 0;
    return v->nelements;
}

// Libera a memória ocupada pelo VectorInt
void vectorint_destroy(VectorInt v) {
    if (!v) return;

    free(v->data);
    free(v);
}
