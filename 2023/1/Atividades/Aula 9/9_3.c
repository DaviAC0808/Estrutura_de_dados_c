#include <stdio.h>
#include <stdlib.h>

typedef struct deque
{
    int *dados;
    int tamanho;
    int capacidade;
    int inicio;
    int fim;
} deque;

deque *criar_deque(int capacidade)
{
    deque *d = (deque *)malloc(sizeof(deque));
    d->dados = (int *)malloc(sizeof(int) * capacidade);
    d->capacidade = capacidade;
    d->tamanho = 0;
    d->inicio = 0;
    d->fim = 0;
    return d;
}

int deque_vazio(deque *d)
{
    return d->tamanho == 0;
}

int deque_cheio(deque *d)
{
    return d->tamanho == d->capacidade;
}

void inserir_inicio(deque *d, int valor)
{
    if (deque_cheio(d))
    {
        printf("Erro: deque cheia\n");
        return;
    }
    d->inicio = (d->inicio - 1 + d->capacidade) % d->capacidade;
    d->dados[d->inicio] = valor;
    d->tamanho++;
}

void inserir_fim(deque *d, int valor)
{
    if (deque_cheio(d))
    {
        printf("Erro: deque cheia\n");
        return;
    }
    d->dados[d->fim] = valor;
    d->fim = (d->fim + 1) % d->capacidade;
    d->tamanho++;
}

int remover_inicio(deque *d)
{
    if (deque_vazio(d))
    {
        printf("Erro: deque vazia\n");
        return -1;
    }
    int valor = d->dados[d->inicio];
    d->inicio = (d->inicio + 1) % d->capacidade;
    d->tamanho--;
    return valor;
}

int remover_fim(deque *d)
{
    if (deque_vazio(d))
    {
        printf("Erro: deque vazia\n");
        return -1;
    }
    d->fim = (d->fim - 1 + d->capacidade) % d->capacidade;
    int valor = d->dados[d->fim];
    d->tamanho--;
    return valor;
}

void exibir_deque(deque *d)
{
    printf("Deque: ");
    int i;
    if (d->fim > d->inicio)
    {
        for (i = d->inicio; i < d->fim; i++)
        {
            printf("%d ", d->dados[i]);
        }
    }
    else
    {
        for (i = d->inicio; i < d->capacidade; i++)
        {
            printf("%d ", d->dados[i]);
        }
        for (i = 0; i < d->fim; i++)
        {
            printf("%d ", d->dados[i]);
        }
    }
    printf("\n");
}

int main()
{
    int capacidade;
    printf("Digite a capacidade da deque: ");
    scanf("%d", &capacidade);
    deque *d = criar_deque(capacidade);

    int opcao, valor;
    while (1)
    {
        exibir_deque(d);
        printf("\n");
        printf("Escolha uma opcao:\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no fim\n");
        printf("3. Remover do inicio\n");
        printf("4. Remover do fim\n");
        printf("5. Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido no inicio: ");
            scanf("%d", &valor);
            inserir_inicio(d, valor);
            system("cls");
            break;
        case 2:
            printf("Digite o valor a ser inserido no fim: ");
            scanf("%d", &valor);
            inserir_fim(d, valor);
            system("cls");
            break;
        case 3:
            valor = remover_inicio(d);
            if (valor != -1)
            {
                printf("Valor removido do inicio: %d\n", valor);
            }
            system("cls");
            break;
        case 4:
            valor = remover_fim(d);
            if (valor != -1)
            {
                printf("Valor removido do fim: %d\n", valor);
            }
            system("cls");
            break;

        case 5:
            printf("Encerrando programa.\n");
            exit(0);

        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    }
}