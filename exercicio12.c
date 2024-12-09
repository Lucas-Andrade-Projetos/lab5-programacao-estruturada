/*
Questão 12. Modifique o seu TAD VectorInt para que ele seja um vetor dinâmico para qualquer tipo
de dados. Para isso, precisaremos usar o tipo genérico void. Nossa estrutura ficará assim:

typedef struct {
	void** data;
 	int capacity;
 	int nelements;
}* Vector;

Vector vector(void);
void vector_insert(Vector v, void* e);
void vector_remove(Vector v, void* e);
void* vector_at(Vector v, int i);
 
Para passar e utilizar valores para as funções do seu TAD, você precisará ficar convertendo os tipos
de ponteiro (fazer cast), como mostram os exemplos a seguir:

int* a = malloc(sizeof(int));
*a = 10;
int* b = malloc(sizeof(int));
*b = 21;
Vector v = vector();
vector_insert(v, (void*) a);
 ector_insert(v, (void*) b);
int *c = (int*) vector_at(v, 0);
vector_remove(v, (void*) a);
 
Outro exemplo:
 
typedef struct _ponto {
 	int x;
 	int y;
}* Ponto;

Ponto a = malloc(sizeof(_ponto));
a->x = 10; // a->x é equivalente a (*a).x
a->y = 11;
Vector v = vector();
vector_insert(v, (void*) a);
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void** data;
    int capacity;
    int nelements;
}* Vector;

Vector vector();
void vector_resize(Vector v);
void vector_insert(Vector v, void* e);
void vector_remove(Vector v, void* e);
void* vector_at(Vector v, int i);

int main() {
    int* a = malloc(sizeof(int));
    *a = 10;
    int* b = malloc(sizeof(int));
    *b = 21;

    Vector v = vector();
    vector_insert(v, (void*) a);
    vector_insert(v, (void*) b);

    int* c = (int*) vector_at(v, 0);
    printf("Elemento na posição 0: %d\n", *c);

    vector_remove(v, (void*) a);
    c = (int*) vector_at(v, 0);
    printf("Elemento na posição 0 após remoção: %d\n", *c);

    free(a);
    free(b);
    free(v->data);
    free(v);
    return 0;
}

Vector vector() {
    Vector v = malloc(sizeof(*v));
    v->capacity = 4;
    v->nelements = 0;
    v->data = malloc(v->capacity * sizeof(void*));
    return v;
}

void vector_resize(Vector v) {
    v->capacity *= 2;
    v->data = realloc(v->data, v->capacity * sizeof(void*));
}

void vector_insert(Vector v, void* e) {
    if (v->nelements == v->capacity) {
        vector_resize(v);
    }
    v->data[v->nelements++] = e;
}

void vector_remove(Vector v, void* e) {
    for (int i = 0; i < v->nelements; i++) {
        if (v->data[i] == e) {
            for (int j = i; j < v->nelements - 1; j++) {
                v->data[j] = v->data[j + 1];
            }
            v->nelements--;
            return;
        }
    }
}

void* vector_at(Vector v, int i) {
    if (i >= 0 && i < v->nelements) {
        return v->data[i];
    }
    return NULL;
}
