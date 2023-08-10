#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista encadeada
typedef struct no {
    int valor;
    struct no* proximo;
} No;

// Definição da estrutura da fila de prioridades
typedef struct fila_prioridades {
    No* inicio;
} Fila_Prioridades;

// Função para criar um novo nó
No* novo_no(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

// Função para inserir um elemento na fila de prioridades
void inserir(Fila_Prioridades* fila, int valor) {
    No* novo = novo_no(valor);

    // Caso especial: a fila está vazia ou o novo valor é maior que o primeiro elemento
    if (fila->inicio == NULL || valor > fila->inicio->valor) {
        novo->proximo = fila->inicio;
        fila->inicio = novo;
    }
    else {
        // Percorre a lista até encontrar a posição correta para inserir o novo elemento
        No* atual = fila->inicio;
        while (atual->proximo != NULL && atual->proximo->valor >= valor) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
}

// Função para imprimir a fila de prioridades
void imprimir(Fila_Prioridades* fila) {
    No* atual = fila->inicio;
    printf("Fila de prioridades: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    Fila_Prioridades fila;
    fila.inicio = NULL;

    int n, valor;
    printf("Quantos elementos deseja inserir? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Digite o valor do elemento %d: ", i+1);
        scanf("%d", &valor);
        inserir(&fila, valor);
        imprimir(&fila);
    }

    return 0;
}
