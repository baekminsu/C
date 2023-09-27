#include <stdio.h>
#include <stdlib.h>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)

int H[100];
int N = 0;
int keyNum;

void downHeap(int i) {
    int left = i * 2;
    int right = (i * 2) + 1;
    int larger = i;
    if (left > N) {
        return;
    }
    if (left <= N && H[left] > H[larger]) {
        larger = left;
    }
    if (right <= N && H[right] > H[larger]) {
        larger = right;
    }
    if (larger != i) {
        int temp = H[i];
        H[i] = H[larger];
        H[larger] = temp;
        downHeap(larger);
    }
}

void createMaxHeap(void) {
    for (int i = N / 2; i >= 1; i--) {
        downHeap(i);
    }
}

void inPlaceHeapSort(void) {
    createMaxHeap();
    while (1) {
        int temp;
        if (N > 1) {
            temp = H[N];
            H[N] = H[1];
            H[1] = temp;
            N--;
            downHeap(1);
        }
        else{
            break;
        }
    }
}

void printArray(void) {
    for (int i = 1; i <= keyNum; i++) {
        printf(" %d", H[i]);
    }
    printf("\n");
}

void insertItem(int key) {
    H[++N] = key;
}

int main() {
    int item;
    scanf("%d", &keyNum);
    for (int i = 0; i < keyNum; i++) {
        scanf("%d",&item);
        insertItem(item);
    }
    inPlaceHeapSort();
    printArray();
    return 0;
}
