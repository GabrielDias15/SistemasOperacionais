#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Definindo o número de threads e a variável sum global
#define thread_count 4
long long n = 1e8; // número de termos para calcular pi
double sum = 0.0;
pthread_mutex_t mutex_sum;

void* Thread_sum(void* rank);

int main() {
    long thread;
    pthread_t thread_handles[thread_count];

    // Inicializa o mutex
    pthread_mutex_init(&mutex_sum, NULL);

    for (thread = 0; thread < thread_count; thread++)  
        pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*)thread);  

    for (thread = 0; thread < thread_count; thread++) 
        pthread_join(thread_handles[thread], NULL); 

    sum = 4.0*sum;
    printf("Valor de pi calculado = %.14f\n", sum);
    printf("Quantidade de threads = %d\n", thread_count);

    pthread_mutex_destroy(&mutex_sum);
    return 0;
}

void* Thread_sum(void* rank) {
    long my_rank = (long) rank;
    double factor;
    double my_sum = 0.0;
    long long i;
    long long my_n = n/thread_count;
    long long my_first_i = my_n*my_rank;
    long long my_last_i = my_first_i + my_n;

    if (my_first_i % 2 == 0) // my_first_i is even
        factor = 1.0;
    else  // my_first_i is odd
        factor = -1.0;

    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        my_sum += factor/(2*i+1);
    }

    // Bloqueia o mutex antes de atualizar a variável sum global
    pthread_mutex_lock(&mutex_sum);
    sum += my_sum;
    // Desbloqueia o mutex após a atualização
    pthread_mutex_unlock(&mutex_sum);

    return NULL;
}
