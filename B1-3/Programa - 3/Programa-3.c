#include <stdio.h>

#define TAMANHO_ARRAY 5

// Função para imprimir todos os elementos do array
void imprimir_array(float *notas) {
    printf("Elementos do array:\n");
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("%.2f ", *(notas + i));
    }
    printf("\n");
}

int main() {
    float notas[TAMANHO_ARRAY];

    // Entrada das notas pelo usuário
    printf("Digite as %d notas:\n", TAMANHO_ARRAY);
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    // Imprimir todos os elementos do array
    imprimir_array(notas);

    return 0;
}
