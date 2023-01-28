#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*함수 prefixAverages1과 prefixAverages2, 그리고 이들을 테스트할 수 있는 main
함수를 구현하여 아래 테스트를 수행하라.*/

int *prefixAverages1(int* x, int n) {
	int* q;
	int i, j;
	int sum = 0;

	q = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++) {
			sum = sum + x[j];
		}
		q[i] = sum / (i + 1);
	}
	return q;
}

int *prefixAverages2(int* x, int n){
	int* q;
	int i, j;
	int sum = 0;

	q = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		sum = sum + x[i];
		q[i] = (sum) / (i+1);
	}

	return q;

}

int main() {
	int n;
	int* x ;
	int* p;
	int* p2;
	scanf("%d", &n); //3

	x = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	} //배열완성
	//3          5 3 5
	//5 1 9   -> 5 3 5

	p = x;
	p2 = x;
	p = prefixAverages1(x, n);
	p2 = prefixAverages2(x, n);

	for (int i = 0; i < n; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", p2[i]);
	}

	free(x);
	return 0;
}
