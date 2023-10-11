#include <stdio.h>
#include <stdlib.h>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)

void merge(int* a, int l, int m, int r) {



}

void mergeSort(int* a, int l ,int r) {
	
	int m;
	
	if (l < r) {
		m = (l + r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
	return;
}


int main() {

	int n;
	int* arr;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	mergeSort(arr, 0,size-1);

	free(arr);

	return 0;
}
