#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*10명 학생의 이름과 3회 퀴즈 점수를 입력으로 받아 퀴즈 평균 점수
가 최고점과 최저점인 학생의 이름과 평균 점수를 출력하고, 퀴즈 평균 점수가 하위 30 % 에 속하
는 학생의 이름과 퀴즈 평균 점수를 출력하는 프로그램을 다음 함수들을 사용하여 작성합니다.*/


struct student {
	char name[9];
	int score;
	int score2;
	int score3;
	double avg;
};

void read_data(struct student* p) {
	for (int i = 0; i < 10; i++) {
		scanf("%s %d %d %d", &p[i].name, &p[i].score, &p[i].score2, &p[i].score3);
	}

}

void cal_avg(struct student* p) {
	
	for (int i = 0; i < 10; i++) {
		p[i].avg = (p[i].score + p[i].score2 + p[i].score3) / 3.0;
	}
}

void sort(struct student* p) {
	struct student temp;
	for (int i = 0; i < 10; i++) {
		for (int j = i+1 ; j < 10; j++) {
			if (p[i].avg < p[j].avg) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}

}

void print_score(struct student* p) {
	printf("%s %.2lf\n", p[0].name, p[0].avg);
	printf("%s %.2lf\n", p[9].name, p[9].avg);
	printf("%s %.2lf\n", p[7].name, p[7].avg);
	printf("%s %.2lf\n", p[8].name, p[8].avg);
	printf("%s %.2lf\n", p[9].name, p[9].avg);
	
}

int main() {
	struct student s1[10];
	read_data(&s1[0]);
	cal_avg(&s1[0]);
	sort(&s1[0]);
	print_score(&s1[0]);
	
	/*for (int i = 0; i < 10; i++) {
		printf("%s %d %d %d %lf\n",
			s1[i].name, s1[i].score, s1[i].score2, s1[i].score3,s1[i].avg);
	}*/

	return 0;
}
