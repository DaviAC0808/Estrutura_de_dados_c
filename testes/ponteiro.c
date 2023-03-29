#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");

    int valor;
    int *ptr1;
    int **ptr2;
    ptr1 = &valor;
    ptr2 = &ptr1;

    printf("Endereço de ptr1 = %x\n", &ptr1);
    printf("Enderço de ptr2 = %x\n", &ptr2);
    printf("Valor do ptr1 = %i\n", *ptr1);
    printf("Valor do ptr2 = %i\n", *ptr2);
}