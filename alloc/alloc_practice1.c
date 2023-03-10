#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*
N개의 정수를 입력 받아 동적 메모리 할당을 사용하여 배열에 저장한 후,
저장된 배열 요소들의 합을 출력하는 프로그램을 작성하시오.
*/

int main() {
	int N;
	int* p;
	scanf("%d", &N);
	p = (int*)malloc(sizeof(int) * N);
	int sum = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
		sum = sum + p[i];
	}

	printf("%d", sum);


	free(p);
	return 0;
}
