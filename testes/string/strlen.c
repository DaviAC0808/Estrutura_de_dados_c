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

    i = strlen(s);//Conta quantos caracteres
    
    printf("\n%d caracteres\n", i);

    printf("\nImpress�o de posi��o:\n");

    for (i = 0; i < strlen(s); i++)
    {
        printf("%c",s[i]);
    }//ou puts(s)
    printf("\n");

    return 0;
}

