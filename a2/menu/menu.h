#ifndef MENU_H
#define MENU_H

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

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

#ifdef __cplusplus
}
#endif

#endif /* MENU_H */
