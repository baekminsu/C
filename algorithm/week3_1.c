#include <stdio.h>
#include <stdlib.h>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)  

int H[100];
int n = 0;

void upHeap(int v) {
	if (v == 1) {
		return;
	}
	int parent = v / 2;
	if (H[v] <= H[parent]) {
		return;
	}
	int temp;
	temp = H[v];
	H[v] = H[parent];
	H[parent] = temp;
	upHeap(parent);
}

void insertItem(int key) {
	n = n + 1;
	H[n] = key;
	upHeap(n);
	printf("0\n");
}

void downHeap(int i) {
	int left = 2 * i;
	int right = (2 * i) + 1;

	if (left > n) {
		return;
	}
	int larger;
	if (H[right] > H[left]) {
		larger = right;
	}
	else if (H[right] < H[left]) {
		larger = left;
	}
	if (H[i] < H[larger]) {
		int temp = H[i];
		H[i] = H[larger];
		H[larger] = temp;
	}
	downHeap(larger);
}

int removeMax(void) {
	int key = H[1];
	H[1] = H[n];
	n = n - 1;
	downHeap(1);
	return key;
}

void printHeap(void) {
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}
	printf("\n");
}

int main() {
	char input;
	int key;
	int root;

	while (1) {
		scanf("%c", &input);
		if (input== 'i') {
			scanf("%d", &key);
			insertItem(key);
		}
		else if (input == 'd') {
			root = removeMax();
			printf("%d\n", root);
		}
		else if (input == 'p') {
			printHeap();
		}
		else if (input == 'q') {
			break;
		}
	}

	return 0;
}
