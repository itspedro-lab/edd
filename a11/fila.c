#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *cria_fila()
{
    /*alocação do ponteiro li para controlar a lista*/
    Fila *fi = (Fila *)malloc(sizeof(Fila));
    if (fi != NULL)
    {
        /*a fila inicia-se vazia, portanto inicio e fim são iguais a NULL*/
        fi->fim = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

void insere_elemento(Fila *fi)
{
    /*a cada inserção alocamos dinamicamente um espaço para um novo elemento*/
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    printf("\nDigite o numero a ser inserido na fila: ");
    scanf("%d", &novo->num);
    novo->prox = NULL;
    /*caso a fila esteja vazia, o elemento inserido será o primeiro e o último */
    if (fi->inicio == NULL)
    {
        fi->inicio = novo;
        fi->fim = novo;
        /*caso a pilha ja contenha algum elemento, o novo elemento será sempre inserido no fim da fila*/
    }
    else
    {
        fi->fim->prox = novo;
        fi->fim = novo;
    }
    printf("\nNumero inserido na fila!");
    getchar();
}

void consulta_fila(Fila *fi)
{
    if (fi->inicio == NULL)
    {
        printf("\nFila Vazia!!");
    }
    else
    {
        aux = fi->inicio;
        do
        {
            printf("\n %d ", aux->num);
            aux = aux->prox;
        } while (aux != NULL);
    }
    getchar();
}

void remove_elemento_fila(Fila *fi)
{
    if (fi->inicio == NULL)
    {
        printf("\nFila Vazia!!");
    }
    else
    {
        aux = fi->inicio;
        printf("\n%d removido!", fi->inicio->num);
        fi->inicio = fi->inicio->prox;
        free(aux);
    }
    getchar();
}

int main()
{
    Fila *fi = cria_fila();

    insere_elemento(fi);
    insere_elemento(fi);
    insere_elemento(fi);
    remove_elemento_fila(fi);
    consulta_fila(fi);
    return 0;
}
