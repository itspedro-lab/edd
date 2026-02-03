#ifndef CONTA_H
#define CONTA_H

typedef struct Conta {
    int numero;
    char titular[100];
    float saldo;
} Conta;


void run_conta(void);
#endif /* CONTA_H */
