#include <stdio.h>
#include "carro.h"

void run_carro(void)
{
    Carro item;

    printf("Informe placa: ");
    if (scanf(" %14[^\n]", item.placa) != 1)
        return;

    printf("Informe modelo: ");
    if (scanf(" %49[^\n]", item.modelo) != 1)
        return;

    printf("Informe ano: ");
    if (scanf(" %d", &item.ano) != 1)
        return;

    printf("\nDados informados:\n");
    printf("placa: %s\n", item.placa);
    printf("modelo: %s\n", item.modelo);
    printf("ano: %d\n", item.ano);
}

#ifndef A1_MENU_BUILD
int main(void)
{
    run_carro();
    return 0;
}
#endif /* A1_MENU_BUILD */
