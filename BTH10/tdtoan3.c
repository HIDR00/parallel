#include <stdio.h>
#include <pthread.h>

#define N 100
#define NUM_THREADS 4

int sum = 0;
pthread_mutex_t mutex;

void* calculate_sum(void* threadid) {
    long tid = (long)threadid;
    int local_sum = 0;

    for (int i = tid + 1; i <= N; i += NUM_THREADS) {
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
        pthread_create(&threads[i], NULL, calculate_sum, (void*)i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("Tong S=1+2+...+%d la: %d\n", N, sum);
    return 0;
}
