#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no
{
    int Vlr;
    struct no *ant;
} no;

typedef struct Pilha
{
    no *topo;
} pilha;

void inicializa(pilha *p)
{
    p->topo == NULL;
}

int verifica(pilha *p)
{
    if (p->topo == NULL)
    {
        printf("\nA pilha está vazia!");
        return 0;
    }
    else
    {
        return 1;
    }
}

void empilha(int vlr, pilha *p){
    no *novo=malloc(sizeof(no));

    if (novo)
    {
        novo->Vlr = vlr;
        novo->ant = p->topo;
        p->topo = novo; 
        
        novo = NULL;
        free(novo);
    }else
    {
        printf("\nA alocação dinâmica falhou!")
    }
    
    
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int;

    printf("\n\n");
    scanf("%", );
}