#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*
N개의 실수(float형)를 입력 받아 동적 메모리 할당을 사용하여 배열에 저
장한 후, 저장된 배열 요소들 중 가장 큰 값을 찾아 출력하는 프로그램을 작성하시오. 출력 시, 소
수점 둘째자리까지 출력하시오.
*/

int main() {
	int N;
	float* arr;
	float high = -999999999;
	scanf("%d", &N);
	arr = (float*)malloc(sizeof(float) * N);
	
	for (int i = 0; i < N; i++) {
		scanf("%f", &arr[i]);
		if (arr[i] > high) {
			high = arr[i];
		}
	}
	printf("%.2f", high);

	free(arr);
}
