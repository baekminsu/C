#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main() {

	int N, M;
	int** arr;


	scanf("%d %d", &N, &M);

	arr = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = (int*)malloc(sizeof(int) * M);
	}


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


	return 0;
}
