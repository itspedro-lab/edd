#include <stdio.h>
#include "produto.h"

void run_produto(void)
{
    Produto item;

    printf("Informe codigo: ");
    if (scanf(" %d", &item.codigo) != 1)
        return;

    printf("Informe nome: ");
    if (scanf(" %99[^\n]", item.nome) != 1)
        return;

    printf("Informe preco: ");
    if (scanf(" %f", &item.preco) != 1)
        return;

    printf("\nDados informados:\n");
    printf("codigo: %d\n", item.codigo);
    printf("nome: %s\n", item.nome);
    printf("preco: %.2f\n", item.preco);
}

#ifndef A1_MENU_BUILD
int main(void)
{
    run_produto();
    return 0;
}
#endif /* A1_MENU_BUILD */
