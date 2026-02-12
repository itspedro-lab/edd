#include "../../utils/menu/menu.h"

#include "vetor.h"

static void action_ler(void *ctx)
{
    ler_valores((Vetor *)ctx);
}

static void action_mostrar_antes(void *ctx)
{
    exibir_vetor((Vetor *)ctx, "Vetor atual");
}

static void action_remover_repetidos(void *ctx)
{
    remover_repetidos((Vetor *)ctx);
}

static void action_mostrar_depois(void *ctx)
{
    exibir_vetor((Vetor *)ctx, "Vetor compactado");
}

int main(void)
{
    Vetor v;
    vetor_init(&v);

    const MenuItem items[] = {
        {"Ler valores", action_ler},
        {"Mostrar vetor", action_mostrar_antes},
        {"Remover repetidos", action_remover_repetidos},
        {"Mostrar apos compactacao", action_mostrar_depois},
    };
    const Menu menu = {
        "Compactacao e Ordenacao de Vetor",
        items,
        sizeof(items) / sizeof(items[0]),
    };

    return menu_run(&menu, &v);
}
