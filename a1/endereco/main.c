#include <stdio.h>
#include "endereco.h"

void run_endereco(void)
{
    Endereco item;

    printf("Informe rua: ");
    if (scanf(" %99[^\n]", item.rua) != 1)
        return;

    printf("Informe numero: ");
    if (scanf(" %d", &item.numero) != 1)
        return;

    printf("Informe cidade: ");
    if (scanf(" %99[^\n]", item.cidade) != 1)
        return;

    printf("\nDados informados:\n");
    printf("rua: %s\n", item.rua);
    printf("numero: %d\n", item.numero);
    printf("cidade: %s\n", item.cidade);
}

#ifndef A1_MENU_BUILD
int main(void)
{
    run_endereco();
    return 0;
}
#endif /* A1_MENU_BUILD */
