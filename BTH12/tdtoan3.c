#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;    
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  
int current_thread = 1; 

void* print_message(void* arg) {
    int thread_id = *((int*)arg); 

    pthread_mutex_lock(&mutex); 
    while (thread_id != current_thread) { 
        pthread_cond_wait(&cond, &mutex); 
    }

    if (thread_id == 1) {
        printf("Nguyen Van A\n"); 
    } else if (thread_id == 2) {
        printf("Xin Chao\n"); 
    } else if (thread_id == 3) {
        printf("Tu Lop\n");  
    } else if (thread_id == 4) {
        printf("Lap trinh song song\n"); 
    }

    current_thread++;
    pthread_cond_broadcast(&cond);  
    pthread_mutex_unlock(&mutex);  

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[4];  
    int thread_ids[4];     

    for (int i = 0; i < 4; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, print_message, (void*)&thread_ids[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL
    }
}