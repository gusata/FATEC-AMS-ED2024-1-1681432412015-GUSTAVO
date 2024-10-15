#include <stdio.h>

// Função para implementar o Bubble Sort otimizado
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped; // Variável para verificar se houve troca
    
    for (i = 0; i < n-1; i++) {
        swapped = 0; // Reseta a variável a cada iteração
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca os elementos
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1; // Marca que houve troca
            }
        }
        // Se não houve trocas, o array já está ordenado
        if (swapped == 0)
            break;
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int n;
    
    // Solicitando o número de elementos
    printf("Quantos números deseja ordenar? ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Recebendo os números do usuário
    printf("Insira %d números: \n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Mostra o array original
    printf("Array original: \n");
    printArray(arr, n);

    // Chama a função Bubble Sort otimizado para ordenar
    bubbleSort(arr, n);

    // Mostra o array ordenado
    printf("Array ordenado: \n");
    printArray(arr, n);
    
    return 0;
}
