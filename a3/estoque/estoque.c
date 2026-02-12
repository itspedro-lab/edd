#include "estoque.h"

#include <stdio.h>
#include <string.h>

void estoque_init(Estoque *e)
{
    if (!e)
        return;
    e->count = 0;
}

static int find_produto_index(const Estoque *e, int codigo)
{
    for (int i = 0; i < e->count; ++i)
    {
        if (e->codigos[i] == codigo)
            return i;
    }
    return -1;
}

void cadastrar_produto(Estoque *e)
{
    if (!e)
        return;

    if (e->count >= MAX_PRODUTOS)
    {
        printf("Limite de produtos atingido.");
        return;
    }

    int codigo = 0;
    printf("Codigo do produto: ");
    if (scanf(" %d", &codigo) != 1)
        return;

    if (find_produto_index(e, codigo) >= 0)
    {
        printf("Codigo ja existente.");
        return;
    }

    printf("Nome do produto: ");
    if (scanf(" %99[^\n]", e->nomes[e->count]) != 1)
        return;

    int qtd = 0;
    printf("Quantidade: ");
    if (scanf(" %d", &qtd) != 1)
        return;
    if (qtd < 0)
    {
        printf("Quantidade negativa nao permitida.");
        return;
    }

    e->codigos[e->count] = codigo;
    e->quantidades[e->count] = qtd;
    e->count++;

    printf("Produto cadastrado.");
}

void atualizar_quantidade(Estoque *e)
{
    if (!e || e->count == 0)
    {
        printf("Nao ha produtos cadastrados.");
        return;
    }

    int codigo = 0;
    printf("Codigo do produto: ");
    if (scanf(" %d", &codigo) != 1)
        return;

    int idx = find_produto_index(e, codigo);
    if (idx < 0)
    {
        printf("Produto nao encontrado.");
        return;
    }

    int qtd = 0;
    printf("Nova quantidade: ");
    if (scanf(" %d", &qtd) != 1)
        return;
    if (qtd < 0)
    {
        printf("Quantidade negativa nao permitida.");
        return;
    }

    e->quantidades[idx] = qtd;
    printf("Quantidade atualizada.");
}

void remover_produto(Estoque *e)
{
    if (!e || e->count == 0)
    {
        printf("Nao ha produtos cadastrados.");
        return;
    }

    int codigo = 0;
    printf("Codigo do produto: ");
    if (scanf(" %d", &codigo) != 1)
        return;

    int idx = find_produto_index(e, codigo);
    if (idx < 0)
    {
        printf("Produto nao encontrado.");
        return;
    }

    for (int i = idx; i < e->count - 1; ++i)
    {
        e->codigos[i] = e->codigos[i + 1];
        strcpy(e->nomes[i], e->nomes[i + 1]);
        e->quantidades[i] = e->quantidades[i + 1];
    }
    e->count--;

    printf("Produto removido.");
}

void listar_produtos(Estoque *e)
{
    if (!e || e->count == 0)
    {
        printf("Nao ha produtos cadastrados.");
        return;
    }

    printf("Produtos cadastrados:\n");
    printf("Codigo - Nome (Quantidade)\n");
    for (int i = 0; i < e->count; ++i)
    {
        printf("\n%d - \"%s\" (qtd: %d)", e->codigos[i], e->nomes[i], e->quantidades[i]);
    }
}
