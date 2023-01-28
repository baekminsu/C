#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

int recur1(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return n + recur1(n - 1);
	}
}

int main() {

	int n;
	int sum = 0;
	scanf("%d", &n);
	sum = sum + recur1(n);

	printf("%d", sum);

	return 0;
}
