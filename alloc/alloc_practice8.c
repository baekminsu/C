#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
/*
사용자로부터 정수 N을 입력받고, N 줄의 공백을 포함하는 문자열을 동
적할당을 이용해 입력 받으시오. 그 후, 이 중 가장 길이가 작은 공백을 포함하는 문자열을 출력
하는 프로그램을 작성하시오.
*/

int main() {

	int N;
	int** arr;
	scanf("%d", &N);
	getchar();
	int low = 100;
	int save = 0;
	arr = (char**)malloc(sizeof(char *) * (N));

	for(int i = 0; i < N; i++) {
		arr[i] = (char*)malloc(sizeof(char) * (100 + 1));
	}

	for (int i = 0; i < N; i++) {
		gets(arr[i]);
	}

	for (int i = 0; i < N; i++) {
		if (low > strlen(arr[i])) {
			low = strlen(arr[i]);
			save = i;
		}
	}

	printf("%s", arr[save]);


	for (int i = 0; i < N; i++) {
		free(arr[i]);
	}

	free(arr);

	return 0;
}
