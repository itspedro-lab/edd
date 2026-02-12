#include "../../utils/menu/menu.h"

#include "biblioteca.h"

static void action_cadastrar_usuario(void *ctx)
{
    cadastrar_usuario((Biblioteca *)ctx);
}

static void action_cadastrar_livro(void *ctx)
{
    cadastrar_livro((Biblioteca *)ctx);
}

static void action_registrar_emprestimo(void *ctx)
{
    registrar_emprestimo((Biblioteca *)ctx);
}

static void action_listar_livros_por_usuario(void *ctx)
{
    listar_livros_por_usuario((Biblioteca *)ctx);
}

int main(void)
{
    Biblioteca biblioteca;
    biblioteca_init(&biblioteca);

    const MenuItem items[] = {
        {"Cadastrar usuario", action_cadastrar_usuario},
        {"Cadastrar livro", action_cadastrar_livro},
        {"Registrar emprestimo", action_registrar_emprestimo},
        {"Listar livros por usuario", action_listar_livros_por_usuario},
    };
    const Menu menu = {
        "Sistema de Controle de Biblioteca",
        items,
        sizeof(items) / sizeof(items[0]),
    };

    return menu_run(&menu, &biblioteca);
}
