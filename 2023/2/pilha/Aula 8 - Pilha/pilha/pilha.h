#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

//structs
typedef struct Tpilha{
  int valor;
  struct Tpilha *ant;//ponteiro anterior
}Tpilha;


typedef struct pilha{
   Tpilha *topo;
}pilha;



//protótipos das funções
void    create_pilha(pilha *p);
int     pilha_vazia(pilha *p);
void    empilha(pilha *p,int valor);
void    mostrar(pilha *p);
void    desempilha(pilha *p);
void    contar_elementos(pilha *p);


#endif // PILHA_H_INCLUDED
