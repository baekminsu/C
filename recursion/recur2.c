#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

/*양의 정수를 입력 받아 각,자리의 수를 높은 자릿수부터 차례로 출력하는 프로그램을 
작성하시오.*/

int recur2(int n) {

	if (n >= 10) { //3408  -> 3 4 0 8
		recur2(n / 10);
		printf("%d\n", n % 10);
	}
	else {
		printf("%d\n", n);
	}

}
int main() {

	int n;
	scanf("%d", &n);

	recur2(n);

	return 0;
}
