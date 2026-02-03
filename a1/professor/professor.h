#ifndef PROFESSOR_H
#define PROFESSOR_H

typedef struct Professor
{
    int id;
    char nome[100];
    float salario;
} Professor;


void run_professor(void);
#endif /* PROFESSOR_H */
