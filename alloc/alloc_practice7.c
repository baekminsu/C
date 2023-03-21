#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
/*
열과 행을 입력받아 2차원 문자열 배열을 동적할당하고, 2차원 배열 내에
알파벳을 순서대로 채워 출력하는 프로그램을 작성하시오.
*/
int main() {

	int col;
	int row;
	char** arr;
	char start = 'a';
	scanf("%d %d", &col, &row);

	arr = (char**)malloc(sizeof(char*) * (row +1));

	for (int i = 0; i < row; i++) {
		arr[i] = (char*)malloc(sizeof(char) * (col+1));
	}

	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = start;
			start++;
			if (start == 'Z' +1) {
				start = start - 'Z' + 'a' - 1;
			}
			if (start > 'z') {
				start = start - 'z' + 'A' - 1;
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < row; i++) {
		free(arr[i]);
	}

	free(arr);


	return 0;
}
