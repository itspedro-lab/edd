#include "escola.h"

#include <stdio.h>

void escola_init(Escola *escola)
{
    if (!escola)
        return;
    escola->alunos_count = 0;
    escola->turmas_count = 0;
}

static int find_aluno_index(const Escola *escola, int id)
{
    for (int i = 0; i < escola->alunos_count; ++i)
    {
        if (escola->alunos[i].id == id)
            return i;
    }
    return -1;
}

static int find_turma_index(const Escola *escola, int codigo)
{
    for (int i = 0; i < escola->turmas_count; ++i)
    {
        if (escola->turmas[i].codigo == codigo)
            return i;
    }
    return -1;
}

void cadastrar_turma(Escola *escola)
{
    if (!escola)
        return;

    if (escola->turmas_count >= MAX_TURMAS)
    {
        printf("Limite de turmas atingido.\n");
        return;
    }

    Turma t;
    printf("Codigo da turma: ");
    if (scanf(" %d", &t.codigo) != 1)
        return;
    printf("Nome da turma: ");
    if (scanf(" %99[^\n]", t.nome) != 1)
        return;
    t.quantidade = 0;

    if (find_turma_index(escola, t.codigo) >= 0)
    {
        printf("Turma ja cadastrada.\n");
        return;
    }

    escola->turmas[escola->turmas_count++] = t;
    printf("Turma cadastrada.\n");
}

void cadastrar_aluno(Escola *escola)
{
    if (!escola)
        return;

    if (escola->alunos_count >= MAX_ALUNOS)
    {
        printf("Limite de alunos atingido.\n");
        return;
    }

    Aluno a;
    printf("ID do aluno: ");
    if (scanf(" %d", &a.id) != 1)
        return;
    printf("Nome do aluno: ");
    if (scanf(" %99[^\n]", a.nome) != 1)
        return;
    printf("Nota do aluno: ");
    if (scanf(" %f", &a.nota) != 1)
        return;

    if (find_aluno_index(escola, a.id) >= 0)
    {
        printf("Aluno ja cadastrado.\n");
        return;
    }

    escola->alunos[escola->alunos_count++] = a;
    printf("Aluno cadastrado.\n");
}

void associar_aluno_turma(Escola *escola)
{
    if (!escola)
        return;

    int id = 0;
    int codigo = 0;

    printf("ID do aluno: ");
    if (scanf(" %d", &id) != 1)
        return;
    printf("Codigo da turma: ");
    if (scanf(" %d", &codigo) != 1)
        return;

    int aluno_idx = find_aluno_index(escola, id);
    int turma_idx = find_turma_index(escola, codigo);

    if (aluno_idx < 0 || turma_idx < 0)
    {
        printf("Aluno ou turma nao encontrado.\n");
        return;
    }

    Turma *t = &escola->turmas[turma_idx];
    if (t->quantidade >= MAX_ALUNOS_TURMA)
    {
        printf("Turma cheia.\n");
        return;
    }

    t->alunos[t->quantidade++] = escola->alunos[aluno_idx];
    printf("Aluno associado a turma.\n");
}

void listar_alunos_turma(Escola *escola)
{
    if (!escola)
        return;

    int codigo = 0;
    printf("Codigo da turma: ");
    if (scanf(" %d", &codigo) != 1)
        return;

    int turma_idx = find_turma_index(escola, codigo);
    if (turma_idx < 0)
    {
        printf("Turma nao encontrada.\n");
        return;
    }

    Turma *t = &escola->turmas[turma_idx];
    printf("\nTurma %s (%d) - %d alunos\n", t->nome, t->codigo, t->quantidade);
    for (int i = 0; i < t->quantidade; ++i)
    {
        printf("%d - %s (nota: %.2f)\n",
               t->alunos[i].id, t->alunos[i].nome, t->alunos[i].nota);
    }
}
