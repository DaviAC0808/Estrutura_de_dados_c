#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
  0_typedef
  1_cria
  2_verifica
  3_insere
  4_remove
  5_mostra
*/

typedef struct no
{
    int Vlr;
    struct no *prox;
} no;

typedef struct fila_ex
{
    no *inicio;
    no *fim;
} fila;

void criar(fila *f)
{
    f->fim = NULL;
    f->inicio = NULL;
}

int verificar(fila *f)
{
    if (f->inicio == NULL)
    {
        return 1;//fila vazia
    }
    else
    {
        return 0;
    }
}

void inserir(fila *f, int vlr)
{ // inicialza o novo
    no *novo = malloc(sizeof(no));
    novo->Vlr = vlr;
    novo->prox = NULL;

    if (verificar(f) == 1)
    {
        f->inicio = novo;
        f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }

    novo = NULL;
    free(novo);
}

int remover(fila *f)
{
    int x;
    no *aux = malloc(sizeof(no));

    aux = f->inicio;
    f->inicio = aux->prox;
    aux->prox = NULL;

    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }

    x = aux->Vlr;
    free(aux);
    return x;
}

void mostrar(fila *f){

    no *aux = malloc(sizeof(no));
    aux->Vlr = f->inicio->Vlr; 

    while (aux != NULL)
    {
        printf("    | %d ", aux->Vlr);
        aux = aux->prox;
    }
    free(aux);    
}

void menu(){
    fila *f1 = malloc(sizeof(fila));
    criar(f1);


    int valor, op;

    do
    {
        system("cls");
        printf("============== Fila ==============");
        printf("0_Sair");
        printf("1_Enfileirar");
        printf("2_Desenfileirar");
        scanf("%d", &op);


        switch (op)
        {
        case 0:
            printf("Saindo..");
            break;
        case 1:
            printf("1_Empilhndo");
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            inserir(f1, valor);
            break;
        case 2:
            printf("2_Desempilhando");
            printf("Removendo o valor %d", );
            
            break;
        default:
            break;
        }
    } while (op != 0);
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    menu();

    printf("\n\n");
    // scanf("%", );
}