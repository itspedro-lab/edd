#include "vetor.h"

#include <stdio.h>

void vetor_init(Vetor *v)
{
    if (!v)
        return;
    v->count = 0;
}

void ler_valores(Vetor *v)
{
    if (!v)
        return;

    int n = 0;
    printf("Quantidade de valores (max %d): ", MAX_VALORES);
    if (scanf(" %d", &n) != 1)
        return;
    if (n < 0 || n > MAX_VALORES)
    {
        printf("Quantidade invalida.");
        return;
    }

    v->count = n;
    for (int i = 0; i < n; ++i)
    {
        printf("Valor %d: ", i + 1);
        if (scanf(" %d", &v->valores[i]) != 1)
            return;
    }
}

void remover_repetidos(Vetor *v)
{
    if (!v || v->count == 0)
    {
        printf("Vetor vazio.");
        return;
    }

    for (int i = 0; i < v->count; ++i)
    {
        for (int j = i + 1; j < v->count;)
        {
            if (v->valores[j] == v->valores[i])
            {
                for (int k = j; k < v->count - 1; ++k)
                    v->valores[k] = v->valores[k + 1];
                v->count--;
            }
            else
            {
                j++;
            }
        }
    }

    printf("Repetidos removidos e vetor compactado.");
}

void exibir_vetor(const Vetor *v, const char *titulo)
{
    if (!v)
    {
        printf("Vetor invalido.");
        return;
    }

    printf("%s", titulo);
    if (v->count == 0)
    {
        printf("(vazio)");
        return;
    }

    for (int i = 0; i < v->count; ++i)
        printf("%d ", v->valores[i]);
    printf("");
}
