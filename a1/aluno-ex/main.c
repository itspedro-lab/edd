#include <stdio.h>
#include "aluno.h"

void run_aluno_ex(void)
{
    Aluno item;

    printf("Informe id: ");
    if (scanf(" %d", &item.id) != 1)
        return;

    printf("Informe nome: ");
    if (scanf(" %99[^\n]", item.nome) != 1)
        return;

    printf("Informe nota1: ");
    if (scanf(" %f", &item.nota1) != 1)
        return;

    printf("Informe nota2: ");
    if (scanf(" %f", &item.nota2) != 1)
        return;

    printf("Informe media: ");
    if (scanf(" %f", &item.media) != 1)
        return;

    item.media = (item.nota1 + item.nota2) / 2.0f;

    printf("\nDados informados:\n");
    printf("id: %d\n", item.id);
    printf("nome: %s\n", item.nome);
    printf("nota1: %.2f\n", item.nota1);
    printf("nota2: %.2f\n", item.nota2);
    printf("media: %.2f\n", item.media);
    printf("media: %.2f\n", item.media);
}

#ifndef A1_MENU_BUILD
int main(void)
{
    run_aluno_ex();
    return 0;
}
#endif /* A1_MENU_BUILD */
