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

void criar(fila *f){
    f->fim = NULL;
    f->inicio = NULL;
}

int verificar(fila *f){
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
    
    if (verificar(f) == 0)
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
            break;
        case 2:
            printf("2_Desempilhando");
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