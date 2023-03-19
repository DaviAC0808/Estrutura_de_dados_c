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
    if (eleitores[*num_eleitores].idade < 16) {
        printf("Eleitor deve ter pelo menos 16 anos para votar!\n");
        return;
    }

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
        printf("Nao ha eleitores cadastrados!\n");
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
    printf("Digite o numero do candidato: ");
    scanf("%d", &voto);

    // Verifica se o número do candidato é válido
if (voto < 0 || voto > num_candidatos) {
printf("Numero do candidato invalido!\n");
return;
}

// Verifica se o eleitor já votou
if (eleitores[i].votou == 1) {
    printf("Este eleitor ja votou!\n");
    return;
}

// Incrementa o número de votos do candidato escolhido
candidatos[voto-1].num_votos++;

// Marca que o eleitor já votou
eleitores[i].votou = 1;

printf("Voto registrado com sucesso!\n");
}

// Função para exibir o resultado da eleição
void resultado(Candidato *candidatos, int num_candidatos) {
int i;
int total_votos = 0;


// Calcula o total de votos
for (i = 0; i < num_candidatos; i++) {
    total_votos += candidatos[i].num_votos;
}

// Exibe o resultado da eleição
printf("Resultado da Eleicao:\n");
printf("Total de votos: %d\n", total_votos);
printf("Candidatos:\n");
for (i = 0; i < num_candidatos; i++) {
    printf("%s (%s) - %d votos (%.2f%%)\n", candidatos[i].nome, candidatos[i].partido,
           candidatos[i].num_votos, (float)candidatos[i].num_votos/total_votos*100);
}
}

// Função principal
int main() {
Eleitor eleitores[10];
Candidato candidatos[3];
int num_eleitores = 0;
int num_candidatos = 0;
int opcao;


// Menu de opções
while (1) {
    printf("\n-- Eleicoes --\n");
    printf("1 - Cadastrar Eleitor\n");
    printf("2 - Cadastrar Candidato\n");
    printf("3 - Votar\n");
    printf("4 - Exibir Resultado\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 0:
            printf("Encerrando programa...\n");
            return 0;
        case 1:
            cadastrar_eleitor(eleitores, &num_eleitores);
            break;
        case 2:
            cadastrar_candidato(candidatos, &num_candidatos);
            break;
        case 3:
            votar(eleitores, num_eleitores, candidatos, num_candidatos);
            break;
        case 4:
            resultado(candidatos, num_candidatos);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

return 0;
}