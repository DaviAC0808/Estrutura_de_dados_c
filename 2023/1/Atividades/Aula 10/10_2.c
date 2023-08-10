#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Defini��o da estrutura de um n� da lista encadeada
typedef struct no
{
    int valor;
    struct no *proximo;
} No;

// Defini��o da estrutura da fila de prioridades
typedef struct fila_prioridades
{
    No *inicio;
} Fila_Prioridades;

// Fun��o para criar um novo n�
No *novo_no(int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

// Fun��o para inserir um elemento na fila de prioridades
void inserir(Fila_Prioridades *fila, int valor)
{
    No *novo = novo_no(valor);

    // Caso especial: a fila est� vazia ou o novo valor � maior que o primeiro elemento
    if (fila->inicio == NULL || valor > fila->inicio->valor)
    {
        novo->proximo = fila->inicio;
        fila->inicio = novo;
    }
    else
    {
        // Percorre a lista at� encontrar a posi��o correta para inserir o novo elemento
        No *atual = fila->inicio;
        while (atual->proximo != NULL && atual->proximo->valor >= valor)
        {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
}

int excluir_elemento(Fila_Prioridades *fila, int valor)
{
    // Verifica se a fila est� vazia
    if (fila->inicio == NULL)
    {
        printf("Erro: a fila est� vazia.\n");
        return 1;
    }

    // Caso especial: o elemento a ser exclu�do � o primeiro da fila
    if (fila->inicio->valor == valor)
    {
        No *temp = fila->inicio;
        fila->inicio = fila->inicio->proximo;
        free(temp);
        return 0;
    }

    // Percorre a lista at� encontrar o elemento a ser exclu�do ou chegar ao fim da lista
    No *atual = fila->inicio;
    while (atual->proximo != NULL && atual->proximo->valor != valor)
    {
        atual = atual->proximo;
    }

    // Caso o elemento a ser exclu�do seja encontrado
    if (atual->proximo != NULL)
    {
        No *temp = atual->proximo;
        atual->proximo = temp->proximo;
        free(temp);
        return 0;
    }

    // Caso o elemento a ser exclu�do n�o seja encontrado
    printf("Erro: o elemento %d n�o foi encontrado na fila.\n", valor);
    return 1;
}

// Fun��o para imprimir a fila de prioridades
void imprimir(Fila_Prioridades *fila)
{
    No *atual = fila->inicio;
    printf("Fila de prioridades: ");
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Fila_Prioridades fila;
    fila.inicio = NULL;
    int opcao, valor;

    do
    {
        imprimir(&fila);
        printf("\nEscolha uma op��o:\n");
        printf("1. Inserir elemento\n");
        printf("2. Excluir elemento\n");
        printf("3. Sair\n");
        printf("Op��o: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            inserir(&fila, valor);
            system("cls");
            break;
        case 2:
            printf("Digite o valor a ser exclu�do: ");
            scanf("%d", &valor);
            excluir_elemento(&fila, valor);
            break;
        case 3:
            printf("Encerrando o programa.\n");
            break;
        default:
            printf("Op��o inv�lida. Tente novamente.\n");
            break;
        }
    } while (opcao != 4);

    return 0;
}