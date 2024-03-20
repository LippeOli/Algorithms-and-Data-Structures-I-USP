#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int data;
    struct lista* prox;
} celula;

celula* top = NULL;

void imprimir() {
    celula* temp;
    temp = top;
    while (temp != NULL) {
        printf("\n%d\n", temp->data);
        temp = temp->prox;
    }
}

void push(int item) {
    celula* novo = malloc(sizeof(celula));
    novo->data = item;
    novo->prox = top;
    top = novo;
    printf("\nValor %d empilhado", novo->data);
}

bool pop(int data) {
    if (top == NULL) {
        printf("\nA pilha está vazia");
        return 0;  // Indicativo de falha
    } else if (data == top->data) {
        celula* temp;
        temp = top;
        top = top->prox;
        printf("\n%d desempilhado", temp->data);
        free(temp);
        return true;  // Indicativo de sucesso
    } else {
        printf("\nValor a ser removido não está no topo da pilha");
        return false;  // Indicativo de falha
    }
}

int main() {
    int data;
    char op;
    do {
        scanf(" %c", &op);  // Removido espaço em branco para evitar problemas de leitura
        switch (op) {
            case 'i':
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &data);
                push(data);
                imprimir();
                break;
            case 'r':
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &data);
                if (pop(data)) {
                    printf("\nRemovido com sucesso.\n");
                }
                imprimir();
                break;
            default:
                printf("Comando inválido\n");
        }
    } 

    return 0;
}
