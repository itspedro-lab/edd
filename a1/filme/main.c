#include <stdio.h>
#include "filme.h"

void run_filme(void)
{
    Filme item;

    printf("Informe titulo: ");
    if (scanf(" %99[^\n]", item.titulo) != 1)
        return;

    printf("Informe genero: ");
    if (scanf(" %49[^\n]", item.genero) != 1)
        return;

    printf("Informe duracao: ");
    if (scanf(" %d", &item.duracao) != 1)
        return;

    printf("\nDados informados:\n");
    printf("titulo: %s\n", item.titulo);
    printf("genero: %s\n", item.genero);
    printf("duracao: %d\n", item.duracao);
}

#ifndef A1_MENU_BUILD
int main(void)
{
    run_filme();
    return 0;
}
#endif /* A1_MENU_BUILD */
