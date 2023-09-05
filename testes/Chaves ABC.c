#include <stdio.h>
#include <string.h>

// Definir uma estrutura para representar as chaves
struct Chave {
    char nome[50];
    char tipo[20];
    int reserva;
};

// Definir uma estrutura para representar as portas
struct Porta {
    char nome[50];
    char localizacao[100];
    int chave_associada; // Índice da chave associada (-1 para nenhuma)
};

int main() {
    int opcao;
    int num_chaves = 0;
    int num_portas = 0;

    struct Chave chaves[100];
    struct Porta portas[100];

    do {
        printf("Menu:\n");
        printf("1. Adicionar porta\n");
        printf("2. Adicionar chave\n");
        printf("3. Associar chave a porta\n");
        printf("4. Verificar reserva de porta\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Opcao 1 selecionada: Adicionar porta\n");
                // Adicione aqui o código para adicionar uma porta
                if (num_portas < 100) {
                    printf("Nome da porta: ");
                    scanf("%s", portas[num_portas].nome);
                    printf("Localizacao da porta: ");
                    scanf("%s", portas[num_portas].localizacao);
                    portas[num_portas].chave_associada = -1; // Inicialmente, não tem chave associada
                    num_portas++;
                } else {
                    printf("Limite de portas atingido.\n");
                }
                break;
            case 2:
                printf("Opcao 2 selecionada: Adicionar chave\n");
                // Adicione aqui o código para adicionar uma chave
                if (num_chaves < 100) {
                    printf("Nome da chave: ");
                    scanf("%s", chaves[num_chaves].nome);
                    printf("Tipo da chave: ");
                    scanf("%s", chaves[num_chaves].tipo);
                    printf("Reserva da chave (1 para Sim, 0 para Nao): ");
                    scanf("%d", &chaves[num_chaves].reserva);
                    num_chaves++;
                } else {
                    printf("Limite de chaves atingido.\n");
                }
                break;
            case 3:
                printf("Opcao 3 selecionada: Associar chave a porta\n");
                // Adicione aqui o código para associar uma chave a uma porta
                // Por exemplo, você pode pedir ao usuário para escolher uma porta e uma chave para associar.
                break;
            case 4:
                printf("Opcao 4 selecionada: Verificar reserva de porta\n");
                // Adicione aqui o código para verificar a reserva de uma porta
                // Por exemplo, você pode pedir ao usuário para escolher uma porta e verificar se ela tem uma chave com reserva.
                break;
            case 5:
                printf("Opcao 5 selecionada: Saindo do programa\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
