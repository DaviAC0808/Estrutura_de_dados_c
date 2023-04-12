#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura n� para a fila
struct Node {
    int data;
    struct Node* next;
};

// Fun��o para criar um novo n� na fila
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fun��o para inserir um n� no final da fila
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

// Fun��o para remover um n� do in�cio da fila
int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Erro: Fila vazia\n");
        exit(1);
    }
    struct Node* temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return data;
}

// Fun��o para exibir o conte�do da fila
void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Fila vazia\n");
        return;
    }
    printf("Conte�do da fila: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

// Fun��o para remover os elementos das duas pilhas e coloc�-los em uma fila
void removeElementsToQueue(int* stack1, int* stack2, int size1, int size2) {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    for (int i = size1 - 1; i >= 0; i--) {
        enqueue(&front, &rear, stack1[i]);
    }
    for (int i = size2 - 1; i >= 0; i--) {
        enqueue(&front, &rear, stack2[i]);
    }
    displayQueue(front);
}

int main() {
    int size1, size2;
    printf("Digite o tamanho da primeira pilha: ");
    scanf("%d", &size1);
    printf("Digite o tamanho da segunda pilha: ");
    scanf("%d", &size2);

    int* stack1 = (int*)malloc(size1 * sizeof(int));
    int* stack2 = (int*)malloc(size2 * sizeof(int));

    printf("Digite os elementos da primeira pilha: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &stack1[i]);
    }

    printf("Digite os elementos da segunda pilha: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &stack2[i]);
    }

    removeElementsToQueue(stack1, stack2, size1, size2);

    free(stack1);
    free(stack2);

    return 0;
}
