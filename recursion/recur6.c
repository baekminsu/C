#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int gcd(int a, int b) {

	if (b == 0) {
		return a;
	}
	else {
		gcd(b, a % b);
	}

}


int main() {

	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d", gcd(a, b));

	return 0;
}
