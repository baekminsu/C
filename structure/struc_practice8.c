#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/* 두 개의 복소수를 입력 받고, 두 복소수를 더한 결과값을 출력하는 프
로그램을 작성하시오.*/

struct complex {
	double a;
	double b;
};

struct complex add(struct complex s1, struct complex s2) {
	struct complex sum;
	sum.a = s1.a + s2.a;
	sum.b = s1.b + s2.b;

	return sum;
}


int main() {
	struct complex input;
	struct complex input2;
	struct complex result;	

	scanf("%lf %lf", &input.a, &input.b);
	scanf("%lf %lf", &input2.a, &input2.b);

	result = add(input,input2);

	printf("%.1lf + %.1lf", result.a, result.b);
	printf("i");


	return 0;
}
