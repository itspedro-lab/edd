#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "livro.h"
#include "usuario.h"

typedef struct Emprestimo
{
    int usuario_id;
    int livro_codigo;
    char data[20];
} Emprestimo;

#endif /* EMPRESTIMO_H */
