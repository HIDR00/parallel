#include <stdio.h>
#include <omp.h>
#include <limits.h>

int find_min_non_zero(int* arr, int size) {
    int min_val = INT_MAX;

    #pragma omp parallel for reduction(min:min_val)
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0 && arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    return (min_val == INT_MAX) ? -1 : min_val;
}

int main() {
    int arr[] = {0, 0, 5, 3, 0, 7, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min_val = find_min_non_zero(arr, size);

    if (min_val != -1) {
        printf("The minimum non-zero value is: %d\n", min_val);
    } else {
        printf("All elements are zero or the array is empty.\n");
    }

    return 0;
}
