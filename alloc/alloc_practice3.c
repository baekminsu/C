#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*
사용자로부터 정수 N을 입력받고, 길이 N의 문자열을 동적할당을 이용해
입력 받으시오. 그 후, 사용자로부터 검색할 문자 2개를 입력받고 각 문자가 입력된 문자열에 몇
번 포함되어있는지 출력하는 프로그램을 작성하시오.
*/

int main() {

	int N;
	scanf("%d", &N);
	char* arr;
	char ser, ser2;
	int cnt = 0, cnt2 = 0;
	arr = (char*)malloc(sizeof(char) * (N+1));

	scanf("%s", arr);
	getchar();
	scanf("%c %c", &ser, &ser2);
	
	for (int i = 0; i < N; i++) {
		if (arr[i] == ser ) {
			cnt++;
		}
		if (arr[i] == ser2) {
			cnt2++;
		}
	}
	
	printf("%d %d", cnt, cnt2);

	free(arr);
	return 0;
}
