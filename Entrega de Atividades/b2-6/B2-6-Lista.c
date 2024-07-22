#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertInLinkedList(Node** head, int value) {
    Node* newNode = createNode(value);
    Node* slow = *head;
    Node* fast = *head;
    Node* prev = NULL;

    // Encontrar o meio da lista
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // Inserir o novo nó no meio
    if (prev != NULL) {
        prev->next = newNode;
    }
    newNode->next = slow;

    // Se a lista estiver vazia
    if (*head == NULL) {
        *head = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = createNode(10);
    head->next = createNode(25);
    head->next->next = createNode(40);
    head->next->next->next = createNode(80);

    int valueToInsert = 30;

    // Tempo inicial
    clock_t start = clock();

    // Inserir valor na lista ligada
    insertInLinkedList(&head, valueToInsert);

    // Tempo final
    clock_t end = clock();

    // Calcular tempo de processamento
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    // Mostrar lista ligada
    printf("Lista ligada após inserção: ");
    printList(head);
    printf("Tempo de processamento: %f segundos\n", time_spent);

    // Liberar memória
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
