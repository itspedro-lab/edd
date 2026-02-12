#ifndef VETOR_H
#define VETOR_H

#define MAX_VALORES 100

typedef struct Vetor
{
    int valores[MAX_VALORES];
    int count;
} Vetor;

void vetor_init(Vetor *v);
void ler_valores(Vetor *v);
void remover_repetidos(Vetor *v);
void exibir_vetor(const Vetor *v, const char *titulo);

#endif /* VETOR_H */
