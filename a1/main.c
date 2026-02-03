#include "menu/menu.h"

#include "aluno-ex/aluno.h"
#include "carro/carro.h"
#include "cliente/cliente.h"
#include "conta/conta.h"
#include "endereco/endereco.h"
#include "filme/filme.h"
#include "func/funcionario.h"
#include "livro/livro.h"
#include "produto/produto.h"
#include "professor/professor.h"

int main(void)
{
    const MenuItem items[] = {
        {"Professor", run_professor},
        {"Produto", run_produto},
        {"Livro", run_livro},
        {"Cliente", run_cliente},
        {"Funcionario", run_funcionario},
        {"Carro", run_carro},
        {"Conta", run_conta},
        {"Endereco", run_endereco},
        {"Filme", run_filme},
        {"Aluno extra", run_aluno_ex},
    };
    const Menu menu = {
        "Menu aula 1",
        items,
        sizeof(items) / sizeof(items[0]),
    };

    return menu_run(&menu);
}
