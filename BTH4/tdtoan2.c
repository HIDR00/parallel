#include <stdio.h>
#include <omp.h>

// Chương trình con f()
void f() {
    #pragma omp for
    for (int i = 0; i < 10; i++) {
        printf("Thread %d is executing iteration %d in function f()\n", omp_get_thread_num(), i);
    }
}

int main() {
    printf("Calling function f() outside parallel region\n");
    f();

    #pragma omp parallel
    {
        printf("Thread %d is in parallel region in main()\n", omp_get_thread_num());
        f(); 
    }

    return 0;
}