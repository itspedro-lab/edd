#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct Cliente {
    int id;
    char nome[100];
    char telefone[30];
} Cliente;


void run_cliente(void);
#endif /* CLIENTE_H */
