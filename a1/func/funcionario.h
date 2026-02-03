#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

typedef struct Funcionario {
    int matricula;
    char nome[100];
    float salario;
} Funcionario;


void run_funcionario(void);
#endif /* FUNCIONARIO_H */
