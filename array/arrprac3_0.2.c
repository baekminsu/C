#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS


/*
N x N (1  N≤≤100) 크기의 행렬에 1 ~ N² 의 수를 아래 그림과 같이 차례로 위에서
부터 → 방향과 ← 방향을 번갈아 가면서 채운 결과를 출력하시오.
*/

int main() {

	int** arr;
	int j = 0;
	int cnt = 0;
	int n;
	int i;
	int row, col = 0;

	scanf("%d",&n);
	arr = (int**)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
	}


	for (i = 1; i <= (n * n); i++) {
		
		if (row % 2 == 0) {
			arr[row][col] = i;
			col++;
			cnt++;
			if ((cnt % 4) == 0) {
				row++;
				cnt = 0;
			}
		}
		else {
			arr[row][col] = i;
			col--;
			cnt++;
			if ((cnt % 4) == 0) {
				row++;
				cnt = 0;
			}
		}

	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}



	for (i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}
