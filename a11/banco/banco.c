#include <stdio.h>
#include <time.h>
#include "banco.h"

void clientes_init(Clientes *clientes)
{
    clientes->inicio = 0;
    clientes->fim = 0;
    clientes->quantidade = 0;
    clientes->total_tempo_atendimento = 0;
    clientes->total_clientes_atendidos = 0;
}

static int fila_cheia(Clientes *clientes)
{
    return clientes->quantidade == MAX_CLIENTES;
}

static int fila_vazia(Clientes *clientes)
{
    return clientes->quantidade == 0;
}

static double calcular_media_atendimento(Clientes *clientes)
{
    if (clientes->total_clientes_atendidos == 0)
        return 0.0;

    return clientes->total_tempo_atendimento / clientes->total_clientes_atendidos;
}

static int cliente_existe(Clientes *clientes, int id)
{
    for (int i = 0; i < clientes->quantidade; i++)
    {
        int pos = (clientes->inicio + i) % MAX_CLIENTES;

        if (clientes->fila[pos].id == id)
            return 1;
    }

    return 0;
}

static void atualizar_tempos_estimados(Clientes *clientes)
{
    double media = calcular_media_atendimento(clientes);

    for (int i = 0; i < clientes->quantidade; i++)
    {
        int pos = (clientes->inicio + i) % MAX_CLIENTES;
        clientes->fila[pos].tempo_estimado = i * media;
    }
}

void inserir_cliente(Clientes *clientes)
{
    if (fila_cheia(clientes))
    {
        printf("\nFila cheia! Nao foi possivel inserir o cliente.\n");
        return;
    }

    Cliente cliente;

    printf("\nDigite o numero de identificacao do cliente: ");
    scanf("%d", &cliente.id);

    if (cliente_existe(clientes, cliente.id))
    {
        printf("\nEsse cliente ja esta na fila.\n");
        return;
    }

    cliente.tempo_estimado = 0;
    cliente.hora_chegada = time(NULL);

    clientes->fila[clientes->fim] = cliente;
    clientes->fim = (clientes->fim + 1) % MAX_CLIENTES;
    clientes->quantidade++;

    atualizar_tempos_estimados(clientes);

    int pos = (clientes->fim - 1 + MAX_CLIENTES) % MAX_CLIENTES;

    printf("\nCliente inserido na fila!");
    printf("\nTempo estimado de espera: %.2f minutos\n", clientes->fila[pos].tempo_estimado);
}

void atender_cliente(Clientes *clientes)
{
    if (fila_vazia(clientes))
    {
        printf("\nFila vazia! Nao ha clientes para atender.\n");
        return;
    }

    Cliente cliente = clientes->fila[clientes->inicio];

    printf("\nCliente %d esta sendo atendido.\n", cliente.id);
    printf("Pressione ENTER para iniciar o atendimento...");
    getchar();
    getchar();

    time_t inicio_atendimento = time(NULL);

    printf("Pressione ENTER quando o atendimento terminar...");
    getchar();

    time_t fim_atendimento = time(NULL);

    double tempo_atendimento_segundos = difftime(fim_atendimento, inicio_atendimento);
    double tempo_atendimento_minutos = tempo_atendimento_segundos / 60.0;

    clientes->total_tempo_atendimento += tempo_atendimento_minutos;
    clientes->total_clientes_atendidos++;

    clientes->inicio = (clientes->inicio + 1) % MAX_CLIENTES;
    clientes->quantidade--;

    if (clientes->quantidade == 0)
    {
        clientes->inicio = 0;
        clientes->fim = 0;
    }

    atualizar_tempos_estimados(clientes);

    printf("\nCliente %d atendido e removido da fila.\n", cliente.id);
    printf("Tempo real de atendimento: %.2f minutos\n", tempo_atendimento_minutos);
    printf("Media atual de atendimento: %.2f minutos\n", calcular_media_atendimento(clientes));
}

void exibir_fila(Clientes *clientes)
{
    if (fila_vazia(clientes))
    {
        printf("\nFila vazia!\n");
        return;
    }

    atualizar_tempos_estimados(clientes);

    printf("\nClientes em espera:\n");
    printf("ID\tTempo estimado de espera\n");

    for (int i = 0; i < clientes->quantidade; i++)
    {
        int pos = (clientes->inicio + i) % MAX_CLIENTES;
        Cliente cliente = clientes->fila[pos];

        printf("%d\t%.2f minutos\n", cliente.id, cliente.tempo_estimado);
    }

    printf("\nMedia de atendimento usada no calculo: %.2f minutos\n", calcular_media_atendimento(clientes));
}

void exibir_tempo_total_espera(Clientes *clientes)
{
    if (fila_vazia(clientes))
    {
        printf("\nFila vazia! Tempo total de espera: 0 minutos\n");
        return;
    }

    atualizar_tempos_estimados(clientes);

    double tempo_total = 0;

    for (int i = 0; i < clientes->quantidade; i++)
    {
        int pos = (clientes->inicio + i) % MAX_CLIENTES;
        tempo_total += clientes->fila[pos].tempo_estimado;
    }

    printf("\nTempo total de espera dos clientes: %.2f minutos\n", tempo_total);
}
