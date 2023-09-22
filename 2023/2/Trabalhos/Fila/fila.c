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

void menu(){
    
}

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");
    menu();

    printf("\n\n");
    //scanf("%", );
}