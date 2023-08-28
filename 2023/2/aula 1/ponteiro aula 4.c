#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void add(int *x, int *y)
{

    *x = 40;
    *y = 80;

    return &x, &y;
}

int main()
{
    int *x, *y;
    setlocale(LC_ALL, "Portuguese_Brazil");
    int *p = malloc(sizeof(int));

    *p = &x; // ponteiro p rescebe o end de x

    printf("\n%d", &x);
    printf("\n%d", &y);

    // printf("\n\n");
    // scanf("%", );
}