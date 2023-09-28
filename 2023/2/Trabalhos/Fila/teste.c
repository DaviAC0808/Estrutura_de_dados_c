#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*

1. Implemente uma fun��o que receba uma fila, remova os elementos desta fila em uma pilha;

2. Implemente um fun��o que receba duas pilhas, remova os elementos destas duas pilhas em uma fila;

3. Enquanto uma pilha permite a inser��o e a elimina��o de elementos em apenas uma extremidade e um fila permite a inser��o em uma extremidade e a elimina��o na outra extremidade, uma deque (double-ended queue, ou fila de extremidade dupla) permite a inser��o e a elimina��o em ambas as extremidades. Escreva quatro fun��es para inserir elementos e eliminar elementos de ambas as extremidades de uma deque constru�da a partir de um vetor din�mico.

4.  Escreva fun��es em linguagem C para: enfileirar e desenfileirar pacientes de uma fila do tipo: FILA_PACIENTES, conforme os
    prot�tipos abaixo:

    int enfileirar(FILA_PACIENTES *Fila,     PACIENTE  *Paciente)
    Int desenfileirar(FILA_PACIENTES *Fila,     PACIENTE  *Paciente)

    O valor de retorno deve ser igual a 0 quando a opera��o for bem sucedida, ou iguala 1 quando ocorrer alguma situa��o em que a opera��o n�o possa ser efetuada.
*/

typedef struct no
{
    int Vlr;
    struct no *prox;
} no;

typedef struct fila
{
    no *inicio;
    no *fim;
} fila;

typedef struct pilha
{
    no *topo;
} pilha;

typedef struct deque
{
    int Vlr;
    int tamanho;
    int capassidade;
    no *dinicio;//inicio
    no *dfim//fim
} deque;

void criar_deque(deque *d)
{
    d->dfim = NULL;
    d->dinicio = NULL;
    d->tamanho = 0;
    d->capassidade = 0;
    d->Vlr = 0;
}

int deque_vazio(deque *d)
{
    if (d->tamanho == 0)
    {
        d->dfim = NULL;
        d->dinicio = d->dfim;
        return 0;
    }
    else
    {
        return 1;
    }
}

int deque_cheio(deque *d)
{
    if (d->tamanho >= d->capassidade)
    {
        return 1; // deque cheio
    }
    else
    {
        return 0;
    }
}

void criar_pilha(pilha *p)
{
    p->topo = NULL;
}

int verificar_pilha(pilha *p)
{
    if (p->topo == NULL)
    {
        return 0; // pilha vazia
    }
    else
    {
        return 1;
    }
}

void criar_fila(fila *f)
{
    f->fim = NULL;
    f->inicio = NULL;
}

int verificar_fila(fila *f)
{
    if (f->inicio == NULL)
    {
        return 0; // fila vazia
    }
    else
    {
        return 1;
    }
}

