#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*
N명의 학생에 대한 정보(이름, 국어 성적, 영어 성적, 수학 성적)를 동적
메모리 할당을 사용하여 입력 받아, 각 학생의 평균 성적과 GREAT 혹은 BAD를 출력하는 프로그
램을 작성하시오.
*/

typedef struct student {
	char name[8];
	int score;
	int score2;
	int score3;
	double avg;
}student;

int main() {

	student* sp = NULL;
	int N;
	scanf("%d", &N);
	sp = (student*)malloc(N * sizeof(student));
	
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d %d",
			sp[i].name, &sp[i].score, &sp[i].score2, &sp[i].score3);
		sp[i].avg = (sp[i].score + sp[i].score2 + sp[i].score3) / 3.0;
	} 

	for (int i = 0; i < N; i++) {
		printf("%s %.1lf ", sp[i].name, sp[i].avg);
		if (sp[i].score >= 90 || sp[i].score2 >= 90 || sp[i].score3 >= 90) {
			printf("GREAT ");
		}
		if (sp[i].score < 70 || sp[i].score2 < 70 || sp[i].score3 < 70) {
			printf("BAD");
		}
		printf("\n");

	}


	free(sp);

	return 0;
}
