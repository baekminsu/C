#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*N 명의 학생에 대한 정보(이름, 국어 성적, 영어 성적, 수학 성적)를 
입력 받아, 각 학생의 평균 성적에 따라 학점을 산출한 후, 각 학생의 이름과 평균 성적(소수점 이 
하 첫째자리까지)과 학점을 출력하는 프로그램을 작성하시오.*/

struct student {
	char name[7];
	int score;
	int score2;
	int score3;
	double avg;
	char rank;
};

int main() {
	int N;
	struct student st[50];
	struct student *p = st;

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d %d", (p + i)->name, &(p + i)->score, &(p + i)->score2, &(p + i)->score3);
		(p+i)->avg = ((p + i)->score +  (p + i)->score2 + (p + i)->score3) / 3.0;

		if ((p + i)->avg >= 90 && (p + i)->avg <= 100) {
			(p+i)->rank = 'A';
		}
		else if ((p + i)->avg >= 80 && (p + i)->avg < 90) {
			(p + i)->rank = 'B';
		}
		else if ((p + i)->avg >= 70 && (p + i)->avg < 80) {
			(p + i)->rank = 'C';
		}
		else {
			(p + i)->rank = 'D';
		}
		printf("%s %.1lf %c\n", (p + i)->name, (p + i)->avg, (p + i)->rank);

	}


	return 0;
}
