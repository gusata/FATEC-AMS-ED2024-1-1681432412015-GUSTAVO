#include <stdlib.h>
#include <stdio.h>

// Função para ordenar os números em ordem crescente
void ordenar(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Trocar os elementos
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numeroInteiros[5];
    int i;

    // Entrada dos números
    printf("Digite 5 números inteiros e positivos:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &numeroInteiros[i]);
    }

    // Ordenar os números
    ordenar(numeroInteiros, 5);

    // Mostrar os números ordenados
    printf("Números em ordem crescente:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", numeroInteiros[i]);
    }
    printf("\n");

    return 0;
}
