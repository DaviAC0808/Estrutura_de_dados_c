#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 5



typedef struct empregado{

    char nome[10];
    char sobrenome[20];
    int nas_dat;
    int rg;
    int adm_dat;
    int sal;

}empregado;

int main(){

    int v_emp;

    printf("\n Informe o numero de empregados da empresa: %i", v_emp);
    scanf("%i",v_emp);

    empregado x[v_emp];

    for(int i=0;i<max;i++){
        printf("\n Nome [%i]: ",v_emp);
        scanf("%i", &x[v_emp].nome);
    }

}

