#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int nthreads = omp_get_num_threads();
        int thread_num = omp_get_thread_num();

        printf("Threads entering parallel region: %d\n", nthreads);

        #pragma omp for
        for (int iter = 0; iter < nthreads; iter++) {
            printf("Thread %d executing iteration %d\n", thread_num, iter);
        }
    }

    return 0;
}

// Nếu số lượng luồng lớn hơn số lõi, hệ thống vẫn tạo đủ số luồng, 
// nhưng một số luồng sẽ phải chờ luân phiên sử dụng tài nguyên CPU (vì số lõi có hạn).
// Điều này có thể dẫn đến giảm hiệu suất vì nhiều luồng sẽ cạnh tranh cho các lõi CPU.
