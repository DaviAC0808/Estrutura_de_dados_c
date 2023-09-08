#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Funcionario {
    char nome[50];
    int idade;
    int sexo;
    char cpf[12];
    char data_nascimento[11];
    int codigo_setor;
    char cargo[30];
    float salario;
}funcionario;

int main() {

    setlocale(LC_ALL,"Portuguese_Brazil");

    funcionario *funcionario = malloc(sizeof(funcionario));//aloca dinâmicamente memória pro ponteiro funcionário

    printf("Digite o nome completo do funcionario: ");
    fgets(funcionario->nome, 50, stdin);
    funcionario->nome[strcspn(funcionario->nome, "\n")] = '\0';

    printf("Digite a idade do funcionario: ");
    scanf("%d", &funcionario->idade);

    printf("Digite o sexo do funcionario: \n1_Masculino\n2_Feminino\n");
    scanf("%d", &funcionario->sexo);

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
    switch (funcionario->sexo)
    {
    case 1:
        printf("Sexo: Masculino\n");
        break;
    case 2:
        printf("Sexo: Feminino\n");
        break;
    default:
        printf("Sexo: Opção inválida\n");
        break;
    }
    printf("CPF: %s\n", funcionario->cpf);
    printf("Data de nascimento: %s\n", funcionario->data_nascimento);
    printf("Codigo do setor: %d\n", funcionario->codigo_setor);
    printf("Cargo: %s\n", funcionario->cargo);
    printf("Salario: R$%.2f\n", funcionario->salario);

    free(funcionario);//desaloca memória pro ponteiro funcionário

    return 0;
}
