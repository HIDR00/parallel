#include <stdio.h>
#include <omp.h>

int main() {
    int n = 100;
    int sum = 0;
    omp_lock_t lock;
    omp_init_lock(&lock);

    #pragma omp parallel
    {
        int partial_sum = 0;
        int thread_num = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        for (int i = thread_num + 1; i <= n; i += num_threads) {
            partial_sum += i;
        }

        omp_set_lock(&lock);
        sum += partial_sum;
        omp_unset_lock(&lock);
    }

    omp_destroy_lock(&lock);
    printf("Total sum S=1+2+...+%d is: %d\n", n, sum);
    return 0;
}
