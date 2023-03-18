#include <stdio.h>
#include <stdlib.h>

// Define o tamanho máximo das strings para armazenar nomes
#define MAX_NOME 50

// Define a estrutura para um eleitor
typedef struct {
    char nome[MAX_NOME];
    int idade;
    int votou; // Flag para indicar se já votou ou não (0 para não e 1 para sim)
} Eleitor;

// Define a estrutura para um candidato
typedef struct {
    char nome[MAX_NOME];
    char partido[MAX_NOME];
    int num_votos;
} Candidato;

// Função para cadastrar um eleitor
void cadastrar_eleitor(Eleitor *eleitores, int *num_eleitores) {
    if (*num_eleitores == 10) {
        printf("Limite de eleitores cadastrados atingido!\n");
        return;
    }

    printf("Cadastro de Eleitor:\n");
    printf("Digite o nome: ");
    scanf(" %[^\n]", eleitores[*num_eleitores].nome);
    printf("Digite a idade: ");
    scanf("%d", &eleitores[*num_eleitores].idade);
    eleitores[*num_eleitores].votou = 0;

    (*num_eleitores)++;
}

// Função para cadastrar um candidato
void cadastrar_candidato(Candidato *candidatos, int *num_candidatos) {
    if (*num_candidatos == 3) {
        printf("Limite de candidatos cadastrados atingido!\n");
        return;
    }

    printf("Cadastro de Candidato:\n");
    printf("Digite o nome: ");
    scanf(" %[^\n]", candidatos[*num_candidatos].nome);
    printf("Digite o partido: ");
    scanf(" %[^\n]", candidatos[*num_candidatos].partido);
    candidatos[*num_candidatos].num_votos = 0;

    (*num_candidatos)++;
}

// Função para realizar o voto de um eleitor
void votar(Eleitor *eleitores, int num_eleitores, Candidato *candidatos, int num_candidatos) {
    int i, j, voto;

    // Verifica se há eleitores cadastrados
    if (num_eleitores == 0) {
        printf("Não há eleitores cadastrados!\n");
        return;
    }

    // Verifica se todos os eleitores já votaram
    int todos_votaram = 1;
    for (i = 0; i < num_eleitores; i++) {
        if (eleitores[i].votou == 0) {
            todos_votaram = 0;
            break;
        }
    }

    if (todos_votaram) {
        printf("Todos os eleitores já votaram!\n");
        return;
    }

    // Pede para o eleitor escolher um candidato
    printf("Escolha um candidato:\n");
    for (i = 0; i < num_candidatos; i++) {
        printf("%d - %s (%s)\n", i+1, candidatos[i].nome, candidatos[i].partido);
    }
    printf("0 - Voto em branco\n");
    printf("Digite o número do candidato: ");
    scanf("%d", &voto);

    // Verifica se o v
}