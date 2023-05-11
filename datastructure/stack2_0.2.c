#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)

typedef struct Stack {
	char stack[1000];
	int top;
}Stack;

void push(Stack *s,char ele) {
	s->top++;
	s->stack[s->top] = ele;
}

char pop(Stack* s) {
	s->top--;
	return s->stack[s->top];
}

int isBalenced(char *p) {

	char* q;
	q = p;
	Stack empty;
	Stack* stack;
	stack = &empty;
	stack->top = -1;

	while (*q != '\0') {

		if ((*q == '(') || (*q == '{') || (*q == '[')) {
			push(stack,*q);
		}
		else if ((*q == ')') || (*q == '}') || (*q == ']')) {
			
		}
		q++;
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
			*p == ')' || *p == '}' || *p == ']'
			) {
			cnt++;
		}	
		p++;
	}

	if (boolean == 0) {
		printf("OK_");
	}
	else if (boolean == 1) {
		printf("Wrong_");
	}
	printf("%d", cnt);

	return  0;
}
