#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include<Windows.h>

#define _CRT_SECURE_NO_WARNINGS

/*위 main 함수를 수정하여 아래 절차로 두 함수 prefixAverage1과 prefixAverage2 
각각의 실행시간을 측정 비교하라.*/

int* prefixAverages1(int* x, int n) {
	int* q;
	int i, j;
	int sum = 0;
	clock_t start, end;
	start = clock();
	end = clock();

	q = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++) {
			sum = sum + x[j];
		}
		q[i] = sum / (i + 1);
	}
	printf("%f.ms\n", (float)(end - start) / CLOCKS_PER_SEC);
	free(q);
	return q;
}

int* prefixAverages2(int* x, int n) {
	int* q;
	int i, j;
	int sum = 0;
	clock_t start, end;
	start = clock();
	end = clock();

	q = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		sum = sum + x[i];
		q[i] = (sum) / (i + 1);
	}
	printf("%f.ms\n", (float)(end - start) / CLOCKS_PER_SEC);

	free(q);
	return q;

}


int main() {
	int* x;
	int n;

	scanf("%d",&n);
	srand(time(NULL));
	int* p;
	p = x;
	x = (int*)malloc(sizeof(int) * n);

	n = (rand() % 10001);

	prefixAverages1(x, n);
	prefixAverages2(x, n);

	//printf("%f.ms\n", (float)(end - start) / CLOCKS_PER_SEC);

	free(x);

	return 0;
}
