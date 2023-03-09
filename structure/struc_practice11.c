#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

struct student {
	char name[9];
	int score;
};

struct student* select_min(struct student *sp){
	struct student* sq;
	struct student* loww =NULL;
	int low = 101;
	for (sq = sp; sq < sp + 5; sq++) {
		if (low > sq->score) {
			low = sq->score;
			loww = sq;
		}
	}

	return loww;
}



int main() {

	struct student s1[5];
	struct student* p;
	for (int i = 0; i < 5; i++) {
		scanf("%s %d", s1[i].name,&s1[i].score);
	}

	p = select_min(s1);

	printf("%s %d", p->name, p->score);

	return 0;
}
