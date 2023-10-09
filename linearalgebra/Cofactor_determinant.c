#include <stdio.h>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)
#define N 8

void getCofactor(double matrix[N][N], double temp[N][N], int p, int q, int n) {
    int i = 0, j = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

double calculateDeterminant(double matrix[N][N], int n) {
    double determinant = 0;

    if (n == 1) {
        return matrix[0][0];
    }

    double temp[N][N];
    int sign = 1;

    for (int f = 0; f < n; f++) {
        getCofactor(matrix, temp, 0, f, n);
        determinant += sign * matrix[0][f] * calculateDeterminant(temp, n - 1);
        sign = -sign;
    }

    return determinant;
}

int main() {
    double matrix[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    double determinant = calculateDeterminant(matrix, N);
    printf("%.3lf\n", determinant);
    return 0;
}
