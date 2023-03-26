#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main() {

	int N, M;
	int** arr;
	int row = 0, col = 0;
	scanf("%d %d", &N, &M);

	arr = (int**)malloc(sizeof(int*) * (N+1));
	for (int i = 0; i <= N; i++) {
		arr[i] = (int*)malloc(sizeof(int) * (M+1));
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			arr[i][j] = 0;
		}
	}

	for (int i = 0; i < N * M; i++) {
		
		if (arr[row][col+1] == 0) {
			arr[row][col] = i + 1;
			col++;
		}
		else if (arr[row + 1][col] == 0) {
			arr[row][col] = i + 1;
			row++;
		}



	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i <= N; i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}