void inserir_fila(fila *f, int vlr)
{
    no *novo = malloc(sizeof(no));

    novo->Vlr = vlr;
    novo->prox = NULL;

    if (verificar_fila(f) == 0)
    {
        f->fim = novo;
        f->inicio = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void inserir_inicio_deque(deque *d, int vlr){
    
    no *novo = malloc(sizeof(no));

    novo->Vlr = vlr;
    novo->prox = NULL;

    if (deque_vazio(d) == 0)
    {
        d->dinicio = novo;
        d->dfim = novo;
    }
    else
    {
        novo->prox = d->dinicio;
        d->dinicio = novo;
    }
}


int remover(fila *f)
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
void mostra_fila(fila *f)
{
    if (verificar_fila(f) == 0)
    {
        printf("Fila vazia!");
    }
    else
    {
        no *aux = f->inicio;

        while (aux != NULL)
        {
            printf("| %d", aux->Vlr);
            aux = aux->prox;
        }
    }
}

void mostra_pilha(pilha *p)
{
    if (verificar_pilha(p) == 0)
    {
        printf("Pilha vazia!");
    }
    else
    {

        no *aux = p->topo;

        while (aux != NULL)
        {
            printf("| %d", aux->Vlr);
            aux = aux->prox;
        }
    }
}

void mostrar_deque(deque *d)
{
    if (deque_vazio(d) == 0)
    {
        printf("Deuque vazio!");
    }
    else
    {
        no *count = d->dinicio;

        while (count != NULL)
        {
            printf("    %d |", count->Vlr);
            count = count->prox;
        }
    }
}

void empilhar(pilha *p, int vlr)
{
    no *novo = malloc(sizeof(no));
    novo->Vlr = vlr;
    novo->prox = p->topo;
    p->topo = novo;
    novo = NULL;
    free(novo);
}

int desempilhar(pilha *p)
{
    if (verificar_pilha(p) == 0)
    {
        printf("Pilha vazia\n");
        return -1; // Retorna um valor inv�lido para indicar erro
    }

    int x;
    no *aux;
    aux = p->topo;
    x = aux->Vlr;
    p->topo = aux->prox;
    aux->prox = NULL;
    free(aux);
    return x;
}

void fila_pilha(fila *f, pilha *p)
{
    int valor;

    while (verificar_fila(f) != 0)
    {
        valor = remover(f);
        empilhar(p, valor);
    }
}

void pilhas_para_fila(pilha *pa, pilha *pb, fila *f)
{
    if (verificar_pilha(pa) == 0 && verificar_pilha(pb) == 0)
    {
        printf("Ambas as pilhas est�o vazias.\n");
        return;
    }

    while (verificar_pilha(pa) != 0)
    {
        int valor = desempilhar(pa);
        inserir_fila(f, valor);
    }

    while (verificar_pilha(pb) != 0)
    {
        int valor = desempilhar(pb);
        inserir_fila(f, valor);
    }
}

void menu_q1()
{
    fila *f1 = malloc(sizeof(fila));
    criar_fila(f1);

    pilha *p1 = malloc(sizeof(pilha));
    criar_pilha(p1);

    pilha *p2 = malloc(sizeof(pilha));
    criar_pilha(p2);

    int valor; // enfileirado
    int op;    // operacional

    do
    {
        system("cls");
        mostra_fila(f1);
        printf("\n");
        mostra_pilha(p1);
        printf("\n============== Quest�o 1 ==============\n");
        printf("\n0_Sair");
        printf("\n1_Enfileirar");
        printf("\n2_Desenfileirar e empilhar");
        // printf("\n3_Fundindo pilhas em fila");
        printf("\n\n");

        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("Saindo..\n");
            break;
        case 1:
            printf("1_Enfileirando\n");

            printf("digite o valor a ser enfileirado: ");
            scanf("%d", &valor);

            inserir_fila(f1, valor);
            break;
        case 2:
            printf("2_Desemfileirando e empilhando\n");

            fila_pilha(f1, p1);
            mostra_pilha(p1);
            printf("\n");
            system("pause");
            break;
        // case 3:
        //     printf("\n3_Fundindo pilhas em fila\n");

        //     pilhas_para_fila(p1, p2, f1);
        //     break;
        default:
            break;
        }
    } while (op != 0);

    f1 = NULL;
    p1 = NULL;
    free(f1);
    free(p1);
}

void menu_q2()
{
    fila *f1 = malloc(sizeof(fila));
    criar_fila(f1);

    pilha *p1 = malloc(sizeof(pilha));
    criar_pilha(p1);

    pilha *p2 = malloc(sizeof(pilha));
    criar_pilha(p2);

    int valor; // enfileirado
    int op;    // operacional

    do
    {
        system("cls");
        mostra_fila(f1);
        printf("\n");
        mostra_pilha(p1);
        printf("\n");
        mostra_pilha(p2);
        printf("\n============== Quest�o 2 ==============\n");
        printf("\n0_Sair");
        printf("\n1_Criar Pilha_1");
        printf("\n2_Criar Pilha_2");
        printf("\n3_Fundindo pilhas em fila");
        printf("\n\n");

        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("Saindo..\n");
            break;
        case 1:
            printf("1_Empilhando pilha_1\n");

            printf("digite o valor a ser empilhado: ");
            scanf("%d", &valor);

            empilhar(p1, valor);
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

void menu_q3()
{

    deque *d1 = malloc(sizeof(deque));
    criar_deque(d1);

    int valor; // enfileirado
    int op;    // operacional

    // capacidade = capacidade(d1);

    do
    {   
        system("cls");
        mostrar_deque(d1);
        printf("\n");
        printf("\n============== Quest�o 3 ==============\n");
        printf("0_ Sair\n");
        printf("1_ Inserir no in�cio\n");
        printf("2_ Inserir no fim\n");
        printf("3_ Remover no in�cio\n");
        printf("4_ Remover no fim\n");
        fflush(stdin);
        scanf("%d", &op);

        printf("\n\n");

        switch (op)
        {
        case 1:
            printf("digite o valor a ser inserido: ");
            fflush(stdin);
            scanf("%d", valor);
            inserir_inicio_deque(d1);
            break;
        case 2:
            inserir_fim_deque(d1);
            break;
        case 3:
            remover_inicio_deque(d1);
            break;
        case 4:
            remover_fim_deque(d1);
            break;
        
        default:
            break;
        }

    } while (op == 0);
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int questao;

    printf("Qual quest�o quer acessar?");
    scanf("%d", &questao);

    switch (questao)
    {
    case 1:
        menu_q1();
        break;

    case 2:
        menu_q2();
        break;

    case 3:
        menu_q3();
        break;

        //  case 4:
        //     menu_q4();
        //     break;

    default:
        break;
    }
    printf("\n\n");
}
