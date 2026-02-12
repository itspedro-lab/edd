#include "nota.h"

#include <stdio.h>

void notas_init(Notas *n)
{
    if (!n)
        return;
    n->count = 0;
}

void inserir_nota(Notas *n)
{
    if (!n)
        return;

    if (n->count >= MAX_NOTAS)
    {
        printf("Limite de notas atingido.");
        return;
    }

    float valor = 0.0f;
    printf("Informe a nota: ");
    if (scanf(" %f", &valor) != 1)
        return;

    n->valores[n->count++] = valor;
    printf("Nota inserida.");
}

void remover_nota(Notas *n)
{
    if (!n || n->count == 0)
    {
        printf("Nao ha notas cadastradas.");
        return;
    }

    int pos = -1;
    printf("Posicao para remover (0 a %d): ", n->count - 1);
    if (scanf(" %d", &pos) != 1)
        return;

    if (pos < 0 || pos >= n->count)
    {
        printf("Posicao invalida.");
        return;
    }

    for (int i = pos; i < n->count - 1; ++i)
        n->valores[i] = n->valores[i + 1];
    n->count--;

    printf("Nota removida.");
}

void atualizar_nota(Notas *n)
{
    if (!n || n->count == 0)
    {
        printf("Nao ha notas cadastradas.");
        return;
    }

    int pos = -1;
    printf("Posicao para atualizar (0 a %d): ", n->count - 1);
    if (scanf(" %d", &pos) != 1)
        return;

    if (pos < 0 || pos >= n->count)
    {
        printf("Posicao invalida.");
        return;
    }

    float valor = 0.0f;
    printf("Nova nota: ");
    if (scanf(" %f", &valor) != 1)
        return;

    n->valores[pos] = valor;
    printf("Nota atualizada.");
}

void exibir_notas(Notas *n)
{
    if (!n || n->count == 0)
    {
        printf("Nao ha notas cadastradas.");
        return;
    }

    float soma = 0.0f;
    float maior = n->valores[0];
    float menor = n->valores[0];

    printf("Notas(posicao->valor):");
    printf("\n[");
    for (int i = 0; i < n->count; ++i)
    {
        float v = n->valores[i];
        printf(" %d->%.2f |", i, v);
        soma += v;
        if (v > maior)
            maior = v;
        if (v < menor)
            menor = v;
    }
    printf("]\n");

    printf(" (Media: %.2f)", soma / n->count);
    printf(" (Maior: %.2f)", maior);
    printf(" (Menor: %.2f)", menor);
}
