#include "../../utils/menu/menu.h"

#include "nota.h"

static void action_inserir(void *ctx)
{
  inserir_nota((Notas *)ctx);
}

static void action_remover(void *ctx)
{
  remover_nota((Notas *)ctx);
}

static void action_atualizar(void *ctx)
{
  atualizar_nota((Notas *)ctx);
}

static void action_exibir(void *ctx)
{
  exibir_notas((Notas *)ctx);
}

int main(void)
{
  Notas notas;
  notas_init(&notas);

  const MenuItem items[] = {
      {"Inserir nota", action_inserir},
      {"Remover nota", action_remover},
      {"Atualizar nota", action_atualizar},
      {"Exibir notas", action_exibir},
  };
  const Menu menu = {
      "Gerenciamento de Notas",
      items,
      sizeof(items) / sizeof(items[0]),
  };

  return menu_run(&menu, &notas);
}
