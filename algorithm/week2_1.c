#include <stdio.h>
#include <stdlib.h>

#define _crt_secure_no_warnings
#pragma warning(disable:4996)

int main() {

	int n;
	int* arr;
	int max;
	int temp;
	int index = 0;
	
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		max = i;
		for (int j = 0; j < i; j++) {
			if (arr[max] < arr[j]) {
				max = j;
			}
		}
		temp = arr[i]; 
		arr[i] = arr[max]; 
		arr[max] = temp; 
	}
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}


	return 0;
}
/*
8
8 31 48 73 3 65 20 29
*/
