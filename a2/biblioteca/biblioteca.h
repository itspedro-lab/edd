#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"

#define MAX_LIVROS 200
#define MAX_USUARIOS 200
#define MAX_EMPRESTIMOS 500

typedef struct Biblioteca
{
    Livro livros[MAX_LIVROS];
    int livros_count;
    Usuario usuarios[MAX_USUARIOS];
    int usuarios_count;
    Emprestimo emprestimos[MAX_EMPRESTIMOS];
    int emprestimos_count;
} Biblioteca;

void biblioteca_init(Biblioteca *biblioteca);
void cadastrar_usuario(Biblioteca *biblioteca);
void cadastrar_livro(Biblioteca *biblioteca);
void registrar_emprestimo(Biblioteca *biblioteca);
void listar_livros_por_usuario(Biblioteca *biblioteca);

#endif /* BIBLIOTECA_H */
