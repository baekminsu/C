#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct Stack {
	char stack[101];
	int top;
}Stack;

int OperBoolean(char *s) {
	if (*s == '!' || *s == '+' || *s == '-') {
		return 0;
	}
	else if (*s == '*') {
		return 0;
	}
	else if (*s == '/') {
		return 0;
	}
	else if (*s == '>') {
		return 0;
	}
	else if (*s == '<') {
		return 0;
	}
	else if (*s == '&') {
		return 0;
	}



}

char convert(char* s) {
	Stack empty;
	Stack* p;
	p = empty;
	while (s != '\0') {
		if(      )






		s++;
	}

}

int main() {

	int N;
	scanf("%d", &N);
	Stack s;
	Stack* stack;
	stack = s;
	stack->top = -1;

	for (int i = 0; i < N; i++) {
		scanf("%s", stack->stack);
		printf("%s",convert(stack->stack));
	}

	return 0;
}
