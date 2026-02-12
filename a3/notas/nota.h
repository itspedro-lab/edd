#ifndef NOTA_H
#define NOTA_H

#define MAX_NOTAS 50

typedef struct Notas
{
  float valores[MAX_NOTAS];
  int count;
} Notas;

void notas_init(Notas *n);
void inserir_nota(Notas *n);
void remover_nota(Notas *n);
void atualizar_nota(Notas *n);
void exibir_notas(Notas *n);

#endif /* NOTA_H */
