#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int add(int *x, int *y, int result)
{

    *x = 40;
    *y = 80;

    result = *x + *y;

    return result;
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int *p = malloc(sizeof(int));
    int *x = malloc(sizeof(int));
    int *y = malloc(sizeof(int));
    int result;

    result = add(x, y, result);
    *p = &result; // ponteiro p rescebe o end de result

    printf("\n%d", *x);
    printf("\n%d", *y);
    printf("\n%d", *p);
    printf("\n%d", result);

    free(x);
    free(y);
    free(p);

}