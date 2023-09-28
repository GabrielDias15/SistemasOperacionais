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
        printf("Nenhuma das contas tem saldo suficiente para a transferência\n");
    }

    printf("Saldo de c1: %d\n", from.saldo);
    printf("Saldo de c2: %d\n", to.saldo);
    pthread_mutex_unlock(&print_mutex); // Desbloqueia o mutex após acessar os dados compartilhados

    return 0;
}

int main() {
    void* stack[THREADS];
    pid_t pids[THREADS];
    int i;

    pthread_barrier_init(&barreira, NULL, THREADS + 1);
    pthread_mutex_init(&print_mutex, NULL);

    from.saldo = 100;
    to.saldo = 40;
    printf("Transferindo 10 para a conta c2\n");
    valor = 10;

    for (i = 0; i < THREADS; i++) {
        stack[i] = malloc(FIBER_STACK);
        if (stack[i] == 0) {
            perror("malloc: could not allocate stack");
            exit(1);
        }

        pids[i] = clone(&transferencia, (char*) stack[i] + FIBER_STACK, SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, 0);
        if (pids[i] == -1) {
            perror("clone");
            exit(2);
        }
    }

    pthread_barrier_wait(&barreira);

    for (i = 0; i < THREADS; i++) {
        waitpid(pids[i], NULL, 0);
        free(stack[i]);
    }

    printf("Transferencias concluidas e memoria liberada.\n");

    pthread_mutex_destroy(&print_mutex);
    return 0;
}
