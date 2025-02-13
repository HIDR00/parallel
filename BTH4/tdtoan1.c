#include <stdio.h>
#include <omp.h>

void f() {
    #pragma omp for
    for (int i = 0; i < 20; i++) {
        printf("Thread %d is executing iteration %d in function f()\n", omp_get_thread_num(), i);
    }
}

int main() {
    #pragma omp parallel
    {
        printf("Thread %d is in parallel region in main()\n", omp_get_thread_num());
        f(); 
    }
    return 0;
}
