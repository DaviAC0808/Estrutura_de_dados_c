#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no
{
    int Vlr;
    struct no *ant;
} no;

typedef struct pilha
{
    no *topo;
} pilha;

void criar(pilha *p)
{
    p->topo = NULL;
}

int verificar(pilha *p)
{
    if (p->topo == NULL)
    {
        printf("\nA pilha está vazia!\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void empilhar(pilha *p, int vlr)
{
    no *novo = malloc(sizeof(no));

    if (novo == NULL)
    {
        // Lidar com erro de alocação de memória, se necessário
        return;
    }

    novo->Vlr = vlr;
    novo->ant = p->topo;
    p->topo = novo;
}

int desempilhar(pilha *p)
{
    if (verificar(p) == 1)
    {
        printf("Pilha vazia\n");
        return -1; // Retorna um valor inválido para indicar erro
    }

    int x;
    no *aux;
    aux = p->topo;
    x = aux->Vlr;
    p->topo = aux->ant;
    aux->ant = NULL;
    free(aux);
    return x;
}

void inverter(pilha *pa, pilha *pb)
{
    while (!verificar(pa))  
    {
        int valor = desempilhar(pa);
        empilhar(pb, valor);
    }
}

void mostrar(pilha *p)
{
    if (verificar(p) == 0)
    {
        no *aux;
        aux = p->topo;

        while (aux != NULL)
        {
            printf("\n %d", aux->Vlr);
            aux = aux->ant;
        }
    }
    else
    {
        printf("Pilha Vazia !!!\n");
    }
}

void menu()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    pilha p1;
    criar(&p1);

    pilha p2;
    criar(&p2);

    int op; // opcao recursiva

    do
    {
        system("cls");
        printf("\n Pilha: \n");
        mostrar(&p1);

        printf("\n\n");
        printf("0 - Sair \n");
        printf("1 - Empilhar \n");
        printf("2 - Desempilhar \n");
        printf("3 - Manipular \n ");

        printf("\n\n Informe a opcao :>_");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            break;

        case 1:
        { // empilhar

            int valor;
            printf("\n Informe um valor\n");
            scanf("%d", &valor);

            empilhar(&p1, valor);

            break;
        }

        case 2:
        { // desempilhando

            int valorDesempilhado = desempilhar(&p1);

            if (valorDesempilhado == -1)
            {
                printf("Pilha vazia\n");
            }
            else
            {
                printf("Valor desempilhado: %d\n", valorDesempilhado);
            }

            break;
        }

        case 3:
        { // manipular

            inverter(&p1, &p2);
            printf("Pilha invertida com sucesso!\n");

            break;
        }
        }

    } while (op != 0);
}

int main()
{
    menu();
    printf("\n\n");
    return 0;
}
