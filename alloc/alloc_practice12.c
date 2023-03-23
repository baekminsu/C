#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*
정수 N을 입력받고 N개의 문자열을 입력받아 사전 순으로 출력하는 프
로그램을 작성하시오.
*/

int main() {
	
	int N;
	int** arr;
	scanf("%d", &N);
	getchar();

	arr = (int**)malloc(sizeof(int *) * N);
	int temp[101];
	for (int i = 0; i < N; i++) {
		arr[i] = (int*)malloc(sizeof(int) * (100 + 1));
	}

	for (int i = 0; i < N; i++) {
		gets(arr[i]);
	}	

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (strcmp(arr[i],arr[j])  > 0 ) {
				strcpy(temp, arr[i]);
				strcpy(arr[i], arr[j]);
				strcpy(arr[j], temp);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%s\n", arr[i]);
	}


	for (int i = 0; i < N; i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}
