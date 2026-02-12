#include "../../utils/menu/menu.h"

#include "escola.h"

static void action_cadastrar_turma(void *ctx)
{
    cadastrar_turma((Escola *)ctx);
}

static void action_cadastrar_aluno(void *ctx)
{
    cadastrar_aluno((Escola *)ctx);
}

static void action_associar_aluno_turma(void *ctx)
{
    associar_aluno_turma((Escola *)ctx);
}

static void action_listar_alunos_turma(void *ctx)
{
    listar_alunos_turma((Escola *)ctx);
}

int main(void)
{
    Escola escola;
    escola_init(&escola);

    const MenuItem items[] = {
        {"Cadastrar turma", action_cadastrar_turma},
        {"Cadastrar aluno", action_cadastrar_aluno},
        {"Associar aluno a turma", action_associar_aluno_turma},
        {"Listar alunos da turma", action_listar_alunos_turma},
    };
    const Menu menu = {
        "Sistema de Gerenciamento Escolar",
        items,
        sizeof(items) / sizeof(items[0]),
    };

    return menu_run(&menu, &escola);
}
