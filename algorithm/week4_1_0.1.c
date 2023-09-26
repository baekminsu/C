#include <stdio.h>
#include <stdlib.h>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)

int H[100];
int N = 0;

void downHeap(int i) {
    int left = i * 2;
    int right = (i * 2) + 1;
    if (left > N) {
        return;
    }
    int larger;
    if (H[left] <= H[right]) {
        larger = right;
    }
    else if (H[left] >= H[right]) {
        larger = left;
    }

    downHeap(larger);
}

void createMaxHeap(void) {
    for (int i = N / 2; i >= 1; i--) {
        downHeap(i);
    }
}

void inPlaceHeapSort(void) {

    createMaxHeap();



}

void printArray(void) {
    for (int i = 1; i <= N; i++) {
        printf(" %d", H[i]);
    }
    printf("\n");
}

void insertItem(int key) {
    H[N] = key;
    N++;
}

int main() {
    int item;
    int keyNum;
    scanf("%d", &keyNum);
    for (int i = 0; i < keyNum; i++) {
        scanf("%d", item);
        insertItem(item);
    }
    inPlaceHeapSort();

    return 0;
}
