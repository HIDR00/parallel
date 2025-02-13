#include <pthread.h>
#define NUM_THREADS 5

void* hello_world(void *i) {
    int i = int(i);
    printf("This is a thread\n %d\n",i);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    int ret,i;
    for(int i = 0;i < NUM_THREADS;i++) {
        printf("Creating thread %d\n",i);
        ret = pthread_create(&thread,NULL,hello_world,(void*)i);

        if(ret) {
            printf("Error creating thread %d\n",i);
            exit(-1);
        }
    }
    return 0;
}