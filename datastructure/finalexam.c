#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)

char stack[10000];
int top = -1;

int main() {

	scanf("%s", stack);

for (int i = 0; i < strlen(stack); i++) {
		if (stack[i] == '(') {
			top++;
			stack[top] = '(';
		}
		else if (stack[i] == ')') {
			if (stack[i + 1] == ')') {
				printf("duplicate");
				break;
			}
			if (top == -1) {
				return 0;
			}
			else {
				top--;
			}
		}
	}
	if (top == -1) {
		printf("not duplicate");
	}

	return 0;
}
