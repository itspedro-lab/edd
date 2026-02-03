#include <stdio.h>
#include "livro.h"

void run_livro(void)
{
    Livro item;

    printf("Informe isbn: ");
    if (scanf(" %19[^\n]", item.isbn) != 1)
        return;

    printf("Informe titulo: ");
    if (scanf(" %99[^\n]", item.titulo) != 1)
        return;

    printf("Informe autor: ");
    if (scanf(" %99[^\n]", item.autor) != 1)
        return;

    printf("\nDados informados:\n");
    printf("isbn: %s\n", item.isbn);
    printf("titulo: %s\n", item.titulo);
    printf("autor: %s\n", item.autor);
}

#ifndef A1_MENU_BUILD
int main(void)
{
    run_livro();
    return 0;
}
#endif /* A1_MENU_BUILD */
