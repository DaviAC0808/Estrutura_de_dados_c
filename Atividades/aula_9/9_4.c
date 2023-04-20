#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // tamanho máximo da fila

typedef struct
{
    char nome[50];
    int idade;
} PACIENTE;

typedef struct
{
    PACIENTE dados[MAX_SIZE];
    int inicio, fim;
} FILA_PACIENTES;

// função para verificar se a fila está vazia
int vazia(FILA_PACIENTES *fila)
{
    return fila->inicio == fila->fim;
}

// função para verificar se a fila está cheia
int cheia(FILA_PACIENTES *fila)
{
    return fila->fim == MAX_SIZE;
}

// função para enfileirar um paciente
int enfileirar(FILA_PACIENTES *fila, PACIENTE *paciente)
{
    if (cheia(fila))
    {
        printf("Erro: a fila está cheia.\n");
        return 1;
    }

    fila->dados[fila->fim] = *paciente;
    fila->fim++;

    return 0;
}

// função para desenfileirar um paciente
int desenfileirar(FILA_PACIENTES *fila, PACIENTE *paciente)
{
    if (vazia(fila))
    {
        printf("Erro: a fila está vazia.\n");
        return 1;
    }

    *paciente = fila->dados[fila->inicio];
    fila->inicio++;

    return 0;
}

int main()
{
    FILA_PACIENTES fila;
    fila.inicio = fila.fim = 0;
    int n = MAX_SIZE, idade, tam = 0;
    char nome[50];

    printf("Quantos pacientes? \n");
    scanf("%d", &n);
    fflush(stdin);

    do
    {
        printf("Digite o nome do paciente: ");
        scanf("%s", nome);

        printf("Digite a idade do paciente: ");
        scanf("%d", &idade);

        printf("\n");

        PACIENTE p = {"", idade};
        strcpy(p.nome, nome);
        enfileirar(&fila, &p);
        tam++;

    } while (tam < n);

    char confirmacao;
    do
    {
        printf("Deseja remover o um paciente da fila? (s/n): ");
        scanf(" %c", &confirmacao);
        fflush(stdin);

        if (confirmacao == 's' || confirmacao == 'n')
        {
            if (confirmacao == 's')
            {
                PACIENTE paciente_desenfileirado;
                desenfileirar(&fila, &paciente_desenfileirado);
                printf("Paciente desenfileirado: %s, %d anos.\n", paciente_desenfileirado.nome, paciente_desenfileirado.idade);
            }else{
                printf("\nOk\n");
            }
        }
        else if (confirmacao != 'n')
        {
            printf("Opcao invalida. Tente novamente.\n");
        }

    } while (fila.inicio != fila.fim);

    if (fila.inicio == fila.fim)
    {
        printf("A fila esta vazia.\n");
    }

    return 0;
}
