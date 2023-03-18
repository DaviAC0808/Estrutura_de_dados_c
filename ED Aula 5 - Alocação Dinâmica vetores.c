typedef struct Chamada
{
  int custo;
  int tempo_de_espera;
} Chamada;

int main()
{
  int num_chamadas = 10;
  Chamada **chamadas;
  chamadas = (Chamada **)malloc(num_chamadas * sizeof(Chamada *));

  // Preenche o vetor de chamadas com valores aleatórios
  for (int i = 0; i < num_chamadas; i++)
  {
    chamadas[i] = (Chamada *)malloc(sizeof(Chamada));
    chamadas[i]->custo = rand() % 1000; // custo aleatório entre 0 e 999
    chamadas[i]->tempo_de_espera = i;   // tempo de espera igual à ordem de chegada
  }

  // Ordena o vetor de chamadas de acordo com o custo
  void ordenaChamadas(Chamada * chamadas, int nChamadas)
  {
    int i, j;
    Chamada chave;

    for (i = 1; i < nChamadas; i++)
    {
      chave = chamadas[i];
      j = i - 1;

      while (j >= 0 && chamadas[j].custo > chave.custo)
      {
        chamadas[j + 1] = chamadas[j];
        j--;
      }

      chamadas[j + 1] = chave;
    }
  }

  // Realiza o atendimento das chamadas
  for (int i = 0; i < num_chamadas; i++)
  {
    // Atende a chamada
    printf("Atendendo chamada com custo %d e tempo de espera %d\n", chamadas[i]->custo, chamadas[i]->tempo_de_espera);

    // Libera a memória alocada para a chamada
    free(chamadas[i]);
  }

  // Libera a memória alocada para o vetor de chamadas
  free(chamadas);

  return 0;
}

int compara_chamadas(const void *a, const void *b)
{
  Chamada *c1 = *(Chamada **)a;
  Chamada *c2 = *(Chamada **)b;
  if (c1->custo < c2->custo)
  {
    printf("%d \n",*c1);
    printf("%d \n",*c2);
    return -1;
  }
  else if (c1->custo > c2->custo)
  {
    printf("%d \n",*c1);
    printf("%d \n",*c2);
    return 1;
  }
  else
  {
    printf("%d \n",*c1);
    printf("%d \n",*c2);
    return 0;
  }
}
