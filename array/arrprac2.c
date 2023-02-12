#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

/*
2≤ N ≤ 100) 개의정수로이루어진수열X를“위치바꿈정보에”    의해변
환한 최종 결과를 출력하는 프로그램을 작성하시오 위치 .  바꿈 방식은 다음과 같다 예를 .          들어, 10
개 정수의 수열 X와 위치 바꿈 정보가 다음과 같이 주어졌을 때,
*/

int main() {

	int n;
	int* x;
	int swab;
	int length;	
	int* x2;

	scanf("%d", &n);
	x = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	scanf("%d", &length);
	
	x2 = (int*)malloc(sizeof(int) * (length +1));

	for (int i = 0; i < length; i++) {
		scanf("%d", &x2[i]);
	}

	x2[length] = x2[length - 1];

	for (int i = 0; i < length; i++) {
		swab = x[x2[i]];
		x[x2[i]] = x[x2[i + 1]];
		x[x2[i + 1]] = swab;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ",x[i]);
	}
	
	/*for (int i = 0; i <= length; i++) {
		printf("%d ", x2[i]);
	}*/


	free(x);
	free(x2);

	return 0;
}
