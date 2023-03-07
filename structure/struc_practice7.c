#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*10 개의 정수를 입력 받고, 그 정수의 내림차순 상 순위를 계산하여,
정수와 순위를 함께 구조체 배열에 저장 한 후, 3번째 순위와 7번째 순위에 해당하는 정수를 출력
하는 프로그램을 작성 하시오.*/

struct infor {
	int num;
	int rank;
};


int main() {
	
	struct infor s1[10];
	struct infor temp;


	for (int i = 0; i < 10; i++) {
		scanf("%d", &s1[i].num);
	}

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {

			if (s1[i].num > s1[j].num) {
				temp = s1[i];
				s1[i] = s1[j];
				s1[j] = temp;
			}

		}

	}

	for (int i = 0; i < 10; i++) {
		s1[i].rank = i;
		if (s1[i].rank == 2 || s1[i].rank == 6) {
			printf("%d ", s1[i].num);
		}
	}


	return 0;
}
