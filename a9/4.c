#include <stdio.h>
#include <stdlib.h>

static int alocar_vetor(int **vetor, int tamanho)
{
  *vetor = calloc((size_t)tamanho, sizeof(**vetor));
  return *vetor != NULL;
}

static int preencher_vetor(int *vetor, int tamanho)
{
  for (int i = 0; i < tamanho; ++i)
  {
    printf("Digite o valor para a posicao %d: ", i);
    if (scanf("%d", &vetor[i]) != 1)
    {
      return 0;
    }
  }

  return 1;
}

static void exibir_vetor(const int *vetor, int tamanho)
{
  printf("Vetor: ");
  for (int i = 0; i < tamanho; ++i)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main(void)
{
  int *vetor = NULL;
  int tamanho = 0;

  printf("Digite o tamanho inicial do vetor: ");
  if (scanf("%d", &tamanho) != 1 || tamanho <= 0)
  {
    printf("Tamanho invalido.\n");
    return 1;
  }

  if (!alocar_vetor(&vetor, tamanho))
  {
    printf("Erro ao alocar memoria.\n");
    return 1;
  }

  if (!preencher_vetor(vetor, tamanho))
  {
    printf("Entrada invalida.\n");
    free(vetor);
    return 1;
  }

  exibir_vetor(vetor, tamanho);

  int novo_tamanho = 0;
  printf("Digite o novo tamanho do vetor: ");
  if (scanf("%d", &novo_tamanho) != 1 || novo_tamanho <= 0)
  {
    printf("Tamanho invalido.\n");
    free(vetor);
    return 1;
  }

  int *temp = realloc(vetor, (size_t)novo_tamanho * sizeof(*vetor));
  if (temp == NULL)
  {
    printf("Erro ao realocar memoria.\n");
    free(vetor);
    return 1;
  }
  vetor = temp;

  if (novo_tamanho > tamanho)
  {
    for (int i = tamanho; i < novo_tamanho; ++i)
    {
      vetor[i] = 0;
    }
  }

  printf("Preencha o vetor novamente.\n");
  if (!preencher_vetor(vetor, novo_tamanho))
  {
    printf("Entrada invalida.\n");
    free(vetor);
    return 1;
  }

  exibir_vetor(vetor, novo_tamanho);

  free(vetor);
  return 0;
}
