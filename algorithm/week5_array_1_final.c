#include <stdio.h>
#include <stdlib.h>

int sorted[300];

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void merge(int* a, int l, int m, int r) {
    int i = l, k = l;
    int j = m + 1;
    int t;

    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            sorted[k++] = a[i++];
        }
        else {
            sorted[k++] = a[j++];
        }
    }

    while (i <= m) {
        sorted[k++] = a[i++];
    }

    while (j <= r) {
        sorted[k++] = a[j++];
    }

    for (t = l; t <= r; t++) {
        a[t] = sorted[t];
    }
}

void mergeSort(int* a, int l, int r) {
    int m;

    if (l < r) {
        m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int n;
    int* arr;
    scanf("%d", &n);

    arr = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printArray(arr, n);

    free(arr);
    return 0;
}
