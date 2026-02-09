#ifndef VENDAS_H
#define VENDAS_H

#include "cliente.h"
#include "produto.h"
#include "venda.h"

#define MAX_CLIENTES 200
#define MAX_PRODUTOS 200
#define MAX_VENDAS 200

typedef struct Vendas
{
    Cliente clientes[MAX_CLIENTES];
    int clientes_count;
    Produto produtos[MAX_PRODUTOS];
    int produtos_count;
    Venda vendas[MAX_VENDAS];
    int vendas_count;
} Vendas;

void vendas_init(Vendas *vendas);
void cadastrar_cliente(Vendas *vendas);
void cadastrar_produto(Vendas *vendas);
void criar_venda(Vendas *vendas);
void listar_vendas(Vendas *vendas);

#endif /* VENDAS_H */
