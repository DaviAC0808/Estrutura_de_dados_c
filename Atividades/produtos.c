#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

struct Produto {
    int codigo;
    char nome[50];
    float preco;
};

int main() {
    struct Produto produtos[MAX_PRODUTOS];
    int qtd_produtos = 0;

    // Cadastro de produtos
    while (1) {
        int codigo;
        char nome[50];
        float preco;

        printf("Digite o codigo do produto (ou 0 para sair): ");
        scanf("%d", &codigo);

        if (codigo == 0) {
            break;
        }

        // Verifica se o código já foi cadastrado
        int codigo_existente = 0;
        for (int i = 0; i < qtd_produtos; i++) {
            if (produtos[i].codigo == codigo) {
                codigo_existente = 1;
                break;
            }
        }

        if (codigo_existente) {
            printf("Erro: o codigo %d ja foi cadastrado!\n", codigo);
            continue;
        }

        printf("Digite o nome do produto: ");
        scanf(" %[^\n]", nome);

        printf("Digite o preco do produto: ");
        scanf("%f", &preco);

        // Cadastra o novo produto
        struct Produto novo_produto = {codigo, "", preco};
        strcpy(novo_produto.nome, nome);
        produtos[qtd_produtos] = novo_produto;
        qtd_produtos++;

        printf("Produto cadastrado com sucesso!\n");
    }

    printf("\nLista de produtos cadastrados:\n");
    for (int i = 0; i < qtd_produtos; i++) {
        printf("Codigo: %d



}