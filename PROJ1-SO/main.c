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

struct c {
    int saldo;
};
typedef struct c conta;

conta from, to;
int valor;

pthread_barrier_t barreira;

int transferencia(void *arg) {
    if (from.saldo >= valor) {
        from.saldo -= valor;
        to.saldo += valor;
    }
    printf("Transferencia concluida com sucesso!\n");
    printf("Saldo de c1: %d\n", from.saldo);
    printf("Saldo de c2: %d\n", to.saldo);
    return 0;
}

int main() {
    void* stack;
    pid_t pid;
    int i;

    pthread_barrier_init(&barreira, NULL, 11);

    stack = malloc(FIBER_STACK);
    if (stack == 0) {
        perror("malloc: could not allocate stack");
        exit(1);
    }

    from.saldo = 100;
    to.saldo = 100;
    printf("Transferindo 10 para a conta c2\n");
    valor = 10;

    for (i = 0; i < 10; i++) {
        pid = clone(&transferencia, (char*) stack + FIBER_STACK, SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, 0);
        if (pid == -1) {
            perror("clone");
            exit(2);
        }
    }

    free(stack);
    printf("Transferencias concluidas e memoria liberada.\n");
    return 0;
}
