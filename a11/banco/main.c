#include "../../utils/menu/menu.h"
#include "banco.h"

static void action_inserir_cliente(void *ctx)
{
    inserir_cliente((Clientes *)ctx);
}

static void action_atender_cliente(void *ctx)
{
    atender_cliente((Clientes *)ctx);
}

static void action_exibir_fila(void *ctx)
{
    exibir_fila((Clientes *)ctx);
}

static void action_exibir_tempo_total_espera(void *ctx)
{
    exibir_tempo_total_espera((Clientes *)ctx);
}

int main(void)
{
    Clientes clientes;
    clientes_init(&clientes);

    const MenuItem items[] = {
        {"Inserir cliente", action_inserir_cliente},
        {"Atender cliente", action_atender_cliente},
        {"Exibir fila de espera", action_exibir_fila},
        {"Exibir tempo total de espera", action_exibir_tempo_total_espera},
    };

    const Menu menu = {
        "Sistema de Banco",
        items,
        sizeof(items) / sizeof(items[0]),
    };

    return menu_run(&menu, &clientes);
}
