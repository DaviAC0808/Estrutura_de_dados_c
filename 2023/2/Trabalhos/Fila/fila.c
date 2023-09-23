#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

void verificar_pilha(pilha *p){
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

void empilhar(pilha *p, int vlr){
    no *novo = malloc(sizeof(no));
    novo->Vlr = vlr;
    novo->prox = p->topo;
}

int fila_pilha(fila *f, pilha *p)
{
  int valor;

  while (verificar_fila(f))
  {
    valor = remover(f);
    empilhar(p, valor);
  }

  while (verificar_fila(f) != 1)
  {
    valor = remover(f);
    empilhar(p, remover(f));
  }
  return 0;
}

void menu(){
    fila *f1 = malloc(sizeof(fila));
    criar_fila(f1);

    pilha *p1 = malloc(sizeof(no));
    criar_pilha(p1);

    int valor;  //enfileirado
    int x;     //desenfileirado
    int op;    //operacional

    do
    {
        system("cls");
        printf("\n============== Fila ==============\n");
        printf("\n0_Sair");
        printf("\n1_Enfileirar");
        printf("\n2_Desenfileirar\n");
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
            
            x = fila_pilha(f1, p1);

            printf("O vbalor desenfileirado e empilhado foi: %d", x);
            system("pause");
            
            break;
        default:
            break;
        }
    } while (op != 0);
    free(f1);    
}

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");
    menu();

    printf("\n\n");
    //scanf("%", );
}