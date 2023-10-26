#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int m, n;
double **A;
double *x;
double *y;
int thread_count;

void* Pth_mat_vect(void* rank) {
    long my_rank = (long) rank;
    int i, j;
    int local_m = m / thread_count;
    int my_first_row = my_rank * local_m;
    int my_last_row = (my_rank + 1) * local_m - 1;

    for (i = my_first_row; i <= my_last_row; i++) {
        y[i] = 0.0;
        for (j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    long thread;
    pthread_t* thread_handles;

    m = 4; 
    n = 4; 
    thread_count = 4; 

    A = malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++) {
        A[i] = malloc(n * sizeof(double));
    }
    x = malloc(n * sizeof(double));
    y = malloc(m * sizeof(double));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = i + j;
        }
    }
    for (int i = 0; i < n; i++) {
        x[i] = i;
    }

    thread_handles = malloc(thread_count * sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*) thread);
    }

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    for (int i = 0; i < m; i++) {
        printf("y[%d] = %f\n", i, y[i]);
    }

    for (int i = 0; i < m; i++) {
        free(A[i]);
    }
    free(A);
    free(x);
    free(y);
    free(thread_handles);

    return 0;
}
