#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
N���� ������ �Է� �޾� �迭�� ������ �� (N �� 50), �ٽ� �迭���� ���� ��ȯ�ϰ� ��
�� �ε��� a �� b�� �Է� �޴´� �ε��� . a �� b ��ġ�� ��� ������ ��ȯ�� �迭�� ����ϴ� ��
�α׷��� �ۼ��Ͻÿ�.
*/


void swap(int* p, int* p2) {
	int temp;
	temp = *p;
	*p = *p2;
	*p2 = temp;
}

int main() { 

	int arr[50];
	int n;
	scanf("%d", &n);
	int* p;
	int a, b;
	for (p = arr; p < arr + n; p++) {
		scanf("%d", p);
	}
	p = arr;
	scanf("%d %d", &a, &b);
	if (a > b) {
		swap(p + b, p + a);
	}
	else {
		swap(p + a, p + b);
	}
	p = arr;
	for (p = arr; p < arr + n; p++) {
		printf(" %d", *p);
	}


	return 0;
}