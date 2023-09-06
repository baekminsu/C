#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _crt_secure_no_warnings
#pragma warning(disable:4996)

int main() {
	int n;
	int *arr;
	int temp;
	int target;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i < n ; i++) {
		if (n == 1) {
			break;
		}
		target = i;
		for (int j = i-1; j >= 0; j--) {
			if (arr[target] < arr[j]) {
				temp = arr[j];
				arr[j] = arr[target];
				arr[target] = temp;
				target = j;
			}
			else {
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
	return 0;
}
/*
7
3 73 48 31 8 11 20
8
73 65 48 31 29 20 8 3
*/
