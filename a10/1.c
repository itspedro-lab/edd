#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto
{
  char nome[50];
  int quantidade;
  float preco;
  struct Produto *prox;
} Produto;

void inserir(Produto **lista)
{
  Produto *novo = malloc(sizeof(Produto));

  if (novo == NULL)
  {
    printf("Erro de memoria.\n");
    return;
  }

  printf("Nome do produto: ");
  scanf(" %49[^\n]", novo->nome);

  printf("Quantidade: ");
  scanf("%d", &novo->quantidade);

  printf("Preco unitario: ");
  scanf("%f", &novo->preco);

  novo->prox = *lista;
  *lista = novo;

  printf("Produto inserido.\n");
}

void remover(Produto **lista)
{
  char nome[50];
  Produto *atual = *lista;
  Produto *anterior = NULL;

  printf("Nome do produto para remover: ");
  scanf(" %49[^\n]", nome);

  while (atual != NULL && strcmp(atual->nome, nome) != 0)
  {
    anterior = atual;
    atual = atual->prox;
  }

  if (atual == NULL)
  {
    printf("Produto nao encontrado.\n");
    return;
  }

  if (anterior == NULL)
  {
    *lista = atual->prox;
  }
  else
  {
    anterior->prox = atual->prox;
  }

  free(atual);
  printf("Produto removido.\n");
}

void atualizar(Produto *lista)
{
  char nome[50];

  printf("Nome do produto para atualizar: ");
  scanf(" %49[^\n]", nome);

  while (lista != NULL)
  {
    if (strcmp(lista->nome, nome) == 0)
    {
      printf("Nova quantidade: ");
      scanf("%d", &lista->quantidade);
      printf("Quantidade atualizada.\n");
      return;
    }

    lista = lista->prox;
  }

  printf("Produto nao encontrado.\n");
}

void listar(Produto *lista)
{
  if (lista == NULL)
  {
    printf("Lista vazia.\n");
    return;
  }

  while (lista != NULL)
  {
    printf("Produto: %s | Quantidade: %d | Preco: R$ %.2f\n",
           lista->nome, lista->quantidade, lista->preco);
    lista = lista->prox;
  }
}

void total(Produto *lista)
{
  float soma = 0;

  while (lista != NULL)
  {
    soma += lista->quantidade * lista->preco;
    lista = lista->prox;
  }

  printf("Valor total: R$ %.2f\n", soma);
}

void liberar(Produto *lista)
{
  Produto *aux;

  while (lista != NULL)
  {
    aux = lista;
    lista = lista->prox;
    free(aux);
  }
}

int main(void)
{
  Produto *lista = NULL;
  int opcao;

  do
  {
    printf("\n1. Inserir produto\n");
    printf("2. Remover produto\n");
    printf("3. Atualizar quantidade\n");
    printf("4. Mostrar valor total\n");
    printf("5. Listar produtos\n");
    printf("0. Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      inserir(&lista);
      break;
    case 2:
      remover(&lista);
      break;
    case 3:
      atualizar(lista);
      break;
    case 4:
      total(lista);
      break;
    case 5:
      listar(lista);
      break;
    case 0:
      break;
    default:
      printf("Opcao invalida.\n");
    }
  } while (opcao != 0);

  liberar(lista);
  return 0;
}
