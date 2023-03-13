#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*
사용자로부터 정수 N을 입력받고, N개의 문자를 동적할당을 이용해 입력
받으시오. 문자 중에 “cat"가 몇 번 있는지 횟수를 출력 하시오.
*/

int main() {

	int N;
	char* arr;
	char arr2[3] = { 'c','a','t' };
	scanf("%d", &N);
	arr = (char*)malloc(sizeof(char) * (N+1));
	scanf("%s", arr);
	int cnt = 0;
	char* p;
	p = arr;
	for (p = arr; p < arr+N; p++) {
		if (strncmp(p, arr2,3) == 0) {
			cnt++;
		}
	}
	printf("%d", cnt);

	free(arr);

	return 0;
}
