#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct Stack {
	int stack[101];
	int top;
}Stack;

int doOperator(char* op, int x, int y) {
	int result = 0;
	char* p;

	if (*op == '+') {
		result = x + y;
	}
	else if (*op == '-') {
		result = x - y;
	}
	else if (*op == '*') {
		result = x * y;
	}
	else if (*op == '/') {
		result = x / y;
	}

	return result;
}

int pop(Stack* S) {
	if (S->top <= -1) {
		return;
	}
	S->top--;
	return S->stack[S->top +1];
}

void push(Stack* S, int ele) {
	if (S->top >= 100) {
		return;
	}
	S->top++;
	S->stack[S->top] = ele;
}


int isOperand(char* s) {
	if (*s == '+') {
		return 1;
	}
	else if (*s == '-') {
		return 1;
	}
	else if (*s == '*') {
		return 1;
	}
	else if (*s == '/') {
		return 1;
	}
	else {
		return 0;
	}
}

void evaluate(char* s) {

	Stack S;
	Stack* stack;
	stack = &S;
	char* p;
	p = s;
	int a;
	int b;
	int convert;
	stack->top = -1;

	while (*p != NULL) {

		if (isOperand(p) == 0) {
			convert = *p % '0';
			push(stack, convert);
		}
		else { //*p is an operator
			a = pop(stack); 
			b = pop(stack);
			push(stack, doOperator(p, b, a)); //doOperator는 char *p 포인터로반납
		}
		p++;
	}

	printf("%d", stack->stack[stack->top]);

}

int main() {

	int N;
	scanf("%d", &N);
	char input[101];

	for (int i = 0; i < N; i++) {
		scanf("%s",input);
		getchar();
		evaluate(input);
		printf("\n");
	}

	return 0;
}
