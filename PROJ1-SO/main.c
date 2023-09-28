#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h>

#define FIBER_STACK 1024*64
#define THREADS 50

struct c {
    int saldo;
};
typedef struct c conta;

conta from, to;
int valor;

pthread_barrier_t barreira;
pthread_mutex_t print_mutex;

int transferencia(void *arg) {
    // Aguarda até que todas as fibras estejam prontas para iniciar
    pthread_barrier_wait(&barreira);

    pthread_mutex_lock(&print_mutex); // Bloqueia o mutex antes de acessar os dados compartilhados

    if (from.saldo >= valor) {
        from.saldo -= valor;
        to.saldo += valor;
        printf("Transferido %d de c1 para c2\n", valor);
    } else if (to.saldo >= valor) {
        to.saldo -= valor;
        from.saldo += valor;
        printf("Transferido %d de c2 para c1\n", valor);
    } else {
