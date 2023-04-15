#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct data_nas
{
    int dia;
    int mes;
    int ano;
};

typedef struct data_nas data_nas;
struct empregado
{
    char nome[10];
    char sobrenome[20];
    struct data_nas nascimento;
    int rg;
    int dat_admi;
    int salario;
};

typedef struct empregado empregado; // struct_empregado -> empregado

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    empregado str;//renomeia a truct
    int v_emp;
    int conf_data;

    printf("\n Informe o número de empregados da empresa: ");
    scanf("%d", &v_emp);

    for (int i = 0; i < v_emp; i++)
    {
        printf("\n Nome [Max 10 caracteres] [%d]: ", i);
        scanf("%s", &str.nome);

        printf("\n Sobrenome [Max 20 caracteres]: ");
        scanf("%s", &str.sobrenome);

        printf("\n Data de nascimento [DDMMAA]: ");
        scanf("%2d%2d%4d", &str.nascimento.dia, &str.nascimento.mes, &str.nascimento.ano);

        printf("\nData inserida: %02d/%02d/%04d\n", str.nascimento.dia, str.nascimento.mes, str.nascimento.ano);
        printf("As datas conferem? [1=sim/0=não]: ");
        scanf("%d", &conf_data);

        if (conf_data == 1)
        {
            printf("okay");
        }else{
            printf("not okay");
            v_emp++;
        }
        
    }
}