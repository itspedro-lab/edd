#ifndef FILA_H
#define FILA_H

/*registro que reprensentará cada elemento da fila*/
struct Elemento
{
    int num;
    struct Elemento *prox;
};
typedef struct Elemento Elemento;

/*registro do tipo Fila contento dois ponteiros do tipo nó para controlar a fila*/
struct Fila
{
    struct Elemento *inicio; /*aponta para o elemento do início da fila*/
    struct Elemento *fim;    /*aponta para o elemento do fim da fila*/
};
typedef struct Fila Fila;

/*ponteiro auxiliar*/
Elemento *aux;

Fila *cria_fila();

void insere_elemento(Fila *fi);
void consulta_fila(Fila *fi);
void remove_elemento_fila(Fila *fi);

#endif
