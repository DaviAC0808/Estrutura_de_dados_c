#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;
''
typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

typedef struct Stack
{
    Node *top;
} Stack;

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

int dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int value = q->front->value;
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

void push(Stack *s, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s)
{
    if (s->top == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    int value = s->top->value;
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return value;
}

// void queueToStack(Queue *q, Stack *s)
// {
//     while (q->front != NULL)
//     {
//         push(s, dequeue(q));
//     }
// }

void printQueue(Queue *q)
{
    Node *current = q->front;
    printf("Fila: ");
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void printStack(Stack *s)
{
    Node *current = s->top;
    printf("Pilha: ");
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void clearQueue(Queue *q)
{
    int value;
    while ((value = dequeue(q)) != -1)
    {
        printf("Valor %d removido da fila.\n", value);
    }
}

int main()
{
    Queue q = {NULL, NULL};
    Stack s = {NULL};
    int opcao, valor;
    while (1)
    {
        printf("Escolha uma opcao:\n");
        printf("1 - Inserir valor na fila\n");
        printf("2 - Desenfileirar valor da fila e inserir na pilha\n");
        printf("3 - Imprimir fila e pilha e sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            enqueue(&q, valor);
            printf("Valor %d inserido na fila.\n", valor);
            printQueue(&q); // Adicione esta linha para imprimir a fila ap�s a inser��o
            break;
        case 2:
            valor = dequeue(&q);
            if (valor != -1)
            {
                push(&s, valor);
                printf("Valor %d desenfileirado da fila e inserido na pilha.\n", valor);
            }
            printQueue(&q); // Adicione esta linha para imprimir a fila ap�s a desenfileira��o
            break;
        case 3:
            // queueToStack(&q, &s);
            printf("Valores desenfileirados da fila e inseridos na pilha.\n");
            printQueue(&q);
            printStack(&s);
            return 0;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
}
