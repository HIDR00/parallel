#include <stdio.h>
#include <pthread.h>

char* messages[4] = {
    "Chao ban tu Viet Nam",
    "Chao ban tu Cu Ba",
    "Chao ban tu USA",
    "Chao ban tu Uc"
};

void* print_message(void* threadid) {
    long tid = (long)threadid;
    printf("%s\n", messages[tid]);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[4];
    for (long i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, print_message, (void*)i);
    }
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
