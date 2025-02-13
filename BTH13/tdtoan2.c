#include <stdio.h>
#include <stdlib.h>

#define N 3 
#define M 3 
#define L 3 

void multiply_matrices(int A[N][M], int B[M][L], int C[N][L]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++) {
            C[i][j] = 0;
            for (int k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[N][M] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[M][L] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int C[N][L];

    multiply_matrices(A, B, C);

    printf("Ket qua ma tran C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
