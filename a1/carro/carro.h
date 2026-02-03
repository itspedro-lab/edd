#ifndef CARRO_H
#define CARRO_H

typedef struct Carro {
    char placa[15];
    char modelo[50];
    int ano;
} Carro;


void run_carro(void);
#endif /* CARRO_H */
