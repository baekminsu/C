#include <stdio.h>
#include <stdlib.h> // rand()함수포함 0~32767
#define _crt_secure_no_warnings
#pragma warning(disable:4996)

int inPlacePartition(int* arr, int l, int r, int k) {
	int pivot;
	pivot = arr[k];
	int left, right;
	int temp;

	left = l;
	right = r;

	while (left < right) {
		while ((arr[left] < pivot) && (left < right)) {
			left++;
		}
		while ((arr[right] >= pivot) && (left < right)) {
			right--;
		}
		if (left < right) {
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			if (left == k) {
				k = right;
			}
		}
	}
	temp = arr[k];
	arr[k] = arr[right];
	arr[right] = temp;
	return right;
}

int findPivot(int l,int r) {
	int index;
	index = l + (rand() % (r-l+1)) ;
	return index;
}

void inPlaceQuickSort(int* arr,int l,int r) {
	int a, b;
	int c;
	if (l >= r) {
		return;
	}
	int k = findPivot(l, r);
	a = b = inPlacePartition(arr, l, r, k);

	inPlaceQuickSort(arr, l, a - 1);
	inPlaceQuickSort(arr, b + 1, r);

}

void printArr(int* arr,int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}


int main() {

	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	inPlaceQuickSort(arr, 0, n-1);
	printArr(arr, n);

	free(arr);

	return 0;
}
