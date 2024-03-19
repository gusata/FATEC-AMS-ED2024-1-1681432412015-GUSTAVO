#include <stdio.h>

#define TAMANHO_ARRAY 5

// Função para encontrar o maior elemento do array
float encontrar_maior(float *notas) {
    float maior = *notas;
    for (int i = 1; i < TAMANHO_ARRAY; i++) {
        if (*(notas + i) > maior) {
            maior = *(notas + i);
        }
    }
    return maior;
}

// Função para classificar o array em ordem ascendente usando o algoritmo Bubble Sort
void ordenar_ascendente(float *notas) {
    for (int i = 0; i < TAMANHO_ARRAY - 1; i++) {
        for (int j = 0; j < TAMANHO_ARRAY - i - 1; j++) {
            if (*(notas + j) > *(notas + j + 1)) {
                // Trocar os elementos
                float temp = *(notas + j);
                *(notas + j) = *(notas + j + 1);
                *(notas + j + 1) = temp;
            }
        }
    }
}

int main() {
    float notas[TAMANHO_ARRAY];

    // Entrada das notas pelo usuário
    printf("Digite as %d notas:\n", TAMANHO_ARRAY);
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    // Encontrar o maior elemento
    float maior = encontrar_maior(notas);
    printf("O maior elemento do array é: %.2f\n", maior);

    // Classificar o array em ordem ascendente
    ordenar_ascendente(notas);

    // Imprimir o array ordenado
    printf("Array ordenado em ordem ascendente:\n");
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("%.2f ", notas[i]);
    }
    printf("\n");

    return 0;
}