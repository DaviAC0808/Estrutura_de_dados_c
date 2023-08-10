#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista {
    int info;
    Lista* prox;
};

Lista* constroi(int n, int* v) {
    Lista* inicio = NULL;
    Lista* atual = NULL;
    int i;
    for (i = 0; i < n; i++) {
        Lista* novo = (Lista*)malloc(sizeof(Lista));
        novo->info = v[i];
        novo->prox = NULL;
        if (inicio == NULL) {
            inicio = novo;
            atual = novo;
        } else {
            atual->prox = novo;
            atual = novo;
        }
    }
    return inicio;
}

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int* v = (int*)malloc(n * sizeof(int));
    printf("Digite os elementos do vetor:\n");
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    Lista* inicio = constroi(n, v);

    Lista* atual = inicio;
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");

    free(v);
    return 0;
}
