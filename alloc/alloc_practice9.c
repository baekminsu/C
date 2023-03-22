#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*
[레벨 1] 사용자로부터 정수 N을 입력받고, N 줄의 공백을 포함하는 문자열을 동
적할당을 이용해 입력 받으시오. 그 후, 이 중 가장 길이가 긴 문자열부터 가장 길이가 작은 문자
열까지 정렬하고, 순서대로 출력하는 프로그램을 작성하시오.
*/

int main() {

	int N;
	scanf("%d", &N);
	getchar();
	int** arr;
	int* temp;
	arr = (char**)malloc(sizeof(char*) * N);
	temp = (char*)malloc(sizeof(char) * (100 + 1));

	for (int i = 0; i < N; i++) {
		arr[i] = (char*)malloc(sizeof(char) * (100 + 1));
	}

	for (int i = 0; i < N; i++) {
		gets(arr[i]);
	}

	for (int i = 0; i < N; i++) {

		for (int j = i+1; j < N; j++) {
			if (strlen(arr[i]) < strlen(arr[j])) {
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
	free(temp);

	return 0;
}

