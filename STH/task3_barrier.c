#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;
    #pragma omp parallel
    {
        omp_set_num_threads(4);
        int id = omp_get_thread_num();
        printf("id: %d\n", id);
        #pragma omp atomic
        sum+=id;
        printf("sum: %d\n", sum);
    }
}