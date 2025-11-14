#include <stdio.h>
#include <stdlib.h>

static int *alloc_matrix(int rows, int cols) {
    int *m = malloc(sizeof(int) * rows * cols);
    if (!m) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    return m;
}

static void read_matrix(int *m, int rows, int cols) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (scanf("%d", &m[i * cols + j]) != 1) {
                fprintf(stderr, "invalid input\n");
                exit(EXIT_FAILURE);
            }
}

static void print_matrix(const int *m, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            printf("%d%c", m[i * cols + j], j + 1 < cols ? ' ' : '\n');
    }
}

static void multiply(const int *A, int r1, int c1, const int *B, int r2, int c2, int *C) {
    // C = A * B, sizes: A[r1 x c1], B[r2 x c2], with c1 == r2, C[r1 x c2]
    for (int i = 0; i < r1 * c2; ++i) C[i] = 0;
    for (int i = 0; i < r1; ++i) {
        for (int k = 0; k < c1; ++k) {
            int a = A[i * c1 + k];
            // accumulate row i of A times row k of B (access B by row k)
            for (int j = 0; j < c2; ++j) {
                C[i * c2 + j] += a * B[k * c2 + j];
            }
        }
    }
}

int main(void) {
    int r1, c1, r2, c2;
    puts("Enter rows and cols for matrix A (r c):");
    if (scanf("%d %d", &r1, &c1) != 2) return 1;
    puts("Enter rows and cols for matrix B (r c):");
    if (scanf("%d %d", &r2, &c2) != 2) return 1;
    if (c1 != r2) {
        fprintf(stderr, "matrix multiplication not possible: c1 (%d) != r2 (%d)\n", c1, r2);
        return 1;
    }

    int *A = alloc_matrix(r1, c1);
    int *B = alloc_matrix(r2, c2);
    int *C = alloc_matrix(r1, c2);

    printf("Enter %d elements of A (row-major):\n", r1 * c1);
    read_matrix(A, r1, c1);

    printf("Enter %d elements of B (row-major):\n", r2 * c2);
    read_matrix(B, r2, c2);

    multiply(A, r1, c1, B, r2, c2, C);

    puts("Result (A * B):");
    print_matrix(C, r1, c2);

    free(A);
    free(B);
    free(C);
    return 0;
}