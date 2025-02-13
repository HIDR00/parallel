#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 4
#define N 100000

double pi = 0.0;
pthread_mutex_t pi_mutex;

void* compute_pi(void* threadid) {
    long tid = (long) threadid;
    double local_sum = 0.0;
    long start = tid * (N / NUM_THREADS);
    long end = (tid + 1) * (N / NUM_THREADS);

    for (long i = start; i < end; i++) {
        double term = ((i % 2 == 0) ? 1 : -1) / (2.0 * i + 1);
        local_sum += term;
    }

    pthread_mutex_lock(&pi_mutex);
    pi += local_sum;
    pthread_mutex_unlock(&pi_mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&pi_mutex, NULL);

    for (long t = 0; t < NUM_THREADS; t++) {
        pthread_create(&threads[t], NULL, compute_pi, (void*) t);
    }

    for (long t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    pthread_mutex_destroy(&pi_mutex);

    printf("Gia tri cua Pi: %.15f\n", pi * 4);
    return 0;
}
