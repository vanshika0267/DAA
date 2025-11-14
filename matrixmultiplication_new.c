#include <stdio.h>
#include <stdlib.h>

int main() {
    int m1, n1, m2, n2;
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &m1, &n1);
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &m2, &n2);

    if (n1 != m2) {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }

    int **A = (int **)malloc(m1 * sizeof(int *));
    int **B = (int **)malloc(m2 * sizeof(int *));
    int **C = (int **)malloc(m1 * sizeof(int *));
    for (int i = 0; i < m1; i++) {
        A[i] = (int *)malloc(n1 * sizeof(int));
        C[i] = (int *)malloc(n2 * sizeof(int));
    }
    for (int i = 0; i < m2; i++)
        B[i] = (int *)malloc(n2 * sizeof(int));

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n1; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < m2; i++)
        for (int j = 0; j < n2; j++)
            scanf("%d", &B[i][j]);

    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n2; j++)
            C[i][j] = 0;

    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n2; j++)
            for (int k = 0; k < n1; k++)
                C[i][j] += A[i][k] * B[k][j];

    printf("Resultant Matrix:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    for (int i = 0; i < m1; i++) {
        free(A[i]);
        free(C[i]);
    }
    for (int i = 0; i < m2; i++)
        free(B[i]);
    free(A);
    free(B);
    free(C);

    return 0;
}
