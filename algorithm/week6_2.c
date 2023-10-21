#include <stdio.h>
#include <stdlib.h> 
#define _crt_secure_no_warnings
#pragma warning(disable:4996)

int min = -1;

int findElement(int* arr, int n, int k) {
	int mid, left = 0, right = n - 1;

	while (1) {
		if (left > right) {
			return -1;
		}
		mid = (left + right) / 2;
		if (arr[mid] == k) {
			return mid;
		}
		else if (arr[mid] > k) {
			if (min == -1) {
				min = mid;
			}
			else if (arr[min] > arr[mid]) {
				min = mid;
			}
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

}


int main() {

	int n, k;
	scanf("%d %d", &n, &k);
	int* arr;
	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}

	if (findElement(arr, n, k) == -1) {
		if (min == -1) {
			printf(" %d\n", n);
		}
		else {
			printf(" %d\n", min);
		}
	}
	else {
		printf(" %d\n", findElement(arr, n, k));
	}
	free(arr);
	return 0;
}
