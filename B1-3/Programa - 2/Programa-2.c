#include <stdio.h>

#define TAMANHO_ARRAY 5

// Função para calcular a soma de todos os elementos do array
float calcular_soma(float *notas) {
    float soma = 0;
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        soma += *(notas + i);
    }
    return soma;
}

int main() {
    float notas[TAMANHO_ARRAY];

    // Entrada das notas pelo usuário
    printf("Digite as %d notas:\n", TAMANHO_ARRAY);
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    // Calcular a soma de todos os elementos
    float soma = calcular_soma(notas);
    printf("A soma de todos os elementos do array é: %.2f\n", soma);

    return 0;
}
