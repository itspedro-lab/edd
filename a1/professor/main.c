#include <stdio.h>
#include "professor.h"

void run_professor(void)
{
    Professor item;

    printf("Informe id: ");
    if (scanf(" %d", &item.id) != 1)
        return;

    printf("Informe nome: ");
    if (scanf(" %99[^\n]", item.nome) != 1)
        return;

    printf("Informe salario: ");
    if (scanf(" %f", &item.salario) != 1)
        return;

    printf("\nDados informados:\n");
    printf("id: %d\n", item.id);
    printf("nome: %s\n", item.nome);
    printf("salario: %.2f\n", item.salario);
}

#ifndef A1_MENU_BUILD
int main(void)
{
    run_professor();
    return 0;
}
#endif /* A1_MENU_BUILD */
