#include <stdio.h>
#include <math.h>
#include <omp.h>

int main() {
    int n = 1000000;
    double pi = 0.0;
    double dx = 1.0 / n;

    #pragma omp parallel
    {
        double local_pi = 0.0;
        #pragma omp for
        for (int i = 0; i < n; i++) {
            double x = i * dx;
            local_pi += sqrt(1 - x * x) * dx;
        }

        #pragma omp critical
        {
            pi += local_pi;
        }
    }

    pi *= 4.0;
    printf("Pi ~ %.12f\n", pi);
    return 0;
}
