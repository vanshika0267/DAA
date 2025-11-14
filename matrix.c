#include <stdio.h>

#define N 4  

void rotateMatrix(int mat[N][N]) {
    for (int layer = 0; layer < N / 2; layer++) {
        int first = layer;
        int last = N - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;

            int top = mat[first][i];
            mat[first][i] = mat[last - offset][first];
            mat[last - offset][first] = mat[last][last - offset];
            mat[last][last - offset] = mat[i][last];
            mat[i][last] = top;
        }
    }
}

void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%3d ", mat[i][j]);
        printf("\n");
    }
}

int main() {
    int mat[N][N] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Original Matrix:\n");
    printMatrix(mat);

    rotateMatrix(mat);

    printf("\nRotated Matrix by 90 degrees:\n");
    printMatrix(mat);

    return 0;
}

