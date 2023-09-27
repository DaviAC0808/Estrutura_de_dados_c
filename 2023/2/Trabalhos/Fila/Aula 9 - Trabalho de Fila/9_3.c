#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
3. Enquanto uma pilha permite a inserção e a eliminação de elementos em apenas uma extremidade e um fila permite a inserção em uma extremidade e a eliminação na outra extremidade, uma deque (double-ended queue, ou fila de extremidade dupla) permite a inserção e a eliminação em ambas as extremidades. Escreva quatro funções para inserir elementos e eliminar elementos de ambas as extremidades de uma deque construída a partir de um vetor dinâmico.

4.  Escreva funções em linguagem C para: enfileirar e desenfileirar pacientes de uma fila do tipo: FILA_PACIENTES, conforme os
    protótipos abaixo:

    int enfileirar(FILA_PACIENTES *Fila,     PACIENTE  *Paciente)
    Int desenfileirar(FILA_PACIENTES *Fila,     PACIENTE  *Paciente)

    O valor de retorno deve ser igual a 0 quando a operação for bem sucedida, ou iguala 1 quando ocorrer alguma situação em que a operação não possa ser efetuada.
*/

typedef struct no
{
    int Vlr;
    struct no *prox;
} no;

typedef struct deque
{
    no *inic;
    no *fi;
}deque;

void criar_deque(deque *d){
    d->inic = NULL;
    d->fi = NULL;
}

int verifica_inicio_deque(deque *d){
    if (d->inic == NULL)
    {
        return 0;
    }else
    {
        return 1;
    }
}

int verifica_fim_deque(deque *d, int count){
    if (d->fi == count)
    {
        return 0;//deque cheio
    }else
    {
        return 1;
    }
}

void inserir_inicio(deque *d, int vlr)
{
    no *novo = malloc(sizeof(no));

    novo->Vlr = vlr;
    novo->prox = NULL;

    if (verifica_inicio_deque(d) == 0)
    {
        d->inic = novo;
        d->fi = novo;
    }
    else
    {
        d->inic->prox = novo;
        d->inic = novo;
    }
}

void inserir_fim(deque *d, int vlr)
{
    no *novo = malloc(sizeof(no));

    novo->Vlr = vlr;
    novo->prox = NULL;

    if (verifica_fim_deque(d) == 0)
    {
        d->fi = novo;
        d->inic = novo;
    }
    else
    {
        d->fi->prox = novo;
        d->fi = novo;
    }
}

int remover(deque *d)
{
    int x;
    no *aux = malloc(sizeof(no));

    x = f->inicio->Vlr;
    aux = f->inicio;
    f->inicio = aux->prox;

    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }
    free(aux);
    return x;
}

void mostra_deque(deque *d)
{
    if (verifica_inicio_deque(d) == 0)
    {
        printf("Deque vazio!");
    }
    else
    {
        no *aux = d->inic;

        while (aux != NULL)
        {
            printf("| %d", aux->Vlr);
            aux = aux->prox;
        }
    }
}

void mostrar_deque(deque *d, int count){
    if (verifica_fim_deque(d) == 0)
    {
        printf("Deque vazio!");
    }else{
        for (int i = 0; i < count; i++)
        {
            printf("%d", d->inic->Vlr);
        }   
    }
}

void menu()
{
    deque *d1 = malloc(sizeof(deque));
    criar_fila(d1);

    int count; //vetor tamanho
    int valor; // enfileirado
    int op;    // operacional
    int tamanho;

    printf("Digite o tamanho do deque: ");
    scanf("%d", &tamanho);

    count = malloc(sizeof(tamanho));

    do
    {
        system("cls");
        mostra_deque(d1);
        printf("\n");

        printf("\n============== DEQUE ==============\n");
        printf("\n0_Sair");
        printf("\n1_Inserir no início");
        printf("\n1_Inserir no fim");
        printf("\n2_Remover no início");
        printf("\n2_Remover no fim");
        printf("\n\n");

        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("Saindo..\n");
            break;
        case 1:
            printf("\n1_Inserir no início");
            
            inserir_inicio(d1);
            break;
        case 2:
            printf("1_Empilhando pilha_2\n");

            printf("digite o valor a ser empilhado: ");
            scanf("%d", &valor);

            empilhar(p2, valor);
            break;
        case 3:
            printf("\n3_Fundindo pilhas em fila");

            pilhas_para_fila(p1, p2, f1);

            break;
        default:
            break;
        }
    } while (op != 0);

    f1 = NULL;
    p1 = NULL;
    free(f1);
    free(p1);
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    menu();

    printf("\n\n");
    // scanf("%", );
}