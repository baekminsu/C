#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/* year/month/day 형식의 두 날짜를 입력 받아, 각각 구조체 변수에
저장하고, 두 날짜 중 더 빠른 날짜를 같은 형식으로 출력하는 프로그램을 작성 하시오.*/

struct time {
	int year;
	int month;
	int day;
};

struct time* select_min(struct time sp, struct time sp2) {
	struct time* sq =NULL;
	if (sp.year < sp2.year) {
		sq = &sp;
		return sq;
	}
	else if (sp.year > sp2.year) {
		sq = &sp2;
		return sq;
	}
	else {

		if (sp.month < sp2.month) {
			sq = &sp;
			return sq;
		}
		else if (sp.month > sp2.month) {
			sq = &sp2;
			return sq;
		}
		else {

			if (sp.day < sp2.day) {
				sq = &sp;
				return sq;
			}
			else {
				sq = &sp2;
				return sq;
			}

		}


		
	}

	return sq;
}

int main() {
	char input[11];
	char input2[11];
	struct time s1, s2;
	struct time* sp = NULL;
	char myear[5] = { 0 ,};
	char mmonth[3] = { 0 , };
	char mday[3] = { 0 , };
	char myear2[5] = { 0 , };
	char mmonth2[3] = { 0 , };
	char mday2[3] = { 0 , };
	int i = 0 , j = 0 ;
	
	scanf("%s", input);
	getchar();
	scanf("%s", input2);

	for (i = 0; i < strlen(input); i++) {
		if (input[i] != '/') {
			myear[i] = input[i];
		}
		else {
			myear[i] = '\0';
			break;
		}
	}

	for (i= i+1; i < strlen(input); i++) {
		if (input[i] != '/') {
			mmonth[j] = input[i];
			j++;
		}
		else {
			mmonth[j] = '\0';
			break;
		}
	}
	j = 0;
	for (i = i+1; i < strlen(input); i++) {
		if (input[i] != '\0') {
			mday[j] = input[i];
			j++;
		}
		else {
			myear[j] = '\0';
			break;
		}
	}
	j = 0;

	//////////////
	for (i = 0; i < strlen(input2); i++) {
		if (input2[i] != '/') {
			myear2[i] = input2[i];
		}
		else {
			myear2[i] = '\0';
			break;
		}
	}

	for (i = i + 1; i < strlen(input2); i++) {
		if (input2[i] != '/') {
			mmonth2[j] = input2[i];
			j++;
		}
		else {
			mmonth2[j] = '\0';
			break;
		}
	}
	j = 0;
	for (i = i + 1; i < strlen(input2); i++) {
		if (input2[i] != '\0') {
			mday2[j] = input2[i];
			j++;
		}
		else {
			myear2[j] = '\0';
			break;
		}
	}
	j = 0;

	s1.year = atoi(myear);  //atoi는 문자열을 정수로변환
	s1.month = atoi(mmonth);
	s1.day = atoi(mday);
	s2.year = atoi(myear2); 
	s2.month = atoi(mmonth2); 
	s2.day = atoi(mday2);
	
	sp = select_min(s1, s2);
	printf("%d/%d/%d", sp->year, sp->month,sp->day );

	return 0;
}
