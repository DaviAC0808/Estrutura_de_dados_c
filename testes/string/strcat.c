#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define N 20

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");

    char s1[N] = {"L�gica de"};
    char s2[N] = {" Prgrama��o!"};// espa�o antes

    printf("Antes de strcat:\n");
    printf("Str1: %s\n", s1);
    printf("Str2: %s\n", s2);
    
    strcat(s1,s2);//joga o s2 dentro de s1

    printf("\nDepois de strcat:\n");
    puts(s1);
    
    return 0;
}

