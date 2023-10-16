#include <stdio.h>
#include <stdlib.h> 
#define _crt_secure_no_warnings
#pragma warning(disable:4996)

maxindex = NULL;


int rFE(int* arr, int k, int left , int right) {
	int mid;
	if (left > right) {
		return -1;
	}
	mid = (left + right) / 2;
	if (k == arr[mid]) {
		return mid;
	}
	else if (k < arr[mid]) {
		return rFE(arr, k, left, mid - 1);
	}
	else {
		if (maxindex == NULL) {
			maxindex = mid;
		}
		else if (arr[maxindex] < arr[mid]) {
			maxindex = mid;
		}
		return rFE(arr, k, mid + 1, right);
	}
}

int findElement(int* arr,int n,int k) {
	return rFE(arr, k, 0, n - 1);
}

int main() {

	int n;
	int k;
	int* arr;
	scanf("%d %d", &n, &k);

	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", arr[i]);
	}

	if (findElement(arr, n, k) == -1) {
		if (maxindex == NULL) {
			printf(" %d\n", findElement(arr, n, k));
		}
		else {
			printf(" %d\n", maxindex);
		}
	}
	else {
		printf(" %d\n", findElement(arr, n, k));
	}


	free(arr);
	return 0;
}
