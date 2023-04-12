#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define N 50

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");

    char s[N];
    int i;

    printf("Digite um texto:\n");
    gets(s);
    i = strlen(s);
    printf("\n%d caracteres\n", i);

    printf("\nImpressão de posição:\n");

    for (i = 0; i < strlen(s); i++)
    {
        printf("%c",s[i]);
    }
    
    return 0;
}

