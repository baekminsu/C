#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct Que {
	int* Q;
	int f;
	int r;
}Que;

void enqueue(Que *q, int N, int e) {

	q->r = (q->r+)




}


void initQueue(Que* q, int N) {
	q->Q = (int*)malloc(sizeof(int) * N);
	q->f = 0;
	q->r = 0;
}

int main() {

	int q;
	int n;

	scanf("%d", &q);
	scanf("%d", &n);

	Que* q;
	initQueue(q, n);

	for (int i = 0; i < n; i++) {
		
	}

	return 0;
}
