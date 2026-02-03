#include <stdio.h>
#include "cliente.h"

void run_cliente(void)
{
    Cliente item;

    printf("Informe id: ");
    if (scanf(" %d", &item.id) != 1)
        return;

    printf("Informe nome: ");
    if (scanf(" %99[^\n]", item.nome) != 1)
        return;

    printf("Informe telefone: ");
    if (scanf(" %29[^\n]", item.telefone) != 1)
        return;

    printf("\nDados informados:\n");
    printf("id: %d\n", item.id);
    printf("nome: %s\n", item.nome);
    printf("telefone: %s\n", item.telefone);
}

#ifndef A1_MENU_BUILD
int main(void)
{
    run_cliente();
    return 0;
}
#endif /* A1_MENU_BUILD */
