#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

/*
 양의 정수를 입력 받아 각,자리의 수를 낮은 자릿수부터 차례로 출력하는 프로그램을
작성하시오 나머지  . (           조건은 문제 와2    동일)
*/

int recur3(int n) {

	if (n <= 10) {
		printf("%d", n);
		return n;
	} //3408  - > 8 0 4 3

	else {
		printf("%d\n",n % 10);
		recur3(n / 10);
	}

}


int main() {
	int n;
	scanf("%d", &n);

	recur3(n); //3408

	return 0;
}
