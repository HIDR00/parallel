#include <stdio.h>
#include <omp.h>

void f() {
    printf("Executing in function f() outside parallel region\n");

    #pragma omp parallel
    {
        printf("Thread %d is executing in function f() inside parallel region\n", omp_get_thread_num());
    }
}

int main() {
    printf("Executing in main() outside parallel region\n");

    #pragma omp parallel
    {
        printf("Thread %d is executing in main() inside parallel region\n", omp_get_thread_num());
    }

    f();

    return 0;
}
