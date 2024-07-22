#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define STACK_SIZE 100

typedef struct {
    double data[STACK_SIZE];
    int top;
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

bool isStackEmpty(Stack *s) {
    return s->top == -1;
}

bool isStackFull(Stack *s) {
    return s->top == STACK_SIZE - 1;
}

void push(Stack *s, double value) {
    if (isStackFull(s)) {
        printf("Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = value;
}

double pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

double calculate(double operand1, double operand2, char operator) {
    switch(operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
            return operand1 / operand2;
        default:
            printf("Error: Invalid operator\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    Stack stack;
    initializeStack(&stack);

    printf("Enter the RPN expression (operands and operators separated by spaces):\n");

    char token;
    double operand1, operand2;

    while (scanf(" %c", &token) == 1) {
        if (token >= '0' && token <= '9') {
            ungetc(token, stdin); // push back the digit
            scanf("%lf", &operand1);
            push(&stack, operand1);
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            if (stack.top < 1) {
                printf("Error: Not enough operands for operator\n");
                exit(EXIT_FAILURE);
            }
            operand2 = pop(&stack);
            operand1 = pop(&stack);
            push(&stack, calculate(operand1, operand2, token));
        }
    }

    if (stack.top != 0) {
        printf("Error: Invalid expression\n");
        exit(EXIT_FAILURE);
    }

    double result = pop(&stack);
    printf("Result: %.2f\n", result);

    return 0;
}
