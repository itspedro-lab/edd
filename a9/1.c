#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  float valor;
  int idx;
} Extremo;

int main(void)
{
  Extremo maior, menor;
  int qnt_alunos = 0;
  float soma;

  printf("Quantidade de alunos: ");
  if (scanf("%d", &qnt_alunos) != 1 || qnt_alunos <= 0)
  {
    printf("Quantidade invalida.");
    return 1;
  }

  float *notas = malloc((size_t)qnt_alunos * sizeof(*notas));
  if (notas == NULL)
  {
    printf("Erro ao alocar memoria.");
    return 1;
  }

  for (int i = 0; i < qnt_alunos; ++i)
  {
    printf("Nota do aluno %d: ", i + 1);
    if (scanf("%f", &notas[i]) != 1 || notas[i] < 0.0f || notas[i] > 10.0f)
    {
      printf("Nota invalida.");
      free(notas);
      return 1;
    }

    soma += notas[i];

    if (i == 0 || notas[i] > maior.valor)
    {
      maior.valor = notas[i];
      maior.idx = i;
    }

    if (i == 0 || notas[i] < menor.valor)
    {
      menor.valor = notas[i];
      menor.idx = i;
    }
  }

  printf("Média das notas: %.2f\n", soma / qnt_alunos);
  printf("O aluno %d tirou a maior nota de %.2f\n", maior.idx + 1, maior.valor);
  printf("O aluno %d tirou a menor nota de %.2f\n", menor.idx + 1, menor.valor);

  free(notas);
  return 0;
}
