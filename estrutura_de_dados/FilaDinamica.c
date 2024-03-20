#include <stdio.h>
#include <stdlib.h>

//estrutira de nó
struct No {
    int data;
    struct No* next;
};

struct No* criarNovoNo(int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    if (novoNo == NULL) {
        perror("Erro na alocação de memória");
        exit(EXIT_FAILURE);
    }

    novoNo->data = valor;
    novoNo->next = NULL;
    return novoNo;
}

void inserirValor(struct No** inicio, int valor) {
    struct No* novoNo = criarNovoNo(valor);

    if (*inicio == NULL) {
        *inicio = novoNo;
    } else {
        struct No* atual = *inicio;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = novoNo;
    }
}

void removerValor(struct No** inicio, int valor) {
    struct No* atual = *inicio;
    struct No* anterior = NULL;

    while (atual != NULL && atual->data != valor) {
        anterior = atual;
        atual = atual->next;
    }

    if (atual == NULL) {
        printf("Valor não encontrado na lista.\n");
        return;
    }

    if (anterior == NULL) {
        // Remover o primeiro nó
        *inicio = atual->next;
    } else {
        anterior->next = atual->next;
    }

    free(atual);
}

void imprimirLista(struct No* inicio) {
    struct No* atual = inicio;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

int main() {
    struct No* inicio = NULL;
    int qnt;
    int valor;
    char op;
    
    
    scanf(" %d", &qnt);

    for (int i = 0; i < qnt; i++){
        scanf(" %c", &op);

        if (op == 'r') {
            scanf("%d", &valor);
            removerValor(&inicio, valor);
        } else if (op == 'i') {
            scanf("%d", &valor);
            inserirValor(&inicio, valor);
        } 
    }
    
    imprimirLista(inicio);
        
    // Liberar a memória alocada
    struct No* atual = inicio;
    while (atual != NULL) {
        struct No* temp = atual;
        atual = atual->next;
        free(temp);
    }

    return 0;
}
