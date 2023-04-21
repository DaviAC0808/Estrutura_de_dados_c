#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int i;

    if (argc > 1)
    {
        printf("Foram encontrados %d argumentos: ", argc);
        for (i = 0; i < argc; i++)
        {
            printf("%s\n", argv[i]);
        }
    }
    else
    {
        printf("Não forma inseridos argumentos no programa.\n");
    }
}