#include <stdio.h>
#include <stdlib.h>

static void imprimir_vetor(const int *vetor, int tamanho)
{
  for (int i = 0; i < tamanho; ++i)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main(void)
{
  int n = 0;

  printf("Digite o tamanho do vetor: ");
  if (scanf("%d", &n) != 1 || n <= 0)
  {
    printf("Valor invalido.\n");
    return 1;
  }

  int *vetor = calloc((size_t)n, sizeof(*vetor));
  if (vetor == NULL)
  {
    printf("Erro ao alocar memoria.\n");
    return 1;
  }

  printf("Vetor apos o calloc: ");
  imprimir_vetor(vetor, n);

  for (int i = 0; i < n; ++i)
  {
    printf("Digite o valor para a posicao %d: ", i);
    if (scanf("%d", &vetor[i]) != 1)
    {
      printf("Entrada invalida.\n");
      free(vetor);
      return 1;
    }
  }

  printf("Vetor atualizado: ");
  imprimir_vetor(vetor, n);

  free(vetor);
  return 0;
}
