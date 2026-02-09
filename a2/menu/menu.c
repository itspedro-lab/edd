#include "menu.h"

#include <stdio.h>

static int read_choice(int *out)
{
    if (scanf(" %d", out) != 1)
    {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
        return 0;
    }
    return 1;
}

int menu_run(const Menu *menu, void *ctx)
{
    int choice = -1;

    if (!menu || !menu->items || menu->count == 0)
        return -1;

    for (;;)
    {
        printf("\n%s\n", menu->title ? menu->title : "Menu");
        for (size_t i = 0; i < menu->count; ++i)
            printf("%zu. %s\n", i + 1, menu->items[i].label);
        printf("0. Sair\n");
        printf("Opcao: ");

        if (!read_choice(&choice))
            continue;

        if (choice == 0)
            return 0;

        if (choice < 0 || (size_t)choice > menu->count)
            continue;

        if (menu->items[choice - 1].action)
            menu->items[choice - 1].action(ctx);
    }
}
