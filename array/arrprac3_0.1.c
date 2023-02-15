#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS


/*
N x N (1  N≤≤100) 크기의 행렬에 1 ~ N² 의 수를 아래 그림과 같이 차례로 위에서
부터 → 방향과 ← 방향을 번갈아 가면서 채운 결과를 출력하시오.
*/

int main() {

	int* arr;
	int j = 0;
	int cnt = 0;
	int n;
	int i;

	scanf("%d",&n);
	arr = (int*)malloc(sizeof(int) * n * n);

	for (i = 0; i < n; i++) {
		
		arr[i][j] = i + 1;
		printf("%d", arr[i][j]);
		cnt++;

		if (i % 2 == 1) {
			i++;
		}

		if (cnt == n) {
			printf("\n");
			cnt = 0;
			j++;
		}


	}

	return 0;
}
