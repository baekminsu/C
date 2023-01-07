#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
N개의 정수를 입력 받아 배열에 저장한 후 (N ≤ 50), 다시 배열에서 값을 교환하고 싶
은 인덱스 a 와 b를 입력 받는다 인덱스 . a 와 b 위치의 요소 값들이 교환된 배열을 출력하는 프
로그램을 작성하시오.
*/


void swap(int* p, int* p2) {
	int temp;
	temp = *p;
	*p = *p2;
	*p2 = temp;
}

int main() { 

	int arr[50];
	int n;
	scanf("%d", &n);
	int* p;
	int a, b;
	for (p = arr; p < arr + n; p++) {
		scanf("%d", p);
	}
	p = arr;
	scanf("%d %d", &a, &b);
	if (a > b) {
		swap(p + b, p + a);
	}
	else {
		swap(p + a, p + b);
	}
	p = arr;
	for (p = arr; p < arr + n; p++) {
		printf(" %d", *p);
	}


	return 0;
}
