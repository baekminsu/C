#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct Stack {
	char stack[1001];
	int top;
}Stack;

void push(Stack *s,char ele) {
	if (s->top >= 1000 ) {
		return;
	}
	s->top++;
	s->stack[s->top] = ele;
}

char pop(Stack* s) {
	if (s->top <= -1) {
		return 'x';
	}
	s->top--;
	return s->stack[s->top+1];
}

int isBalenced(char *p) {

	char* q;
	q = p;
	Stack empty;
	Stack* stack;
	stack = &empty;
	stack->top = -1;
	char tpop;

	while (*q) {

		if ((*q == '(') || (*q == '{') || (*q == '[')) {
			push(stack,*q);
		}
		else if ((*q == ')') || (*q == '}') || (*q == ']')) {
			tpop = pop(stack);
			if (*q == ')') {
				if (tpop != '(') {
					return 1;
				}

			}
			else if (*q == '}') {
				if (tpop != '{') {
					return 1;
				}
			}
			else if ( *q == ']') {
				if (tpop != '[') {
					return 1;
				}
			}
		}
		q++;
	}

	if (stack->top != -1) {
		return 1;
	}

	
	return 0;
}

int main() {

	char input[1001];
	int boolean = 0 ;
	gets(input);
	boolean = isBalenced(input);
	char* p;
	p = input;
	int cnt = 0;

	while (*p != '\0') {
		if (*p == '(' || *p == '{' || *p == '[' ||
			*p == ')' || *p == '}' || *p == ']'	) {
			cnt++;
		}	
		p++;
	}

	if (boolean == 0 && ((cnt %2) == 0)) {
		printf("OK_");
	}
	else {
		printf("Wrong_");
	}

	printf("%d\n", cnt);

	return  0;
}
