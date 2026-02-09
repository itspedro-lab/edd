#include "vendas.h"

#include <stdio.h>

void vendas_init(Vendas *vendas)
{
    if (!vendas)
        return;
    vendas->clientes_count = 0;
    vendas->produtos_count = 0;
    vendas->vendas_count = 0;
}

static int find_cliente_index(const Vendas *vendas, int id)
{
    for (int i = 0; i < vendas->clientes_count; ++i)
    {
        if (vendas->clientes[i].id == id)
            return i;
    }
    return -1;
}

static int find_produto_index(const Vendas *vendas, int codigo)
{
    for (int i = 0; i < vendas->produtos_count; ++i)
    {
        if (vendas->produtos[i].codigo == codigo)
            return i;
    }
    return -1;
}

void cadastrar_cliente(Vendas *vendas)
{
    if (!vendas)
        return;

    if (vendas->clientes_count >= MAX_CLIENTES)
    {
        printf("Limite de clientes atingido.\n");
        return;
    }

    Cliente c;
    printf("ID do cliente: ");
    if (scanf(" %d", &c.id) != 1)
        return;
    printf("Nome do cliente: ");
    if (scanf(" %99[^\n]", c.nome) != 1)
        return;

    if (find_cliente_index(vendas, c.id) >= 0)
    {
        printf("Cliente ja cadastrado.\n");
        return;
    }

    vendas->clientes[vendas->clientes_count++] = c;
    printf("Cliente cadastrado.\n");
}

void cadastrar_produto(Vendas *vendas)
{
    if (!vendas)
        return;

    if (vendas->produtos_count >= MAX_PRODUTOS)
    {
        printf("Limite de produtos atingido.\n");
        return;
    }

    Produto p;
    printf("Codigo do produto: ");
    if (scanf(" %d", &p.codigo) != 1)
        return;
    printf("Nome do produto: ");
    if (scanf(" %99[^\n]", p.nome) != 1)
        return;
    printf("Preco do produto: ");
    if (scanf(" %f", &p.preco) != 1)
        return;

    if (find_produto_index(vendas, p.codigo) >= 0)
    {
        printf("Produto ja cadastrado.\n");
        return;
    }

    vendas->produtos[vendas->produtos_count++] = p;
    printf("Produto cadastrado.\n");
}

void criar_venda(Vendas *vendas)
{
    if (!vendas)
        return;

    if (vendas->vendas_count >= MAX_VENDAS)
    {
        printf("Limite de vendas atingido.\n");
        return;
    }

    int cliente_id = 0;
    printf("ID do cliente: ");
    if (scanf(" %d", &cliente_id) != 1)
        return;

    int cliente_idx = find_cliente_index(vendas, cliente_id);
    if (cliente_idx < 0)
    {
        printf("Cliente nao encontrado.\n");
        return;
    }

    Venda v;
    v.cliente = vendas->clientes[cliente_idx];
    v.quantidade = 0;
    v.total = 0.0f;

    for (;;)
    {
        int codigo = 0;
        printf("Codigo do produto (0 para finalizar): ");
        if (scanf(" %d", &codigo) != 1)
            return;
        if (codigo == 0)
            break;

        int produto_idx = find_produto_index(vendas, codigo);
        if (produto_idx < 0)
        {
            printf("Produto nao encontrado.\n");
            continue;
        }

        if (v.quantidade >= MAX_ITENS_VENDA)
        {
            printf("Limite de itens por venda atingido.\n");
            break;
        }

        v.produtos[v.quantidade++] = vendas->produtos[produto_idx];
        v.total += vendas->produtos[produto_idx].preco;
    }

    vendas->vendas[vendas->vendas_count++] = v;
    printf("Venda registrada. Total: %.2f\n", v.total);
}

void listar_vendas(Vendas *vendas)
{
    if (!vendas)
        return;

    printf("\nVendas registradas: %d\n", vendas->vendas_count);
    for (int i = 0; i < vendas->vendas_count; ++i)
    {
        Venda *v = &vendas->vendas[i];
        printf("%d) Cliente: %s | Itens: %d | Total: %.2f\n",
               i + 1, v->cliente.nome, v->quantidade, v->total);
    }
}
