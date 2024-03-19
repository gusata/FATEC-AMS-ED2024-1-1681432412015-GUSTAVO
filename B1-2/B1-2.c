#include <stdio.h>

// Função para aplicar o desconto
void aplicar_desconto(float *preco, float desconto) {
    *preco = *preco - (*preco * (desconto / 100));
}

int main() {
    float preco, desconto;

    // Solicitar ao usuário que insira o preço do produto
    printf("Insira o preco do produto: ");
    scanf("%f", &preco);

    // Solicitar ao usuário que insira o desconto a ser aplicado
    printf("Insira o desconto a ser aplicado (em %%): ");
    scanf("%f", &desconto);

    // Exibir o preço original
    printf("Preco original: R$ %.2f\n", preco);

    // Aplicar o desconto
    aplicar_desconto(&preco, desconto);

    // Exibir o desconto aplicado e o preço final após o desconto
    printf("Desconto aplicado: %.2f%%\n", desconto);
    printf("Preco final apos o desconto: R$ %.2f\n", preco);

    return 0;
}