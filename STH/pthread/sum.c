#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* sum(void* n) {
    long num = (long)n;
    long* result = malloc(sizeof(long));
    *result = 0; 

    for(long i = 1;i <= num;i++) {
        *result += i;
    }
    return (void*)result;
} 

int main() {
    pthread_t thread;
    long n = 1000000;
    void* sum_result;
    pthread_create(&thread,NULL,sum,(void*)(long)n);
    pthread_join(thread,&sum_result);

    printf("Sum is %lld\n",*(long long*)sum_result);
    return 0;
}