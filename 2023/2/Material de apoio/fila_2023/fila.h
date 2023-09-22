#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
 //structs
 //cabeçalho de cada função

typedef struct Tfila{
  int valor;
  struct Tfila *prox;
}Tfila;

typedef struct fila{
 Tfila *inicio;
 Tfila *fim;
}fila;

void   create_fila(fila *f);
fila*  insere_fila(fila *f,int valor);
int    remove_fila(fila *f);
int    fila_vazia(fila *f);
void   mostra_fila(fila *f);




#endif // FILA_H_INCLUDED
