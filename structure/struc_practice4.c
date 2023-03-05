#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*N명의 학생에 대해 이름과 세 번 본 시험의 성적을 읽어 들여, 각 학 
생의 이름과 평균점수(소수점이하 첫째자리 까지), 학점을 출력하는 프로그램을 작성하시오.*/


struct infor {
	char name[19];
	double score;
	double score2;
	double score3;
	double avg;
	char rank;
};

int main() {

	int N;
	scanf("%d", &N);
	struct infor student[20];

	for (int i = 0; i < N; i++) {
		scanf("%s %lf %lf %lf", student[i].name, &student[i].score, &student[i].score2, &student[i].score3);

		student[i].avg = (student[i].score + student[i].score2 + student[i].score3) / 3.0;
		if (student[i].avg >= 90) {
			student[i].rank = 'A';
		}
		else if (student[i].avg >= 80 && student[i].avg <90) {
			student[i].rank = 'B';
		}
		else if (student[i].avg >= 70 && student[i].avg < 80) {
			student[i].rank = 'C';
		}
		else {
			student[i].rank = 'F';
		}
		printf("%s %.1lf %c\n", student[i].name, student[i].avg, student[i].rank);
	}


	return 0;
}
