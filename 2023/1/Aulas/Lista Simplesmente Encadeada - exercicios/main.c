#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  int dado;
  struct no *prox;
} no;

typedef struct lista
{
  no *inicio;
  no *fim;
} lista;

void inicializa_lista(lista *l)
{
  l->inicio = NULL;
  l->fim = NULL;
}

int lista_vazia(lista *l)
{

  if (l->inicio == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void inserir_inicio_lista(lista *l, int valor)
{

  // cria um novo no
  no *novo = malloc(sizeof(no));
  novo->dado = valor;
  novo->prox = NULL;

  if (l->fim == NULL)
  {                   // primeira vez
    l->inicio = novo; // Ajusta-se o inicio
    l->fim = novo;
  }
  else
  {
    novo->prox = l->inicio;
    l->inicio = novo; // ajusta o ponteiro inicio
  }
}

void inserir_fim_lista(lista *l, int valor)
{

  // cria um novo no
  no *novo = malloc(sizeof(no));
  novo->dado = valor;
  novo->prox = NULL;

  if (l->inicio == NULL)
  {                   // primeira vez
    l->inicio = novo; // inicio aponta pro novo no
  }
  else
  {
    l->fim->prox = novo; // Novo nó será apontado pelo último nó da fila
  }
  l->fim = novo; // Ajusta-se o fim
}

int remove_inicio_lista(lista *l)
{

  no *aux = malloc(sizeof(no)); // ponteiro auxiliar
  int y;                        // variável que recebe o valor de retorno

  if (lista_vazia(l) == 1)
  {
    printf("Nao e possivel remover ----");
    printf("Lista Vazia!!\n");
    return 0;
  }
  else
  {
    if (l->inicio == l->fim)
    { // se so tem um unico nó

      aux = l->inicio; // aponta para o nó final
      y = aux->dado;   // passa o valor da struc para a variável
      l->fim = NULL;
      l->inicio = NULL;
      free(aux);
      return (y);
    }
    else
    {

      aux = l->inicio;             // aponta para o nó inicial
      y = aux->dado;               // passa o valor da struc para a variável
      l->inicio = l->inicio->prox; // aponta para a proxima posição
      aux->prox = NULL;
      free(aux); // liberado.
      return (y);
    }
  }
}

int remove_fim_lista(lista *l)
{

  no *aux = malloc(sizeof(no)); // ponteiro auxiliar
  no *ant = malloc(sizeof(no)); // ponteiro anterior
  int y;

  if (l->inicio == l->fim)
  { // se so tem um unico nó

    aux = l->fim;  // aponta para o nó final
    y = aux->dado; // passa o valor da struc para a variável
    l->fim = NULL;
    l->inicio = NULL;
    free(aux);
    free(ant);
    return (y);
  }
  else
  {

    ant = l->inicio;
    aux = l->fim;

    while (ant->prox != l->fim)
    {
      ant = ant->prox; // percorre a lista para no anterior ao fim
    }

    y = aux->dado;

    l->fim = ant;        // passa o final para o anterior
    l->fim->prox = NULL; // desconect ao final
    free(aux);           // free último elemento
    ant = NULL;
    free(ant);
    return y;
  }
}

int busca_valor(lista *l, int valor)
{

  no *aux = malloc(sizeof(no));
  int *end;

  aux = l->inicio;
  int x = 0; // flag

  while (aux != NULL)
  {
    if (aux->dado == valor)
    { // verifica se o valor está na lista
      x = 1;
    }
    aux = aux->prox; // incrementa o ponteiro
  }

  if (x == 1)
  {
    return 1; // valor encontrado
  }
  else
  {
    return 0; // valor não encontrado
  }
}

void mostra_lista(lista *l)
{
  no *aux = malloc(sizeof(no));
  aux = l->inicio;

  while (aux != NULL)
  {
    printf(" | %d ", aux->dado);
    aux = aux->prox; // incrementa o ponteiro
  }
}

void menu()
{
  lista *l = (lista *)malloc(sizeof(lista));
  inicializa_lista(l);

  int op; // opção recursiva

  do
  {
    system("cls");
    printf("\n lista: \n");
    mostra_lista(l);
    printf("\n\n");
    printf("1 - Inserir inicio Lista \n");
    printf("2 - Inserir fim    Lista \n");
    printf("3 - Remover inicio Lista \n");
    printf("4 - Remover fim    Lista \n");
    printf("5 - Remover valor  Lista \n");
    printf("6 - Inserir ordenado Lista \n");
    printf("7 - Imprime recursiva \n");

    printf("8 - Sair \n ");

    printf("\n\n Informe a opcao :>_");
    scanf("%d", &op);

    switch (op)
    {

    case 1:
    {
      int x;

      printf("Informe o valor: ");
      scanf("%d", &x);
      inserir_inicio_lista(l, x);
      break;
    }

    case 2:
    {
      int x;

      printf("Informe o valor: ");
      scanf("%d", &x);
      inserir_fim_lista(l, x);
      break;
    }

    case 3:
    {
      int x;
      if (lista_vazia(l) == 1)
      {
        printf("Nao e possivel remover ----");
        printf("Lista Vazia!!\n");
        break;
      }
      else
      {
        x = remove_inicio_lista(l);
        printf("\n\tValor retirado: %d \n\n", x);
        break;
      }
    }

    case 4:
    {
      int x;
      if (lista_vazia(l) == 1)
      {
        printf("Nao e possivel remover ----");
        printf("Lista Vazia!!\n");
        break;
      }
      else
      {

        x = remove_fim_lista(l);
        printf("\n\tValor retirado: %d \n\n", x);
        break;
      }
    }

    case 5:
    {
      int y, x;

      printf("Informe o valor: ");
      scanf("%d", &x);

      y = busca_valor(l, x);

      if (y == 0)
      {
        printf(" Valor nao encontado na lista \n");
        getch();
        break;
      }
      else
      {
        // y=remove_valor(l,x);
        break;
      }
    }

    case 6:
    {
      int x;

      printf("Informe o valor: ");
      scanf("%d", &x);
      //      insere_ordenado(l,x);
      break;
    }

    case 7:
    {

      no *aux = (no *)malloc(sizeof(no));
      aux = l->inicio;

      //      imprime_recursivo(aux);
      break;
    }

    case 8:
      op = 8;
    }
  } while (op != 8);
}

int main()
{

  menu();
  printf("\n\n");
  return 0;
}
