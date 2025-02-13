#include <stdio.h>
#include <omp.h>

static long num_steps = 100000;
double step;
#define NUM_THREADS 8

int main() {
    int i;
    double x, pi, sum;
    step = 1.0/(double) num_steps;
    omp_set_num_threads(NUM_THREADS);
    printf("start: %f\n", omp_get_wtime());
    #pragma omp parallel
    {
        int i, id;
        id = omp_get_thread_num();
        for (i = id;i < num_steps; i+=NUM_THREADS) {
            x = (i + 0.5) * step;
            #pragma omp atomic
            sum += 4.0 / (1.0 + x * x);
        }
    }
    printf("end: %f\n", omp_get_wtime());
    pi += sum * step;
    printf("%f\n", pi);
    return 0;

}