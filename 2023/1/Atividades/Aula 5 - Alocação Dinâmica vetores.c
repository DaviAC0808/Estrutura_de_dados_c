#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    int numero;
    char nome[50];
    int votos;
} Candidato;

typedef struct
{
    int id;
    char nome[50];
    int voto; // Armazena o número do candidato votado. 0 para branco e -1 para nulo.
} Eleitor;

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    int numCandidatos = 3;
    int numEleitores = 10;

    // Alocação dinâmica dos vetores de candidatos e eleitores
    Candidato *candidatos = (Candidato *)malloc(numCandidatos * sizeof(Candidato));
    Eleitor *eleitores = (Eleitor *)malloc(numEleitores * sizeof(Eleitor));

    // Cadastro dos candidatos
    printf("Cadastro de candidatos:\n");
    for (int i = 0; i < numCandidatos; i++)
    {
        printf("Candidato %d:\n", i + 1);
        candidatos[i].numero = i + 1;
        printf("Digite o nome do candidato: ");
        scanf("%s", candidatos[i].nome);
        candidatos[i].votos = 0;
    }

    // Cadastro dos eleitores
    printf("\nCadastro de eleitores:\n");
    for (int i = 0; i < numEleitores; i++)
    {
        printf("Eleitor %d:\n", i + 1);
        eleitores[i].id = i + 1;
        printf("Digite o nome do eleitor: ");
        scanf("%s", eleitores[i].nome);
        eleitores[i].voto = -1;
    }

    // Votação
    int opcao = -1;
    while (opcao != 0)
    {
        printf("\nVotação:\n");
        printf("1 - Votar em um candidato\n");
        printf("2 - Votar em branco\n");
        printf("0 - Encerrar votação\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            // Voto em um candidato
            int numCand;
            printf("\nCandidatos:\n");
            for (int i = 0; i < numCandidatos; i++)
            {
                printf("%d - %s\n", candidatos[i].numero, candidatos[i].nome);
            }
            printf("Digite o número do candidato em que deseja votar: ");
            scanf("%d", &numCand);

            int encontrado = 0;
            for (int i = 0; i < numCandidatos; i++)
            {
                if (candidatos[i].numero == numCand)
                {
                    candidatos[i].votos++;
                    encontrado = 1;
                    break;
                }
            }
            if (encontrado == 0)
            {
                printf("Candidato não encontrado.\n");
            }
            else
            {
                printf("Voto registrado.\n");
            }

            // Registra o voto do eleitor
            printf("Digite o número do eleitor que está votando: ");
            int numEleitor;
            scanf("%d", &numEleitor);
            if (numEleitor < 1 || numEleitor > numEleitores)
            {
                printf("Eleitor não encontrado.\n");
            }
            printf("Voto em branco registrado.\n");
            break;
        }
        else if (opcao != 0)
        {
            printf("Opção inválida.\n");
        }

        // Contabilização dos votos
        int votosBrancos = 0;
        int votosNulos = 0;
        int maiorVotos = -1;
        Candidato vencedor;

        for (int i = 0; i < numCandidatos; i++)
        {
            if (candidatos[i].votos > maiorVotos)
            {
                maiorVotos = candidatos[i].votos;
                vencedor = candidatos[i];
            }
        }

        for (int i = 0; i < numEleitores; i++)
        {
            if (eleitores[i].voto == 0)
            {
                votosBrancos++;
            }
            else if (eleitores[i].voto == -1)
            {
                votosNulos++;
            }
        }

        // Resultados da votação
        printf("\nResultados:\n");
        printf("Votos em branco: %d\n", votosBrancos);
        printf("Votos nulos: %d\n", votosNulos);
        printf("Candidato vencedor: %s com %d votos\n", vencedor.nome, vencedor.votos);

        // Liberação da memória alocada dinamicamente
        free(candidatos);
        free(eleitores);

        return 0;
    }
}
