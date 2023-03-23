#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Funcionario {
    char nome[50];
    int idade;
    char sexo;
    char cpf[12];
    char data_nascimento[11];
    int codigo_setor;
    char cargo[30];
    float salario;
};

int main() {
    struct Funcionario *funcionario;
    funcionario = (struct Funcionario *)malloc(sizeof(struct Funcionario));

    printf("Digite o nome completo do funcionario: ");
    fgets(funcionario->nome, 50, stdin);
    funcionario->nome[strcspn(funcionario->nome, "\n")] = '\0';

    printf("Digite a idade do funcionario: ");
    scanf("%d", &funcionario->idade);

    printf("Digite o sexo do funcionario (M/F): ");
    scanf(" %c", &funcionario->sexo);

    printf("Digite o CPF do funcionario: ");
    scanf(" %[^\n]", funcionario->cpf);

    printf("Digite a data de nascimento do funcionario (dd/mm/aaaa): ");
    scanf(" %[^\n]", funcionario->data_nascimento);

    printf("Digite o codigo do setor onde o funcionario trabalha (0-99): ");
    scanf("%d", &funcionario->codigo_setor);

    printf("Digite o cargo que o funcionario ocupa: ");
    scanf(" %[^\n]", funcionario->cargo);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario->salario);

    printf("\nDados do funcionario cadastrado:\n");
    printf("Nome: %s\n", funcionario->nome);
    printf("Idade: %d\n", funcionario->idade);
    printf("Sexo: %c\n", funcionario->sexo);
    printf("CPF: %s\n", funcionario->cpf);
    printf("Data de nascimento: %s\n", funcionario->data_nascimento);
    printf("Codigo do setor: %d\n", funcionario->codigo_setor);
    printf("Cargo: %s\n", funcionario->cargo);
    printf("Salario: R$%.2f\n", funcionario->salario);

    free(funcionario);

    return 0;
}
