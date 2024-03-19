#include <stdio.h>

#define TAMANHO_ARRAY 5

// Função para modificar todos os elementos do array multiplicando por um valor específico
void multiplicar_array(float *notas, float multiplicador) {
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        *(notas + i) *= multiplicador;
    }
}

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
    float multiplicador;

    // Entrada das notas pelo usuário
    printf("Digite as %d notas:\n", TAMANHO_ARRAY);
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    // Entrada do valor pelo qual deseja multiplicar todos os elementos
    printf("Digite o valor pelo qual deseja multiplicar todos os elementos: ");
    scanf("%f", &multiplicador);

    // Modificar todos os elementos do array multiplicando por um valor específico
    multiplicar_array(notas, multiplicador);

    // Imprimir todos os elementos do array após a modificação
    printf("Array modificado:\n");
    imprimir_array(notas);

    return 0;
}
