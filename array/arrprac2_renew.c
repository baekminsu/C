#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main() {

	int N;
	int Num;
	int* arr = { 0, };
	int arr2[101] = { 0, };
	int carr[101] = { 0, };

	for (int i = 0; i < 101; i++) {
		carr[i] = 486486;
	}


	scanf("%d", &N);
	arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &Num);

	for (int i = 0; i < Num; i++) {
		scanf("%d", &arr2[i]);
	}

	for (int i = 0; i < Num - 1; i++) {
		carr[arr2[i + 1]] = arr[arr2[i]];
	}

	for (int i = 0; i < N; i++) {
		if (carr[i] == 486486) {
			carr[i] = arr[i];
		}
	}


	for (int i = 0; i < N; i++) {
		printf(" %d", carr[i]);
	}



	free(arr);

	return 0;
}
