#include <stdio.h>
#include "funcionario.h"

void run_funcionario(void)
{
    Funcionario item;

    printf("Informe matricula: ");
    if (scanf(" %d", &item.matricula) != 1)
        return;

    printf("Informe nome: ");
    if (scanf(" %99[^\n]", item.nome) != 1)
        return;

    printf("Informe salario: ");
    if (scanf(" %f", &item.salario) != 1)
        return;

    printf("\nDados informados:\n");
    printf("matricula: %d\n", item.matricula);
    printf("nome: %s\n", item.nome);
    printf("salario: %.2f\n", item.salario);
}

#ifndef A1_MENU_BUILD
int main(void)
{
    run_funcionario();
    return 0;
}
#endif /* A1_MENU_BUILD */
