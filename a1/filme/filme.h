#ifndef FILME_H
#define FILME_H

typedef struct Filme {
    char titulo[100];
    char genero[50];
    int duracao;
} Filme;


void run_filme(void);
#endif /* FILME_H */
