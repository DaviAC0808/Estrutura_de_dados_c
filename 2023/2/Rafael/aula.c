#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

// 1) Crie um programa em C que faça o seguinte:

// a) Crie  um vetor de tamanho 20 de inteiros
void criandoVetor(int vetor[], int tamanho)
{
    printf("Qual o tamanho do vetor?");
    scanf("%d", &tamanho);
}

// b) Preencha os 10 primeiros valores do vetor com números digitados pelo usuário via teclado
void preencherVetorTeclado(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o valor da posição %d: ", i);
        scanf("%d", &vetor[i]);
    }
}

// c) Preencha os 10 últimos valores do vetor com números aleatórios entre 1 e 100
void preenchaVetorAleatorio(int vetor[], int tamanho, int min, int max)
{
    printf("Qual o valor mínimo? ");
    scanf("%d", &min);

    printf("Qual o valor máximo? ");
    scanf("%d", &max);

    srand(time(NULL)); // inicializa um numero aleatorio a partir da hora do usuário
    for (int i = 0; i < tamanho; i++)
    {
        // vetor[tamanho] = rand() %100; // divide e recebe o resto (menos q 100)
        vetor[tamanho] = (rand() % (max - min + 1)) + min;
    }
}

// d) Mostre o vetor inteiro na tela

void mostrarVetor(int vetor[], int tamanho)
{

    printf("Qual o tamanho do vetor?");
    scanf("%d", &tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        printf("Vetor na posição %d é %d", tamanho, vetor);
    }
}

// e) Mostre o vetor de trás para frente na tela

void mostrarInvVetor(int vetor[], int tamanho)
{

    printf("Qual o tamanho do vetor?");
    scanf("%d", &tamanho);

    for (int i = tamanho; i > tamanho; i--)
    {
        printf("Vetor na posição %d é %d", tamanho, vetor);
    }
}

// f) Calcule e mostre a média dos valores do vetor

// g) Encontre e mostre o maior e o menor valores do vetor

// h) Mostre os valores das posições pares do vetor

// i) Mostre os valores das posições ímpares do vetor

// j) Mostre os valores pares do vetor

// k) Mostre os valores ímpares do vetor

// l)Verifique se há elementos repetidos no vetor e exiba uma mensagem em caso afirmativo

// m) Solicite um valor ao usuário e verifique se esse valor existe no vetor. Se existir exiba a posição em que ele está, senão exiba uma mensagem de valor não encontrado

// n) Solicite dois valores inteiros ao usuário. O programa deve então fazer a troca de todas as ocorrências do 1o valor dentro do vetor pelo 2o valor e mostrar o vetor final na tela.

// o) Verifique se o vetor está em ordem crescente, ou seja, se a[0] <= a[1] <= a[2] <= ... para todos elementos do vetor. Caso estejam, avise o usuário. Caso não estejam, verifique se os dados digitados estão em ordem decrescente. Caso estejam, avise o usuário. Caso não estejam avise-o que o vetor está desordenado.

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int tamanho;
    int min;
    int max;
    int op;
    int valores[tamanho]; // a

    do
    {
        printf("\n======== MENU ========\n");
        printf("0_Sair\n");
        printf("1_a\n");
        printf("2_b\n");
        printf("3_c\n");
        printf("4_d\n");
        printf("5_e\n");
        printf("6_f\n");
        printf("7_g\n");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            /*a)*/ criandoVetor(valores, tamanho);
            break;

        case 2:
            /*b)*/ preencherVetorTeclado(valores, 10);
            break;

        case 3:
            /*c)*/ preenchaVetorAleatorio(valores, tamanho, min, max);
            break;

        case 4:
            /*d)*/ mostrarVetor(valores, tamanho);
            break;

        case 5:
            /*a)*/ preencherVetorTeclado(valores, 10);
            break;

        case 6:
            /*a)*/ preencherVetorTeclado(valores, 10);
            break;

        default:
            break;
        }
    }while (op != 0);

    printf("\n\n");
    // scanf("%", );
}