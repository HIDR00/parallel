#include <stdio.h>
#include <omp.h>

static long num_steps = 100000;
double step;
#define NUM_THREADS 8

int main() {
    int i,nthreads;
    double x, pi, sum[NUM_THREADS];
    step = 1.0/(double) num_steps;
    omp_set_num_threads(NUM_THREADS);
    printf("start: %f\n", omp_get_wtime());
    #pragma omp parallel
    {
        int i, id;
        id = omp_get_thread_num();
        if (id == 0) {
            nthreads = NUM_THREADS;
        }
        for (i = id, sum[id] = 0.0;i < num_steps; i+=NUM_THREADS) {
            x = (i + 0.5) * step;
            printf("i: %d\n", i);
            sum[id] += 4.0 / (1.0 + x * x);
        }
    }
    printf("end: %f\n", omp_get_wtime());
    for (i = 0, pi = 0.0; i < nthreads; i++) {
        pi += sum[i] * step;
    }
    printf("%f\n", pi);
    return 0;

}