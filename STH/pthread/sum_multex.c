#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock;
int dem=0;

void *count(void *arg){
    int i;
    for(i=0;i<1000000;i++) {
        pthread_mutex_lock(&lock);
        dem++;
        pthread_mutex_unlock(&lock);  
    }
    return NULL;

}

int main(){
    int i;
    pthread_t tid[4];
    pthread_mutex_init(&lock, NULL);  

    for(i=0;i<4;i++){
        pthread_create(&tid[i],NULL,count,NULL);
    }
    for(i=0;i<4;i++){
        pthread_join(tid[i],NULL);
    }

    printf("Dem=%d\n",dem);
    pthread_mutex_destroy(&lock);
    pthread_exit(NULL);
    return 0;

}