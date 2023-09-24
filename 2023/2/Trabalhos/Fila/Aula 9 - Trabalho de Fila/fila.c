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
}no;

typedef struct fila
{
    no *inicio;
    no *fim;
}fila;

typedef struct pilha
{
    no *topo;
}pilha;

void criar_pilha(pilha *p){
    p->topo = NULL;
}

int verificar_pilha(pilha *p){
    if (p->topo == NULL)
    {
        return 0;//pilha vazia
    }else
    {
        return 1;
    }
}

void criar_fila(fila *f){
    f->fim = NULL;
    f->inicio = NULL;
}

int verificar_fila(fila *f){
    if (f->inicio == NULL)
    {
        return 0;//fila vazia
    }else
    {
    return 1;
    }    
}

void inserir(fila *f, int vlr){
    no *novo = malloc(sizeof(no));

    novo->Vlr = vlr;
    novo->prox = NULL;
    
    if (verificar_fila(f) == 0)
    {
        f->fim = novo;
        f->inicio = novo;
    }else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int remover(fila *f){
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

  no *aux = f->inicio;

  while (aux != NULL)
  {
    printf("| %d", aux->Vlr);
    aux = aux->prox;
  }
}

void mostra_pilha(pilha *p)
{

  no *aux = p->topo;

  while (aux != NULL)
  {
    printf("| %d", aux->Vlr);
    aux = aux->prox;
  }
}

void empilhar(pilha *p, int vlr){
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
        inserir(f, valor);
    }

    
    while (verificar_pilha(pb) != 0)
    {
        int valor = desempilhar(pb);
        inserir(f, valor);
    }
}


void menu(){
    fila *f1 = malloc(sizeof(fila));
    criar_fila(f1);

    pilha *p1 = malloc(sizeof(no));
    criar_pilha(p1);

    pilha *p2 = malloc(sizeof(no));
    criar_pilha(p2);

    int valor;  //enfileirado
    int op;    //operacional

    do
    {
        system("cls");
        mostra_fila(f1);
        printf("\n");
        mostra_pilha(p1);
        printf("\n");
        printf("\n============== Fila ==============\n");
        printf("\n0_Sair");
        printf("\n1_Enfileirar");
        printf("\n2_Desenfileirar");
        printf("\n3_Fundindo pilhas em fila");
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

            inserir(f1, valor);
            break;
        case 2:
            printf("2_Desemfileirando e empilhando\n");
            
            fila_pilha(f1, p1);
            mostra_pilha(p1);
            printf("\n");
            system("pause");            
            break;
        case 3:
            printf("\n3_Fundindo pilhas em fila\n");
            
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
    setlocale(LC_ALL,"Portuguese_Brazil");
    menu();

    printf("\n\n");
    //scanf("%", );
}