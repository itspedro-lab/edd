#ifndef BANCO_H
#define BANCO_H

#include <time.h>

#define MAX_CLIENTES 100

typedef struct Cliente
{
    int id;
    double tempo_estimado;
    time_t hora_chegada;
} Cliente;

typedef struct Clientes
{
    Cliente fila[MAX_CLIENTES];
    int inicio;
    int fim;
    int quantidade;

    double total_tempo_atendimento;
    int total_clientes_atendidos;
} Clientes;

void clientes_init(Clientes *clientes);
void inserir_cliente(Clientes *clientes);
void atender_cliente(Clientes *clientes);
void exibir_fila(Clientes *clientes);
void exibir_tempo_total_espera(Clientes *clientes);

#endif
