#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main() {

	int N;
	int Num;
	int start;
	int end;
	int temp;
	scanf("%d", &N);
	int* arr;
	int i, j, k;

	arr = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &Num);

	for ( i = 0; i < Num; i++) {
		scanf("%d %d", &start, &end);
		for ( j = start, k = end; j <= (end + start) / 2; j++,k--) {
			temp = arr[j];
			arr[j] = arr[k];
			arr[k] = temp;
		}
	}
	
	for (int i = 0; i < N; i++) {
		printf(" %d", arr[i]);
	}


	free(arr);

	return 0;
}
