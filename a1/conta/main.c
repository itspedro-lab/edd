#include <stdio.h>
#include "conta.h"

void run_conta(void)
{
    Conta item;

    printf("Informe numero: ");
    if (scanf(" %d", &item.numero) != 1)
        return;

    printf("Informe titular: ");
    if (scanf(" %99[^\n]", item.titular) != 1)
        return;

    printf("Informe saldo: ");
    if (scanf(" %f", &item.saldo) != 1)
        return;

    printf("\nDados informados:\n");
    printf("numero: %d\n", item.numero);
    printf("titular: %s\n", item.titular);
    printf("saldo: %.2f\n", item.saldo);
}

#ifndef A1_MENU_BUILD
int main(void)
{
    run_conta();
    return 0;
}
#endif /* A1_MENU_BUILD */
