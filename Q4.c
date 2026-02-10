#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c, i, j;
    int **A, **B, **sum, **diff;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    A = (int **)malloc(r * sizeof(int *));
    B = (int **)malloc(r * sizeof(int *));
    sum = (int **)malloc(r * sizeof(int *));
    diff = (int **)malloc(r * sizeof(int *));

    for (i = 0; i < r; i++) {
        A[i] = (int *)malloc(c * sizeof(int));
        B[i] = (int *)malloc(c * sizeof(int));
        sum[i] = (int *)malloc(c * sizeof(int));
        diff[i] = (int *)malloc(c * sizeof(int));
    }

    printf("Enter elements of matrix A:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            sum[i][j] = A[i][j] + B[i][j];
            diff[i][j] = A[i][j] - B[i][j];
        }
    }

    printf("Sum of matrices:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    printf("Difference of matrices (A - B):\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < r; i++) {
        free(A[i]);
        free(B[i]);
        free(sum[i]);
        free(diff[i]);
    }
    free(A);
    free(B);
    free(sum);
    free(diff);

    return 0;
}
