#include <stdio.h>
#include <time.h>

void insertInArray(int arr[], int size, int value, int position) {
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
}

int main() {
    int arr[6] = {10, 25, 40, 80};
    int size = 4;
    int valueToInsert = 30;
    int position = size / 2;  // Inserir no meio

    // Tempo inicial
    clock_t start = clock();

    // Inserir valor no array
    insertInArray(arr, size, valueToInsert, position);
    size++;

    // Tempo final
    clock_t end = clock();

    // Calcular tempo de processamento
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    // Mostrar array
    printf("Array após inserção: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTempo de processamento: %f segundos\n", time_spent);

    return 0;
}
