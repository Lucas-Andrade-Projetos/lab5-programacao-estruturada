/*
Seja Aluno a estrutura definida da seguinte forma:
typedef struct _aluno {
	int ra;
	char nome[1000];
	char sexo;
 	int idade;
}* Aluno;
 
Implemente a função char aluno_cmp(Aluno *a, Aluno *b) que recebe dois ponteiros para a
estrutura Aluno e returna 1 se o conteúdo dos alunos apontados por a e b é o mesmo e 0, caso
contrário. Uma observação importante: não estou pedindo para comparar os endereços de a e b, mas
sim os conteúdos desses objetos.
*/

#include <stdio.h>
#include <string.h>

typedef struct _aluno {
    int ra;
    char nome[1000];
    char sexo;
    int idade;
} Aluno;

char aluno_cmp(Aluno* a, Aluno* b);

int main() {
    // Criando dois alunos para comparação
    Aluno aluno1 = {123, "Carlos", 'M', 20};
    Aluno aluno2 = {123, "Carlos", 'M', 20};
    Aluno aluno3 = {124, "Ana", 'F', 22};

    // Comparando os alunos
    if (aluno_cmp(&aluno1, &aluno2)) {
        printf("Alunos 1 e 2 são iguais\n");
    } else {
        printf("Alunos 1 e 2 são diferentes\n");
    }

    if (aluno_cmp(&aluno1, &aluno3)) {
        printf("Alunos 1 e 3 são iguais\n");
    } else {
        printf("Alunos 1 e 3 são diferentes\n");
    }

    return 0;
}

char aluno_cmp(Aluno* a, Aluno* b) {
    if (a->ra == b->ra && 
        strcmp(a->nome, b->nome) == 0 && 
        a->sexo == b->sexo && 
        a->idade == b->idade) {
        return 1;  
    }
    return 0;  
}
