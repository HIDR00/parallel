#include <stdio.h>
#include <math.h>

int main() {
    int n = 1000000;  
    double pi = 0.0;
    double dx = 1.0 / n;

    for (int i = 0; i < n; i++) {
        double x = i * dx;
        pi += sqrt(1 - x * x) * dx; 
    }

    pi *= 4.0;
    printf("Pi ~ %.12f\n", pi);
    return 0;
}
