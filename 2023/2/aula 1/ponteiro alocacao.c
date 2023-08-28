#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct aluno
{
    int cpf;
    char nome[50];
} aluno;

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int *p;
    //* antes da var gera um ponteiro(so guarda end não valor)

    *p = malloc(sizeof(int));

    *p = 10;

    printf("\nValor de p: %d\n", *p);
    printf("\nEnd de onde p aponta: %d\n", p);
    printf("\nEnd de *p: %i\n", &p);

    free (p);//libera espaço de memoria

    printf("%d", p);

    // printf("\n\n");
    // scanf("%", );
    return 0;
}