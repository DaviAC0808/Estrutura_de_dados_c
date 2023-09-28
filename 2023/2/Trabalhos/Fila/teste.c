#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*

1. Implemente uma função que receba uma fila, remova os elementos desta fila em uma pilha;

2. Implemente um função que receba duas pilhas, remova os elementos destas duas pilhas em uma fila;

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
        return -1; // Retorna um valor inválido para indicar erro
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
        printf("Ambas as pilhas estão vazias.\n");
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

int deque_vazio(deque *d)
{
    return d->tamanho == 0;
}

int deque_cheio(deque *d)
{
    return d->tamanho == d->capacidade;
}

void inserir_inicio(deque *d, int valor) // Função 1
{
    if (deque_cheio(d))
    {
        printf("Erro: deque cheio\n");
        return;
    }
    d->inicio = (d->inicio - 1 + d->capacidade) % d->capacidade;
    d->dados[d->inicio] = valor;
    d->tamanho++;
}

void inserir_fim(deque *d, int valor) // Função 2
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

int remover_inicio(deque *d) // Função 3
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

int remover_fim(deque *d) // Função 4
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

int menu_q1(int voltar)
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
        printf("\n============== Questão 1 ==============\n");
        printf("\n0_ Voltar");
        printf("\n1_ Enfileirar");
        printf("\n2_ Desenfileirar e empilhar");
        printf("\n\n");

        scanf("%d", &op);

        switch (op)
        {
        case 0:
            voltar = 1;
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
        default:
            break;
        }
    } while (op != 0);

    f1 = NULL;
    p1 = NULL;
    free(f1);
    free(p1);
    return voltar;
}

int menu_q2(int voltar)
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
        printf("\n============== Questão 2 ==============\n");
        printf("\n0_ Voltar");
        printf("\n1_ Criar Pilha_1");
        printf("\n2_ Criar Pilha_2");
        printf("\n3_ Fundindo pilhas em fila");
        printf("\n\n");

        scanf("%d", &op);

        switch (op)
        {
        case 0:
            voltar = 1;
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
    return voltar;
}

int menu_q3(int voltar)
{
    int capacidade;
    
    system("cls");
    printf("Digite a capacidade da deque: ");
    scanf("%d", &capacidade);
    deque *d = criar_deque(capacidade);

    int opcao, valor;
    do{
        printf("\n");
        exibir_deque(d);
        printf("\n============== Questão 3 ==============\n");
        printf("\n");
        printf("0. Voltar\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no fim\n");
        printf("3. Remover do inicio\n");
        printf("4. Remover do fim\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("\nEncerrando programa.\n");
            voltar = 1;
            break;
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

        default:
            printf("Opcao invalida. Tente novamente.\n");
            system("pause");
            break;
        }
    }while (opcao != 0);
    return voltar;
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int questao;
    int voltar = 0;
    do
    {
        system("cls");
        printf("\n============== Aula 9 - Trabalho de Fila ==============\n");
        printf("0_ Sair\n");
        printf("1_ Questão 1\n");
        printf("2_ Questão 2\n");
        printf("3_ Questão 3\n");
        printf("\nQual questão quer acessar?\n");

        scanf("%d", &questao);

        switch (questao)
        {
        case 0:
            printf("Saindo..\n");
            voltar = 1;
            break;

        case 1:
            menu_q1(voltar);
            break;

        case 2:
            menu_q2(voltar);
            break;

        case 3:
            menu_q3(voltar);
            break;

            //  case 4:
            //     menu_q4();
            //     break;

        default:
            printf("\n Questão não encontrada, tente novamente!\n");
            system("pause");
            break;
        }
    } while (voltar == 0);

    printf("\n\n");
}
