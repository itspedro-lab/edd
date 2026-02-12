#ifndef ESTOQUE_H
#define ESTOQUE_H

#define MAX_PRODUTOS 100

typedef struct Estoque
{
    int codigos[MAX_PRODUTOS];
    char nomes[MAX_PRODUTOS][100];
    int quantidades[MAX_PRODUTOS];
    int count;
} Estoque;

void estoque_init(Estoque *e);
void cadastrar_produto(Estoque *e);
void atualizar_quantidade(Estoque *e);
void remover_produto(Estoque *e);
void listar_produtos(Estoque *e);

#endif /* ESTOQUE_H */
