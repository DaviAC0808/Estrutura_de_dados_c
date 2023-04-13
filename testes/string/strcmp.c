#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define N 50

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    char hardtext[N];
    char senha_usr[N];
    int ok;

    printf("Crie uma senha: \n");
    gets(hardtext);

    printf("Digite a senha:\n");
    gets(senha_usr);

    ok = strcmp(hardtext, senha_usr); // confere se os textos são iguais

    if (ok == 0)
    {
        printf("\nSenha correta\n");
    }
    else
    {
        printf("Senha incorreta\n");
    }

    return 0;
}
