#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <string.h>  
#include <stdlib.h>

/*10���� ������ �Է����� �޾� ���� ,ū ������ ������������
�����Ͽ� ����ϴ� ���α׷��� �ۼ� �Ͻÿ�.*/

void abc(int* p, int k) {
	int* q; //1 3 5 7 9 2 4 6 8 10
	q = p;
	int* q2;
	int temp;
	q2 = p;



	for (q = p; q < p + k; q++) {

		if (*q2 < *q) {
			q2 = q; //�ᱹ�ִ������ΰ�
		}

	}
	temp = *q2; //�ִ��ӽÿ��ְ�
	*q2 = *p; //�ٽ� �����迭���� �ʱ�ȭ
	*p = temp; //�����־��ش�.


}

int main() {

	int arr[10] = { 0, };
	int* p = arr;
	int k = 0;

	for (p = arr; p < arr + 10; p++) {
		scanf("%d", p);
	}//�迭�Է¿ϼ�

	p = arr;

	for (k = 0; k < 9; k++) { //1 3 5 7 9 2 4 6 8 10
		abc(p, k);
	}

	for (k = 0; k < 10; k++) {
		printf("%d ", arr[k]);
	}

}