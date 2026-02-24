#include <stdio.h>

int buscarMenor(int arr[], int length) {
  int menor = arr[0];
  int menorIdx = 0;  
  for(int i = 0; i < length; i++) {
    if(arr[i] < menor) {
      menor = arr[i];
      menorIdx = i;
    }
  }

  return menorIdx;
}


int buscarMaior(int arr[], int length) {
  int maior = arr[0];
  int maiorIdx = 0;  
  for(int i = 0; i < length; i++) {
    if(arr[i] > maior) {
      maior = arr[i];
      maiorIdx = i;
    }
  }

  return maiorIdx;
}


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

  printf("O maior valor: %d\n", arr[buscarMaior(arr, size)]);
  printf("O menor valor: %d\n", arr[buscarMenor(arr, size)]);


  return 0;
}
