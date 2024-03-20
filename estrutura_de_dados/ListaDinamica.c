#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int data;
    struct No* next;
} No;

typedef struct Fila {
    No* front;
    No* rear;
} Fila;

Fila* inicializarFila() {
    Fila* fila = (struct Fila*)malloc(sizeof(struct Fila));
    fila->front = fila->rear = NULL;
    return fila;
}

int filaVazia(Fila* fila) {
    return fila->front == NULL;
}

void enfileirar(Fila* fila, int data) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->data = data;
    novoNo->next = NULL;
    if (fila->rear == NULL) {
        fila->front = fila->rear = novoNo;
    } else {
        fila->rear->next = novoNo;
        fila->rear = novoNo;
    }
}

bool desenfileirar(Fila* fila, int n) {
    if (filaVazia(fila)) {
        printf("A fila está vazia.\n");
        return false;
    }

    if (fila->front->data == n) {
        No* temp = fila->front;
        fila->front = fila->front->next;
        if (fila->front == NULL) {
            fila->rear = NULL;
        }
        free(temp);
        return true;
    } else {
        printf("Elemento não corresponde ao primeiro da fila ou é inválido.\n");
        return false;
    }
}

void imprimir(Fila* fila) {
    printf("Elementos da fila: ");
    No* temp = fila->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Fila* fila = inicializarFila();

    char command;
    int data;

    while (1) {
        printf("Comandos (r para remover, i para inserir, q para sair): ");
        scanf(" %c", &command);

        if (command == 'q') {
            break;
        }

        switch (command) {
            case 'i':
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &data);
                enfileirar(fila, data);
                imprimir(fila);
                break;
            case 'r':
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &data);
                if (desenfileirar(fila, data)) {
                    printf("Removido com sucesso.\n");
                }
                imprimir(fila);
                break;
            default:
                printf("Comando inválido\n");
        }
    }

    return 0;
}
