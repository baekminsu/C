#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

/*
N 개의 정수를 입력 받아 (N ≤ 20), 최댓값을 구하는 프로그램을 작성하시오.
*/

int recur4(int* arr, int n) {

	if (n == 1) {
		return arr[0];
	}

	int max = recur4(arr, n - 1);

	if (max > arr[n - 1]) {
		return max;
	}
	else {
		return arr[n - 1];
	}


}

int main() {
	int n;
	int* arr;

	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("%d", recur4(arr, n));

	/*for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}*/

	free(arr);

	return 0;
}
