#ifndef ENDERECO_H
#define ENDERECO_H

typedef struct Endereco {
    char rua[100];
    int numero;
    char cidade[100];
} Endereco;


void run_endereco(void);
#endif /* ENDERECO_H */
