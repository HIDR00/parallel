#include <stdio.h>
#include <omp.h>

void f(int n) {
    int dem = 0;
    #pragma omp parallel for schedule(guided, 2) reduction(+: dem)
    for (int i = 1; i < n; i++) {
        if(n % i == 0) {
            dem++;
        }
    }
    dem == 2 ? printf("So nguyen to\n") : printf("Khong phai so nguyen to\n");
}

int main() {
    int n = 8;
    f(n);
}