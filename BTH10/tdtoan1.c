#include <stdio.h>
#include <pthread.h>

void* print_thread_id(void* threadid) {
    long tid = (long)threadid;
    printf("Xin chao ban! Toi dang o luong so: %ld\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[4];
    for (long i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, print_thread_id, (void*)i);
    }
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
