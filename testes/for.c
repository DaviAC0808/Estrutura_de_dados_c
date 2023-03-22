#include <stdio.h>

int main() {
    int var;

    // Repete até que o usuário digite um número válido
    for (;;) {
        printf("Digite um numero de 0 a 10: ");
        scanf("%d", &var);

        // Verifica se o número está dentro do intervalo permitido
        if (var >= 0 && var <= 10) {
            break; // Sai do loop
        }

        printf("Namero invalido! Tente novamente.\n\n");
    }

    printf("\nO numero %d foi inserido\n", var);
}
