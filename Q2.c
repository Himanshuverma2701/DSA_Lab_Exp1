#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i, pos, value;
    int *arr;
    int sum = 0;
    float avg;

    printf("Enter number of elements: ");
    scanf("%d", &N);

    arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter %d elements:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to insert (0 to %d): ", N);
    scanf("%d", &pos);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    arr = (int *)realloc(arr, (N + 1) * sizeof(int));

    for (i = N; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    N++;

    printf("Array elements:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
        sum += arr[i];
    }

    avg = (float)sum / N;

    printf("\nSum = %d", sum);
    printf("\nAverage = %.2f", avg);

    free(arr);
    return 0;
}
