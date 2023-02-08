#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

/*
N (3 ≤ N ≤ 100) 개의 정수로 이루어진 수열 X를 “뒤집기 정보 에” 의해 변환한 최종
결과를 출력하는 프로그램을 작성하시오
*/

int main() {

	int n;
	int* arr;
	int d;
	int a, b;
	int swab;

	scanf("%d", &n);
	
	arr =(int*) malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &d);

	for (int i = 0; i < d; i++) {
		scanf("%d %d", &a, &b);
		for (int j = a; j < (a + b) / 2; j++, b--) {
			swab = arr[j];
			arr[j] = arr[b];
			arr[b] = swab;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}



	free(arr);


	return 0;
}
