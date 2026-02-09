#ifndef ESCOLA_H
#define ESCOLA_H

#include "aluno.h"
#include "turma.h"

#define MAX_ALUNOS 200
#define MAX_TURMAS 20

typedef struct Escola
{
    Aluno alunos[MAX_ALUNOS];
    int alunos_count;
    Turma turmas[MAX_TURMAS];
    int turmas_count;
} Escola;

void escola_init(Escola *escola);
void cadastrar_turma(Escola *escola);
void cadastrar_aluno(Escola *escola);
void associar_aluno_turma(Escola *escola);
void listar_alunos_turma(Escola *escola);

#endif /* ESCOLA_H */
