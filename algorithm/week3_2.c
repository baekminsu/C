#include <stdio.h>
#include <stdlib.h>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)

int H[100];
int n;

void DownHeap(int i) {
	int left = 2 * i;
	int right = (2 * i) + 1;
	int larger;

	if (left > n) {
		return;
	}
	if (H[left] <= H[right]) {
		larger = right;
	}
	else if (H[left] >= H[right]) {
		larger = left;
	}
	if (H[i] < H[larger]) {
		int temp = H[i];
		H[i] = H[larger];
		H[larger] = temp;
	}
	DownHeap(larger);
}

void BuildHeap(void) {
	for (int i = n / 2; i >= 1; i--) {
		DownHeap(i);
	}
}

void printHeap(void) {
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}
	printf("\n");
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &H[i]);
	}
	BuildHeap();
	printHeap();
	return 0;
}
