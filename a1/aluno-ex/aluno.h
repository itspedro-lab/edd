#ifndef ALUNO_H
#define ALUNO_H

typedef struct Aluno {
    int id;
    char nome[100];
    float nota1;
    float nota2;
    float media;
} Aluno;


void run_aluno_ex(void);
#endif /* ALUNO_H */
