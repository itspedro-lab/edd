#include "../../utils/menu/menu.h"

#include "estoque.h"

static void action_cadastrar(void *ctx)
{
    cadastrar_produto((Estoque *)ctx);
}

static void action_atualizar(void *ctx)
{
    atualizar_quantidade((Estoque *)ctx);
}

static void action_remover(void *ctx)
{
    remover_produto((Estoque *)ctx);
}

static void action_listar(void *ctx)
{
    listar_produtos((Estoque *)ctx);
}

int main(void)
{
    Estoque estoque;
    estoque_init(&estoque);

    const MenuItem items[] = {
        {"Cadastrar produto", action_cadastrar},
        {"Atualizar quantidade", action_atualizar},
        {"Remover produto", action_remover},
        {"Listar produtos", action_listar},
    };
    const Menu menu = {
        "Controle de Estoque",
        items,
        sizeof(items) / sizeof(items[0]),
    };

    return menu_run(&menu, &estoque);
}
