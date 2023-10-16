#include <stdio.h>
#include <stdlib.h>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)
#define N 8
double determinant(double mat[N][N], int size);

void adjointMatrix(double mat[N][N], double adj[N][N]) {
    double temp[N][N];  
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sign = ((i + j) % 2 == 0) ? 1 : -1;
            int m = 0;
            for (int row = 0; row < N; row++) {
                if (row == i) continue;
                int n = 0;
                for (int col = 0; col < N; col++) {
                    if (col == j) continue;
                    temp[m][n] = mat[row][col];
                    n++;
                }
                m++;
            }
            adj[i][j] = sign * determinant(temp, N - 1);
        }
    }
}

void printMatrix(double mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.3lf ", mat[j][i]);
        }
        printf("\n");
    }
}

void multiplyMatrix(double mat1[N][N], double mat2[N][N], double result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    double matrix[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    double adj[N][N];
    adjointMatrix(matrix, adj);

    double det = determinant(matrix, N);

    double inv[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inv[i][j] = adj[i][j] / det;
        }
    }
    printMatrix(inv);

    return 0;
}

double determinant(double mat[N][N], int size) {
    if (size == 1) {
        return mat[0][0];
    }

    double det = 0;
    double temp[N][N];
    int sign = 1;

    for (int i = 0; i < size; i++) {
        int m = 0;
        for (int row = 1; row < size; row++) {
            int n = 0;
            for (int col = 0; col < size; col++) {
                if (col == i) continue;
                temp[m][n] = mat[row][col];
                n++;
            }
            m++;
        }
        det += sign * mat[0][i] * determinant(temp, size - 1);
        sign = -sign;
    }

    return det;
}



/*
1.1 2.1 3.1 4.1 5.1 6.1 7.1 8.1
8.1 7.1 6.1 5.1 4.1 3.1 2.1 1.1
3.4 2.2 1.5 5.6 3.2 1.5 4.3 2.7
7.5 4.3 1.3 4.5 6.7 4.5 3.2 1.7
3.4 5.4 6.7 3.4 2.4 6.7 5.4 3.2
3.4 3.2 1.4 3.5 3.2 4.2 4.6 5.3
7.4 5.3 2.1 3.4 3.5 3.2 1.7 4.7
1.3 4.3 2.8 4.5 6.3 4.2 4.5 4.3
*/
