#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

// 1) Crie um programa em C que faça o seguinte:

// a) Crie  um vetor de tamanho 20 de inteiros
int vetor[20];

// b) Preencha os 10 primeiros valores do vetor com números digitados pelo usuário via teclado
void preencherVetorTeclado(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o valor da posição %d: ", i);
        scanf("%d", &tamanho);
    }
}

// c) Preencha os 10 últimos valores do vetor com números aleatórios entre 1 e 100
void preenchaVetorAleatorio(int vetor[], int tamanho, int min, int max){
    
    srand(time(NULL));//inicializa um numero aleatorio a partir da hora do usuário
    for (int i = 0; i < tamanho; i++)
    {
        //vetor[tamanho] = rand() %100; // divide e recebe o resto (menos q 100)
        vetor[tamanho] = (rand() %(max - min + 1)) + min;
    }
}

// d) Mostre o vetor inteiro na tela

void mostrarVetor(int vetor[], int tamanho){

    for (int i = 0; i < tamanho; i++)
    {
        printf("Vetor na posição %d é %d", tamanho, vetor);
    }
}

// e) Mostre o vetor de trás para frente na tela

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
    int valores[20];

    /*a)*/preencherVetorTeclado(valores, 10);
    /*b)*/preenchaVetorAleatorio(&valores[10], 10, 1, 100);


    printf("\n\n");
    // scanf("%", );
}