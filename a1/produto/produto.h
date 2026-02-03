#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct Produto {
    int codigo;
    char nome[100];
    float preco;
} Produto;


void run_produto(void);
#endif /* PRODUTO_H */
