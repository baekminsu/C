#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
/*5명 학생의 이름과 기말고사 점수를 입력 받아 평균 ,         이하의 점수를 받은 학생의 이름 
을 출력하는 프로그램을 작성하시오.*/
typedef struct {
	char name[9];
	int score;
}last;

int main() {
	last s[5];
	int sum = 0;
	int avg;

	for (int i = 0; i < 5; i++) {
		scanf("%s", s[i].name);
		scanf("%d", &s[i].score);
		sum = sum + s[i].score;
	}
	avg = sum / 5;

	for (int i = 0; i < 5; i++) {
		if (avg > s[i].score) {
			printf("%s\n", s[i].name);
		}
	}

	return 0;
}
