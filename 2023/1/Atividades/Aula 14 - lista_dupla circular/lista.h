#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no{
    int dado;
    struct no *prox; //ponteiro do próximo
    struct no *ant;  //ponteiro do anterior
}no;

typedef struct lista{
 no *inicio;
 no *fim;
}lista;

void create_lista(lista *l);
int  lista_vazia(lista *l);
void inserir_ini_lista(lista *l, int valor);
void inserir_fim_lista(lista *l, int valor);
int  remove_ini_lista(lista *l);
int remove_fim_lista(lista *l);
void mostra_lista(lista *l);
int conta_no(lista *l);
int conta_no_maiores(lista *l,int n);
int verifica_repetido(lista *l,int n);

#endif // LISTA_H_INCLUDED
