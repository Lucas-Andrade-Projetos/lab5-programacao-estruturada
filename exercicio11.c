/*
Crie um TAD Turma para armazenar o nome de todos os alunos de uma turma. Para
manipular esse tipo, você deverá implementar as seguintes funções:
 
1. turma_matricula(turma, nome) essa função recebe o nome de um aluno a ser inserido na
turma;
2. turma_lista(turma) essa função lista o nome de todos os alunos matriculados em turma.
3. turma_jubila(turma, nome) essa função remove o aluno nome da turma.

A sua função deve ser capaz de lidar com um número arbitrariamente grande de alunos, portanto, você
não pode definir “um número máximo de alunos”.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char nome[100];
    struct aluno* prox;
} Aluno;

typedef struct turma {
    Aluno* primeiro;
} Turma;

Turma* turma_criar();
void turma_matricula(Turma* turma, const char* nome);
void turma_lista(Turma* turma);
void turma_jubila(Turma* turma, const char* nome);

int main() {
    Turma* turma = turma_criar();

    turma_matricula(turma, "Carlos");
    turma_matricula(turma, "Ana");
    turma_matricula(turma, "João");

    printf("Alunos matriculados:\n");
    turma_lista(turma);

    printf("Removendo João:\n");
    turma_jubila(turma, "João");

    printf("Alunos restantes:\n");
    turma_lista(turma);

    free(turma);
    return 0;
}

Turma* turma_criar() {
    Turma* turma = malloc(sizeof(Turma));
    turma->primeiro = NULL;
    return turma;
}

void turma_matricula(Turma* turma, const char* nome) {
    Aluno* novo = malloc(sizeof(Aluno));
    strcpy(novo->nome, nome);
    novo->prox = turma->primeiro;
    turma->primeiro = novo;
}

void turma_lista(Turma* turma) {
    Aluno* atual = turma->primeiro;
    while (atual != NULL) {
        printf("%s\n", atual->nome);
        atual = atual->prox;
    }
}

void turma_jubila(Turma* turma, const char* nome) {
    Aluno* atual = turma->primeiro;
    Aluno* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior == NULL) {
                turma->primeiro = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}