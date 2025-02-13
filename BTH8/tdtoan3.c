#include <stdio.h>
#include <omp.h>

int main() {
    int n = 100;
    int sum = 0;

    #pragma omp parallel
    {
        int partial_sum = 0;
        int thread_num = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        for (int i = thread_num + 1; i <= n; i += num_threads) {
            partial_sum += i;
        }

        #pragma omp atomic
        sum += partial_sum;
    }

    printf("Total sum S=1+2+...+%d is: %d\n", n, sum);
    return 0;
}
