#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

struct Produto
{
    int codigo;
    char nome[50];
    float preco;
};

int main()
{
    int m;
    int codigo;
    char nome[50];
    float preco;
    int codigo_consulta;

    struct Produto produtos[MAX_PRODUTOS];
    int qtd_produtos = 0;

    while (m != 0)
    {
        printf("\n========= M E N U =========\n");
        printf("1_ Cadastrar Produto: \n");
        printf("2_ Listar Produtos: \n");
        printf("3_ Consultar Produto: \n");
        printf("0_ Sair: \n");
        printf("===========================\n");
        scanf("%d", &m);
        system("cls");

        // Cadastro de produtos
        switch (m)
        {
        case 0:
            break;

        case 1:
            printf("Digite o codigo do produto (ou 0 para sair): ");
            scanf("%d", &codigo);

            if (codigo == 0)
            {
                break;
            }

            // Verifica se o código já foi cadastrado
            int codigo_existente = 0;
            for (int i = 0; i < qtd_produtos; i++)
            {
                if (produtos[i].codigo == codigo)
                {
                    codigo_existente = 1;
                    break;
                }
            }

            if (codigo_existente)
            {
                printf("Erro: o codigo %d já foi cadastrado!\n", codigo);
                break;
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
            break;

        case 2:
            // Lista de Produtos
            printf("\nLista de produtos cadastrados:\n");
            for (int i = 0; i < qtd_produtos; i++)
            {
                printf("Codigo: %d\tNome: %s\n", produtos[i].codigo, produtos[i].nome);
            }
            break;

        case 3:
            // Consulta de preço

            printf("\nDigite o codigo do produto que deseja consultar o preco: ");
            scanf("%d", &codigo_consulta);

            int produto_encontrado = 0;
            for (int i = 0; i < qtd_produtos; i++)
            {
                if (produtos[i].codigo == codigo_consulta)
                {
                    printf("Preco do produto %s: %.2f\n", produtos[i].nome, produtos[i].preco);
                    produto_encontrado = 1;
                    break;
                }
            }

            if (!produto_encontrado)
            {
                printf("Produto nao encontrado!\n");
            }
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }

    return 0;
}
