#include <stdio.h>
#include <stdlib.h>

// Função que faz a comparação para o  qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int size = 5;
    int IntNumbers[size];

    printf("Insira 5 números:\n");

    for (int i = 0; i < size; ++i) {
        printf("Número %d: ", i + 1);
        scanf("%d", &IntNumbers[i]);
    }

    // Chama a função qsort para ordenar os números
    qsort(IntNumbers, size, sizeof(int), comparar);

    printf("\nOs Números ordenado de forma ascendente são:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", IntNumbers[i]);
    }

    return 0;
}
