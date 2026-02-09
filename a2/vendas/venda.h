#ifndef VENDA_H
#define VENDA_H

#include "cliente.h"
#include "produto.h"

#define MAX_ITENS_VENDA 20

typedef struct Venda
{
    Cliente cliente;
    Produto produtos[MAX_ITENS_VENDA];
    int quantidade;
    float total;
} Venda;

#endif /* VENDA_H */
