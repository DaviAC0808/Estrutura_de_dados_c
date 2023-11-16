#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct dados
{
    char nome;
    int matricula;
    float cpf[11];

} dados;

typedef struct no
{
    dados *Funcionario;
    struct no *prox;
} no;

typedef struct Fila
{
    no *inicio;
    no *fim;
} fila;

void inicializaFila(fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

int verifificarFila(fila *f)
{
    if (f->inicio == NULL)
    {
        f->fim = NULL;
        return 0;
    }
    else
    {
        return 1;
    }
}

void enfileirar(fila *f){
    
}

void menu(){
    int op;

    do
    {
        system("cls");
        printf("\n========= MENU =========\n");    
        printf("0_ Sair");
        printf("1_ Adicionar ID");
        printf("2_ Destruir ID");
        printf("3_ Procurar ID");
        
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            
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