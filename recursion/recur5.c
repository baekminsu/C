#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int hanoi(int N,char from, char aux, char to) {
	
	if (N == 1) {
		return ;
	}

	hanoi(N - 1, from, to, aux);
	printf("%c %c\n", from, to);
	hanoi(N - 1, aux, from, to);
	
	return 0;

}


int main() {
	int N;
	scanf("%d", &N);
	N = N + 1;
	hanoi(N, 'A', 'B', 'C');


	return 0;
}
