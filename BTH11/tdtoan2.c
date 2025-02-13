#include <stdio.h>
#include <pthread.h>

#define N 1000000
#define NUM_THREADS 4

long sum = 0;
pthread_mutex_t mutex;

void *calculate_sum(void *threadid) {
    long tid = (long)threadid;
    long local_sum = 0;
    long start = (tid * N) / NUM_THREADS + 1;
    long end = ((tid + 1) * N) / NUM_THREADS;

    for (long i = start; i <= end; i++) {
        local_sum += i;
    }

    pthread_mutex_lock(&mutex);  
    sum += local_sum;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, calculate_sum, (void *)i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Tong S = 1 + 2 + ... + %d la: %ld\n", N, sum);

    pthread_mutex_destroy(&mutex);
    pthread_exit(NULL);
    return 0;
}
