#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de paciente
typedef struct {
    char nome[50];
    int idade;
    char motivo[100];
} Paciente;

// Definição da estrutura de nó da fila
typedef struct Node {
    Paciente paciente;
    struct Node* next;
} Node;

// Definição da estrutura de fila
typedef struct {
    Node* front;
    Node* rear;
    int count;
} Fila;

// Função para inicializar uma fila
void inicializarFila(Fila* fila) {
    fila->front = NULL;
    fila->rear = NULL;
    fila->count = 0;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* fila) {
    return (fila->count == 0);
}

// Função para adicionar um paciente à fila
void adicionarPaciente(Fila* fila, Paciente paciente) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro: Não foi possível alocar memória para o novo paciente.\n");
        return;
    }
    novoNode->paciente = paciente;
    novoNode->next = NULL;

    // Se a fila estiver vazia, o novo nó será tanto o primeiro quanto o último
    if (filaVazia(fila)) {
        fila->front = novoNode;
        fila->rear = novoNode;
    } else {
        // Adiciona o novo nó no final da fila e atualiza o rear
        fila->rear->next = novoNode;
        fila->rear = novoNode;
    }
    fila->count++;
}

// Função para remover um paciente da fila
Paciente removerPaciente(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Erro: A fila está vazia.\n");
        // Retorna um paciente vazio
        Paciente pacienteVazio = {"", 0, ""};
        return pacienteVazio;
    } else {
        Node* temp = fila->front;
        Paciente paciente = temp->paciente;
        fila->front = fila->front->next;
        free(temp);
        fila->count--;
        return paciente;
    }
}

// Função para visualizar a fila de pacientes
void visualizarFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia.\n");
    } else {
        Node* current = fila->front;
        printf("Fila de pacientes:\n");
        while (current != NULL) {
            printf("Nome: %s, Idade: %d, Motivo: %s\n", current->paciente.nome, current->paciente.idade, current->paciente.motivo);
            current = current->next;
        }
    }
}

int main() {
    Fila filaNormal;
    Fila filaPrioritaria;
    Fila filaUrgente;

    inicializarFila(&filaNormal);
    inicializarFila(&filaPrioritaria);
    inicializarFila(&filaUrgente);

    // Adiciona alguns pacientes para teste
    Paciente paciente1 = {"Maria", 25, "Febre"};
    Paciente paciente2 = {"João", 70, "Pressão alta"};
    Paciente paciente3 = {"Ana", 30, "Fratura no braço"};
    Paciente paciente4 = {"Pedro", 55, "Dor de cabeça"};
    Paciente paciente5 = {"Luiza", 35, "Consulta de rotina"};

    adicionarPaciente(&filaNormal, paciente1);
    adicionarPaciente(&filaPrioritaria, paciente2);
    adicionarPaciente(&filaUrgente, paciente3);
    adicionarPaciente(&filaNormal, paciente4);
    adicionarPaciente(&filaNormal, paciente5);

    // Visualiza as filas
    printf("Fila Normal:\n");
    visualizarFila(&filaNormal);
    printf("\nFila Prioritária:\n");
    visualizarFila(&filaPrioritaria);
    printf("\nFila Urgente:\n");
    visualizarFila(&filaUrgente);

    return 0;
}
