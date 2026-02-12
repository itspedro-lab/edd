#ifndef MENU_H
#define MENU_H

#include <stddef.h>

typedef void (*MenuAction)(void *ctx);

typedef struct MenuItem
{
    const char *label;
    MenuAction action;
} MenuItem;

typedef struct Menu
{
    const char *title;
    const MenuItem *items;
    size_t count;
} Menu;

int menu_run(const Menu *menu, void *ctx);

#endif /* MENU_H */
