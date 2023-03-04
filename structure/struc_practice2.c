#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*구조체를 이용하여서 현재 시각을 표현한다. 사용자로부터 2개의 시각 
을 입력 받아서 두 시각 사이의 차이를 계산하여 출력하는 프로그램을 작성하시오..*/

struct time {
	int hour;
	int min;
	int sec;
};

int main() { //1초  1분 =60초 60분 = 3600초

	struct time s1;
	struct time s2;
	struct time s3;
	int sec = 0;
	int sec2 = 0;

	scanf("%d %d %d", &s1.hour, &s1.min, &s1.sec);
	scanf("%d %d %d", &s2.hour, &s2.min, &s2.sec);

	sec = (s1.hour * 3600) + (s1.min * 60) + (s1.sec);
	sec2 = (s2.hour * 3600) + (s2.min * 60) + (s2.sec);

	sec2 = sec2 - sec;
	s3.hour = sec2 / 3600;
	sec2 = sec2 % 3600;
	s3.min = sec2 / 60;
	sec2 = sec2 % 60;
	printf("%d %d %d", s3.hour, s3.min, sec2);


	return 0;
}
