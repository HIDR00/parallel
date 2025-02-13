#include <stdio.h>
#include <omp.h>

#define N 3

void multiplyMatrices(int matA[N][N], int matB[N][N], int result[N][N]) {
    #pragma omp parallel for collapse(3)
    for (int i = 0; i < N; i++)
        for (int j=0; j<N; j++) {
            result[i][j] = 0;
            for (int k=0; k<N; k++)
                result[i][j] += matA[i][k] * matB[k][j];
    }
}

void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matA[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matB[N][N] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int result[N][N];

    multiplyMatrices(matA, matB, result);

    printf("Ket qua cua phep nhan A * B:\n");
    printMatrix(result);
}