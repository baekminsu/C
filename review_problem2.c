#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <string.h>  
#include <stdlib.h>

/*10개의 정수를 입력으로 받아 가장 ,큰 수부터 내림차순으로
정렬하여 출력하는 프로그램을 작성 하시오.*/

void abc(int* p, int k) {
	int* q; //1 3 5 7 9 2 4 6 8 10
	q = p;
	int* q2;
	int temp;
	q2 = p;



	for (q = p; q < p + k; q++) {

		if (*q2 < *q) {
			q2 = q; //결국최대한으로감
		}

	}
	temp = *q2; //최대임시에넣고
	*q2 = *p; //다시 다음배열부터 초기화
	*p = temp; //값을넣어준다.


}

int main() {

	int arr[10] = { 0, };
	int* p = arr;
	int k = 0;

	for (p = arr; p < arr + 10; p++) {
		scanf("%d", p);
	}//배열입력완성

	p = arr;

	for (k = 0; k < 9; k++) { //1 3 5 7 9 2 4 6 8 10
		abc(p, k);
	}

	for (k = 0; k < 10; k++) {
		printf("%d ", arr[k]);
	}

}