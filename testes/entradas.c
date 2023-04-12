#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[10];

    printf("\nDigite um dado: (scanf)\n");
    scanf("%c", s);
    fflush(stdin);

    printf("\nDigite um dado: (gets)\n");
    gets(s);
    fflush(stdin);
    
    printf("\nDigite um dado: (fgets)\n");
    fgets(s, 10, stdin);
    fflush(stdin);
    
    printf("\nDigite um dado: (puts)\n");
    puts(s);
    puts("");
    fflush(stdin);

}