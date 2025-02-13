#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_cond_t cond_recv = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_send = PTHREAD_COND_INITIALIZER;
pthread_mutex_t cond_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
int full = 0;
int count = 0;

void* produce(void*) {
    while (1) {
        pthread_mutex_lock(&cond_mutex);
        while (full) {
            pthread_cond_wait(&cond_recv, &cond_mutex);
        }
        pthread_mutex_unlock(&cond_mutex);
        pthread_mutex_lock(&count_mutex);
        count++;
        full = 1;
        printf("produced(%d): %d\n", pthread_self(), count);
        pthread_cond_broadcast(&cond_send);
        pthread_mutex_unlock(&count_mutex);
        if (count >= 10) break;
    }
    return NULL;
}

void* consume(void*) {
    while (1) {
        pthread_mutex_lock(&cond_mutex);
        while (!full) {
            pthread_cond_wait(&cond_send, &cond_mutex);
        }
        pthread_mutex_unlock(&cond_mutex);
        pthread_mutex_lock(&count_mutex);
        full = 0;
        printf("consumed(%d): %d\n", pthread_self(), count);
        pthread_cond_broadcast(&cond_recv);
        pthread_mutex_unlock(&count_mutex);
        if (count >= 10) break;
    }
    return NULL;
}

int main() {
    pthread_t cons_thread, prod_thread;
    pthread_create(&prod_thread, NULL, produce, NULL);
    pthread_create(&cons_thread, NULL, consume, NULL);
    pthread_join(cons_thread, NULL);
    pthread_join(prod_thread, NULL);
    return 0;
}
