#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/* 한 학생의 시험 결과 정보(가장 높은 점수, 가장 낮은 점수, 시험 통과
여부, 합격 기준 점수차, 점수차)를 입력 받는다. 이 학생의 점수차와 시험 통과 여부(P 혹은 F)를
출력하는 프로그램을 작성하시오.*/

struct result {
	int high;
	int low;
	char pass;
	int cha;
	int cha2;
};

void passorfail(struct result* sp) {
	if (sp->cha2 >= sp->cha) {
		sp->pass = 'F';
	}
	else {
		sp->pass = 'P';
	}
}


int main() {
	int high, low, cha;
	struct result s1;
	scanf("%d %d %d",&s1.high, &s1.low ,&s1.cha);
	s1.cha2 = s1.high - s1.low;
	passorfail(&s1);

	printf("%d %c", s1.cha2, s1.pass);
	
	return 0;
}
