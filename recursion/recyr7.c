#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int recur(char* input, int last,char input2) {
	if (last != 0) {

		if (*(input + strlen(input) - 1 - last) == input2) {
			return 1 + recur(input, last - 1, input2);
		}
		else {
			return 0 + recur(input, last - 1, input2);
		}

	}
	else {

		if (*(input + strlen(input) - 1) == input2) {
			return 1;
		}
		else {
			return 0;
		}

	}




}


int main() {
	char input[101];
	char input2;

	scanf("%s", input);
	getchar();
	scanf("%c", &input2);

	printf("%d", recur(input, strlen(input) - 1,input2));


	return 0;
}
