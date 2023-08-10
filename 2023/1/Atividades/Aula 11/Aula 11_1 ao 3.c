#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node // Cria o valor
{
    int value;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

int vazio(Queue *q)
{
    return q->front == NULL;
}

void printQueue(Queue *q)
{
    if (vazio(q))
    {
        printf("A fila está vazia\n");
        return;
    }

    Node *current = q->front;
    while (current != NULL)
    {
        printf(" %d |", current->value);
        current = current->next;
    }
    printf("\n");
}

int dequeue(Queue *q)
{
    if (vazio(q))
    {
        printf("Erro: a fila está vazia\n");
        return -1;
    }

    Node *temp = q->front;
    int value = temp->value;

    if (q->front == q->rear)
    {
        // Se a fila tiver apenas um elemento
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        // Percorre a fila até chegar ao penúltimo elemento
        while (temp->next != q->rear)
        {
            temp = temp->next;
        }
        // Remove o último elemento
        q->rear = temp;
        temp = temp->next;
        q->rear->next = NULL;
    }

    free(temp);

    return value;
}

int findAndRemove(Queue *q, int value)
{
    if (vazio(q))
    {
        printf("Erro: a fila está vazia\n");
        return 0;
    }

    Node *previous = NULL;
    Node *current = q->front;

    while (current != NULL && current->value != value)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Erro: o valor não foi encontrado na fila\n");
        return 0;
    }

    if (previous == NULL)
    {
        q->front = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    if (q->rear == current)
    {
        q->rear = previous;
    }

    free(current);
    return 1;
}

// enfileirar
void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (q->rear == NULL)
    {
        q->front = newNode;
    }
    else
    {
        q->rear->next = newNode;
    }
    q->rear = newNode;
}

void insertAtPosition(Queue *q, int position, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;

    if (position == 1) {
        newNode->next = q->front;
        q->front = newNode;
        if (q->rear == NULL) {
            q->rear = newNode;
        }
        return;
    }

    Node *previous = NULL;
    Node *current = q->front;
    int i = 1;

    while (current != NULL && i < position) {
        previous = current;
        current = current->next;
        i++;
    }

    if (i < position) {
        newNode->next = NULL;
        q->rear->next = newNode;
        q->rear = newNode;
    } else {
        newNode->next = current;
        previous->next = newNode;
    }
}


int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    Queue q;
    q.front = q.rear = NULL;

    int menu, value, n;
    do
    {
        printf("\n========MENU========");
        printf("\n1_Enfileirar");
        printf("\n2_Remove o ultimo elemento da lista");
        printf("\n3_Encontrar e remover um elemento da lista");
        printf("\n4_Inserir um elemento em um certo lugar da lista");
        printf("\n5_Sair");
        printf("\n====================\n");
        printQueue(&q);
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            printf("Digite um valor a ser enfileirado: ");
            scanf("%d", &value);
            enqueue(&q, value);
            printQueue(&q);
            system("cls");
            break;
        case 2:
            printf("Removendo o ultimo elemento da lista\n");
            dequeue(&q);
            printQueue(&q);
            system("cls");
            break;
        case 3:
            printf("Digite um valor para encontrar e remover da lista: ");
            scanf("%d", &value);
            findAndRemove(&q, value);
            printQueue(&q);
            system("cls");
            break;
        case 4:
            printf("Digite a posição em que deseja inserir um elemento: ");
            scanf("%d", &n);
            printf("Digite um valor a ser inserido: ");
            scanf("%d", &value);
            insertAtPosition(&q, n, value);
            printQueue(&q);
            system("cls");
            break;

        case 5:
            break;
        default:
            printf("Opção inválida!\n");
            system("cls");
            break;
        }
    } while (menu != 5);

    return 0;
}
