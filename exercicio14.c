/*
Muitas linguagens possuem uma função chamada map, que é muito útil. Essa função
 geralmente tem a seguinte assinatura map(v, func), onde v é uma coleção de itens e func é uma
 função que será aplicada a cada um dos elementos dessa coleção. Em C, podemos implementar essa
 funcionalidade da seguinte maneira.
*/
#include <stdio.h>

int square(int a);
int cube(int a);
void map(int array[], int n, int (*func)(int));

int main() {
    int vet[5] = {1, 2, 3, 4, 5};
    map(vet, 5, square);
    printf("Quadrado dos elementos:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", vet[i]);
    }

    int vet2[5] = {1, 2, 3, 4, 5};
    map(vet2, 5, cube);
    printf("Cubo dos elementos:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", vet2[i]);
    }

    return 0;
}

int square(int a) {
    return a * a;
}

int cube(int a) {
    return a * a * a;
}

void map(int array[], int n, int (*func)(int)) {
    for (int i = 0; i < n; i++) {
        array[i] = func(array[i]);
    }
}