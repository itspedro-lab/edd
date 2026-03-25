#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int linhas, colunas;

  printf("Digite o numero de linhas: ");
  if (scanf("%d", &linhas) != 1 || linhas <= 0)
  {
    printf("Numero de linhas invalido.\n");
    return 1;
  }

  printf("Digite o numero de colunas: ");
  if (scanf("%d", &colunas) != 1 || colunas <= 0)
  {
    printf("Numero de colunas invalido.\n");
    return 1;
  }

  int **matriz = malloc((size_t)linhas * sizeof(*matriz));
  if (matriz == NULL)
  {
    printf("Erro ao alocar memoria.\n");
    return 1;
  }

  for (int i = 0; i < linhas; ++i)
  {
    matriz[i] = malloc((size_t)colunas * sizeof(*matriz[i]));
    if (matriz[i] == NULL)
    {
      printf("Erro ao alocar memoria.\n");
      for (int j = 0; j < i; ++j)
      {
        free(matriz[j]);
      }
      free(matriz);
      return 1;
    }
  }

  int maior = 0;

  for (int i = 0; i < linhas; ++i)
  {
    int soma_linha = 0;

    for (int j = 0; j < colunas; ++j)
    {
      printf("Digite o valor para [%d][%d]: ", i, j);
      if (scanf("%d", &matriz[i][j]) != 1)
      {
        printf("Entrada invalida.\n");
        for (int k = 0; k < linhas; ++k)
        {
          free(matriz[k]);
        }
        free(matriz);
        return 1;
      }

      soma_linha += matriz[i][j];

      if ((i == 0 && j == 0) || matriz[i][j] > maior)
      {
        maior = matriz[i][j];
      }
    }

    printf("Soma da linha %d: %d\n", i, soma_linha);
  }

  printf("Maior elemento da matriz: %d\n", maior);

  for (int i = 0; i < linhas; ++i)
  {
    free(matriz[i]);
  }
  free(matriz);

  return 0;
}
