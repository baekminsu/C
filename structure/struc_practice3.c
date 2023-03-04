#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*5명 학생의 이름과 기말고사 점수를 입력 받아, 구조체 배열에 저장 
한 후, 평균 이하의 점수를 받은 학생의 이름을 출력하는 프로그램을 작성 하시오.*/


struct test {
	char name[9];
	int score;
};

int main() {

	struct test s1[5];
	int sum = 0;
	int avg = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%s %d", s1[i].name, &s1[i].score);
		sum = sum + s1[i].score;
	}
	avg = sum / 5;

	for (int i = 0; i < 5; i++) {
		if (avg >= s1[i].score) {
			printf("%s\n", s1[i].name);
		}
	}

	return 0;
}
