#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no
{
    int Vlr;
    struct no *ant;
}no;

typedef struct Pilha
{
    no *topo;
}pilha;

void validar (pilha *p){
    p->topo = NULL;
}

int verificar(pilha *p){
    if (p->topo == NULL){
        printf("\nA pilha está vazia!");
        return 0;
    }else{
        return 1;
    }
}

void empilhar(pilha *p, int vlr){
    no *novo = malloc(sizeof(no));

    novo->Vlr = vlr;
    novo->ant = p->topo;
    p->topo = novo;

    novo = NULL;
    free(novo);
}

void desempilhar(pilha *p){
    
}

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");
    int;

    printf("\n\n");
    scanf("%", );
}