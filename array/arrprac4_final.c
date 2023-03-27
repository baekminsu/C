#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main() {

    int N, M;
    int** arr;
    int num = 1;
    int row = 0, col = 0;
    scanf("%d %d", &N, &M);

    arr = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        arr[i] = (int*)malloc(sizeof(int) * M);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = 0;
        }
    }

    while (num != N * M) {


        if (col + 1 < M && arr[row][col + 1] == 0) {
            while (col + 1 < M && arr[row][col + 1] == 0) {
                arr[row][col] = num;
                col++;
                num++;
            }
            arr[row][col] = num;
            continue;
        }
        else if (row + 1 < N && arr[row + 1][col] == 0) {
            while (row + 1 < N && arr[row + 1][col] == 0) {
                arr[row][col] = num;
                row++;
                num++;
            }
            arr[row][col] = num;
            continue;
        }

        else if (col - 1 >= 0 && arr[row][col - 1] == 0) {
            while (col - 1 >= 0 && arr[row][col - 1] == 0) {
                arr[row][col] = num;
                col--;
                num++;
            }
            arr[row][col] = num;
            continue;
        }

        else if (row - 1 >= 0 && arr[row - 1][col] == 0) {
            while (row - 1 >= 0 && arr[row - 1][col] == 0) {
                arr[row][col] = num;
                row--;
                num++;
            }
            arr[row][col] = num;
            continue;
        }

        break;
    }
    arr[row][col] = num;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        free(arr[i]);
    }
    return 0;
}
