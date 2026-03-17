#include <stdio.h>

int main(void)
{
  int arr[3][3];
  int input;
  int cur = 0;
  while (cur < 9) {
    printf("Digite um valor: ");
    scanf("%d", &input);
    arr[cur/3][cur%3] = input;
    cur++;
  }
  int len = sizeof(arr) / sizeof(arr[0]);
  int count = 0;
  for(int i = 0; i < len; ++i) {
    for(int j = 0; j < len; ++j) {
      if(arr[i][j] % 2 == 0) count++;
    }
  }
  printf("numeros pares: %d", count);
  return 0;
}

