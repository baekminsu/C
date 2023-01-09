#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*사용자로부터 두 개의 시각을 입력 받아서 두 시각 사이의 차이를 계산하여 출력하는 
프로그램을 작성하시오.*/

typedef struct time {
	int hour;
	int min;
	int sec;
}time;


int main() {
	//1초 60초 3600초
	time a[3] = { 0, };
	int hab;
	int hab2;
	int result;

	scanf("%d %d %d", &a[0].hour, &a[0].min, &a[0].sec);
	hab = (a[0].hour * 3600) + (a[0].min * 60) + (a[0].sec * 1);
	scanf("%d %d %d", &a[1].hour, &a[1].min, &a[1].sec);
	hab2 = (a[1].hour * 3600) + (a[1].min * 60) + (a[1].sec * 1);
	result = hab2 - hab;

	//printf("%d", result);
	a[2].hour = result / 3600;
	result = result % 3600;
	a[2].min = result / 60;
	result = result % 60;
	a[2].sec = result;
	
	printf("%d %d %d", a[2].hour, a[2].min, a[2].sec);


	return 0;
}
