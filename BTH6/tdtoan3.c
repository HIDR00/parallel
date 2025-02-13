#include <stdio.h>
#include <math.h>
#include <omp.h>

int main() {
    int n = 1000000;
    double pi = 0.0;
    double dx = 1.0 / n;

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        double x = i * dx;
        #pragma omp atomic
        pi += sqrt(1 - x * x) * dx;
    }

    pi *= 4.0;
    printf("Pi ~ %.12f\n", pi);
    return 0;
}
