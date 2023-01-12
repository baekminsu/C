#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

/*N명의 학생에 대한 정보(이름, 국어 성적, 영어 성적, 수학 성적)를 입력 받아, 각 학생의
평균 성적과 GREAT 혹은 BAD을 출력하는 프로그램을 작성하시오.*/

typedef struct st{
	char name[7];
	int kor;
	int eng;
	int math;
	double avg;
}student;

int main() {
	int n;
	int i;
	char name[7];
	
	scanf("%d", &n);
	
	student* p1 = (student*)malloc(sizeof(student) *n );

	for (i = 0; i < n; i++) {
		scanf("%s", name);
		strcpy(p1[i].name, name);
		scanf("%d", &p1[i].kor);
		scanf("%d", &p1[i].eng);
		scanf("%d", &p1[i].math);
		p1[i].avg = (p1[i].kor + p1[i].eng + p1[i].math);
		p1[i].avg = p1[i].avg / 3.0;
		if (p1[i].kor >= 90 || p1[i].eng >= 90 || p1[i].math) {
			printf("%s ", p1[i].name);
			printf("%.1lf ", p1[i].avg);
			printf("GREAT ");
			if (p1[i].kor < 70 || p1[i].eng < 70 || p1[i].math < 70) {
				printf("BAD");
			}
			printf("\n");
		}
	}

	free(p1);


	return 0;
}
