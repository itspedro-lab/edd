#include "biblioteca.h"

#include <stdio.h>

void biblioteca_init(Biblioteca *biblioteca)
{
    if (!biblioteca)
        return;
    biblioteca->livros_count = 0;
    biblioteca->usuarios_count = 0;
    biblioteca->emprestimos_count = 0;
}

static int find_livro_index(const Biblioteca *biblioteca, int codigo)
{
    for (int i = 0; i < biblioteca->livros_count; ++i)
    {
        if (biblioteca->livros[i].codigo == codigo)
            return i;
    }
    return -1;
}

static int find_usuario_index(const Biblioteca *biblioteca, int id)
{
    for (int i = 0; i < biblioteca->usuarios_count; ++i)
    {
        if (biblioteca->usuarios[i].id == id)
            return i;
    }
    return -1;
}

void cadastrar_usuario(Biblioteca *biblioteca)
{
    if (!biblioteca)
        return;

    if (biblioteca->usuarios_count >= MAX_USUARIOS)
    {
        printf("Limite de usuarios atingido.\n");
        return;
    }

    Usuario u;
    printf("ID do usuario: ");
    if (scanf(" %d", &u.id) != 1)
        return;
    printf("Nome do usuario: ");
    if (scanf(" %99[^\n]", u.nome) != 1)
        return;

    if (find_usuario_index(biblioteca, u.id) >= 0)
    {
        printf("Usuario ja cadastrado.\n");
        return;
    }

    biblioteca->usuarios[biblioteca->usuarios_count++] = u;
    printf("Usuario cadastrado.\n");
}

void cadastrar_livro(Biblioteca *biblioteca)
{
    if (!biblioteca)
        return;

    if (biblioteca->livros_count >= MAX_LIVROS)
    {
        printf("Limite de livros atingido.\n");
        return;
    }

    Livro l;
    printf("Codigo do livro: ");
    if (scanf(" %d", &l.codigo) != 1)
        return;
    printf("Titulo do livro: ");
    if (scanf(" %99[^\n]", l.titulo) != 1)
        return;
    printf("Autor do livro: ");
    if (scanf(" %99[^\n]", l.autor) != 1)
        return;

    if (find_livro_index(biblioteca, l.codigo) >= 0)
    {
        printf("Livro ja cadastrado.\n");
        return;
    }

    biblioteca->livros[biblioteca->livros_count++] = l;
    printf("Livro cadastrado.\n");
}

void registrar_emprestimo(Biblioteca *biblioteca)
{
    if (!biblioteca)
        return;

    if (biblioteca->emprestimos_count >= MAX_EMPRESTIMOS)
    {
        printf("Limite de emprestimos atingido.\n");
        return;
    }

    int usuario_id = 0;
    int livro_codigo = 0;

    printf("ID do usuario: ");
    if (scanf(" %d", &usuario_id) != 1)
        return;
    printf("Codigo do livro: ");
    if (scanf(" %d", &livro_codigo) != 1)
        return;

    if (find_usuario_index(biblioteca, usuario_id) < 0 ||
        find_livro_index(biblioteca, livro_codigo) < 0)
    {
        printf("Usuario ou livro nao encontrado.\n");
        return;
    }

    Emprestimo e;
    e.usuario_id = usuario_id;
    e.livro_codigo = livro_codigo;
    printf("Data do emprestimo (dd/mm/aaaa): ");
    if (scanf(" %19[^\n]", e.data) != 1)
        return;

    biblioteca->emprestimos[biblioteca->emprestimos_count++] = e;
    printf("Emprestimo registrado.\n");
}

void listar_livros_por_usuario(Biblioteca *biblioteca)
{
    if (!biblioteca)
        return;

    int usuario_id = 0;
    printf("ID do usuario: ");
    if (scanf(" %d", &usuario_id) != 1)
        return;

    int user_idx = find_usuario_index(biblioteca, usuario_id);
    if (user_idx < 0)
    {
        printf("Usuario nao encontrado.\n");
        return;
    }

    printf("\nLivros emprestados para %s:\n", biblioteca->usuarios[user_idx].nome);
    for (int i = 0; i < biblioteca->emprestimos_count; ++i)
    {
        if (biblioteca->emprestimos[i].usuario_id == usuario_id)
        {
            int livro_idx = find_livro_index(biblioteca, biblioteca->emprestimos[i].livro_codigo);
            if (livro_idx >= 0)
            {
                printf("%d - %s (%s) - %s\n",
                       biblioteca->livros[livro_idx].codigo,
                       biblioteca->livros[livro_idx].titulo,
                       biblioteca->livros[livro_idx].autor,
                       biblioteca->emprestimos[i].data);
            }
        }
    }
}
