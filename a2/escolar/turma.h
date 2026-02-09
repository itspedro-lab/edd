#ifndef TURMA_H
#define TURMA_H

#include "aluno.h"

#define MAX_ALUNOS_TURMA 50

typedef struct Turma
{
    int codigo;
    char nome[100];
    int quantidade;
    Aluno alunos[MAX_ALUNOS_TURMA];
} Turma;

#endif /* TURMA_H */
