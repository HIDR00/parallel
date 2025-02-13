#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 3 
#define M 3 
#define L 3  
#define NUM_THREADS 4

int A[N][M] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int B[M][L] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
int C[N][L];

void* multiply_matrices(void* arg) {
    long tid = (long) arg;
    int start = tid * (N / NUM_THREADS);
    int end = (tid + 1) * (N / NUM_THREADS);

    for (int i = start; i < end; i++) {
        for (int j = 0; j < L; j++) {
            C[i][j] = 0;
            for (int k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];

    for (long t = 0; t < NUM_THREADS; t++) {
        pthread_create(&threads[t], NULL, multiply_matrices, (void*) t);
    }

    for (long t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("Ket qua ma tran C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
