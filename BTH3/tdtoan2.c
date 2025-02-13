#include <stdio.h>
#include <omp.h>

int main() {
    printf("Trước vùng song song:\n");
    printf("Số lượng bộ xử lý: %d\n", omp_get_num_procs());
    
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        printf("Xin chào từ thread %d trong tổng số %d threads\n", thread_id, num_threads);
    }
    
    printf("Sau vùng song song.\n");

    return 0;
}
