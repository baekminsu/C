#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


int main() {
    int N;
    int** arr;
    int num = 1;

    scanf("%d", &N);

    arr = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        arr[i] = (int*)malloc(sizeof(int) * N);
    }

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = num++;
            }
        }
        else {
            for (int j = N - 1; j >= 0; j--) {
                arr[i][j] = num++;
            }
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
