#include <stdio.h>


int main(void)
{
  int size;
  printf("Qual tamanho do array: ");
  scanf(" %d", &size); 

  int arr[size];

  for (int i = 0; i < size; i++) {
    int v;
    printf("Digite o valor para pos (%d) para o array: ", i + 1);
    scanf(" %d", &v);
    arr[i] = v;
  }

  int idx;

  while (true) {
    printf("Digite um index entre (0 - %d): ", size - 1);
    scanf(" %d", &idx);
    int ch = getchar();
    
    if(idx <= size - 1 && idx >= 0 && ch != "\n" && ch != EOF) {
      break;
    }

    printf("Valor invalido!\n");
  }
  printf("o valor na pos (%d) = %d", idx, arr[idx]);
  return 0;
}
