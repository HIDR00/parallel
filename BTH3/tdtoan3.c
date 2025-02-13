#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;

    #pragma omp parallel
    {
        #pragma omp atomic
        sum += 1;
    }

    printf("Tổng là: %d\n", sum);

    return 0;
}
