#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

/*N개의 정수를 두 번 입력받아 예시와 , 
같이 역방향으로 더하여 출력하는 프로그램을 작성하시오.*/

int main() {

	int n;
	int* arr;
	int* arr2;
	int* p;
	int* p2;
	int* result;
	int* p3;

	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);
	arr2 = (int*)malloc(sizeof(int) * n);
	result = (int*)malloc(sizeof(int) * n);

	for (p = arr; p < arr + n; p++) {
		scanf("%d", p);
	}

	for (p2 = arr2; p2 < arr2 + n; p2++) {
		scanf("%d", p2);
	}
	
	for (p = arr,p2 = arr2+n-1, p3 =result; p < arr + n; p++,p2--,p3++) {
		*p3 = *p + *p2;
		
	}
	for (p3 = result; p3 < result + n; p3++) {
		printf(" %d", *p3);
	}

	free(arr);
	free(arr2);
	free(result);

	return 0;
}

