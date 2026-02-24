#include <stdio.h>


int fib(int n) {
 
  if (n == 0) {
    return 0;
  }
  
  if (n == 1) { 
    return 1;
  }

  return fib(n - 1) + fib(n - 2);
}


int main(void)
{
  int valor;
  printf("Digite o n-esimo termo para fib: ");
  scanf(" %d", &valor);
  printf("%d",fib(valor));
  return 0;
}
