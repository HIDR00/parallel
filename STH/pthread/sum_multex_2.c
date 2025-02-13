#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock;
int dem=0;

void *count(void *arg){
    long num = (long)arg;
    long i;
    long local_sum = 0;
    long start = (num * 1000000) / (4 + 1);
    long end = ((num + 1) * 1000000) / 4;

    for(i=start;i<=end;i++) {
        local_sum += i;
    }

    pthread_mutex_lock(&lock);
    dem += local_sum;
    pthread_mutex_unlock(&lock);  
    return NULL;

}

int main(){
    long i;
    pthread_t tid[4];
    pthread_mutex_init(&lock, NULL);  

    for(i=0;i<4;i++){
        pthread_create(&tid[i],NULL,count,(void*)i);
    }
    for(i=0;i<4;i++){
        pthread_join(tid[i],NULL);
    }

    printf("Dem=%d\n",dem);
    pthread_mutex_destroy(&lock);
    pthread_exit(NULL);
    return 0;

}