#include "../../utils/menu/menu.h"

#include "vendas.h"

static void action_cadastrar_cliente(void *ctx)
{
    cadastrar_cliente((Vendas *)ctx);
}

static void action_cadastrar_produto(void *ctx)
{
    cadastrar_produto((Vendas *)ctx);
}

static void action_criar_venda(void *ctx)
{
    criar_venda((Vendas *)ctx);
}

static void action_listar_vendas(void *ctx)
{
    listar_vendas((Vendas *)ctx);
}

int main(void)
{
    Vendas vendas;
    vendas_init(&vendas);

    const MenuItem items[] = {
        {"Cadastrar cliente", action_cadastrar_cliente},
        {"Cadastrar produto", action_cadastrar_produto},
        {"Criar venda", action_criar_venda},
        {"Listar vendas", action_listar_vendas},
    };
    const Menu menu = {
        "Sistema de Vendas Simples",
        items,
        sizeof(items) / sizeof(items[0]),
    };

    return menu_run(&menu, &vendas);
}
