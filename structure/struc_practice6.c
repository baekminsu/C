#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*학급 학생의 수를 입력 받은 후, 각 학생의 성별, 체중, 키를 입력 받 
으시오. 아래 표에 따라 신체등급별 인원 수를 출력하는 프로그램을 작성하시오.*/

struct student {
	int sex;
	int kg;
	int toll;
};

int main() {
	int N;

	scanf("%d", &N);
	struct student s1[10];
	int one = 0, two = 0, three = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &s1[i].sex, &s1[i].kg, &s1[i].toll);

		if (s1[i].sex == 1) {
			if (s1[i].kg < 60) {
				if (s1[i].toll < 165) {
					one++;
				}
				else if (s1[i].toll >= 165 && s1[i].toll < 175) {
					two++;
				}
				else {
					three++;
				}
			}
			else if (s1[i].kg >= 60 && s1[i].kg < 70) {
				if (s1[i].toll < 165) {
					three++;
				}
				else if (s1[i].toll >= 165 && s1[i].toll < 175) {
					one++;
				}
				else {
					two++;
				}
			}
			else {
				if (s1[i].toll < 165) {
					two++;
				}
				else if (s1[i].toll >= 165 && s1[i].toll < 175) {
					three++;
				}
				else {
					one++;
				}
			}

		}
		else {
			if (s1[i].kg < 50) {
				if (s1[i].toll < 165) {
					one++;
				}
				else if (s1[i].toll >= 165 && s1[i].toll < 175) {
					two++;
				}
				else {
					three++;
				}
			}
			else if (s1[i].kg >= 50 && s1[i].kg < 60) {
				if (s1[i].toll < 165) {
					three++;
				}
				else if (s1[i].toll >= 165 && s1[i].toll < 175) {
					one++;
				}
				else {
					two++;
				}
			}
			else {
				if (s1[i].toll < 165) {
					two++;
				}
				else if (s1[i].toll >= 165 && s1[i].toll < 175) {
					three++;
				}
				else {
					one++;
				}
			}
		}

	}

	printf("%d %d %d", one, two, three);
	return 0;
}
