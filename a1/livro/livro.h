#ifndef LIVRO_H
#define LIVRO_H

typedef struct Livro {
    char isbn[20];
    char titulo[100];
    char autor[100];
} Livro;


void run_livro(void);
#endif /* LIVRO_H */
