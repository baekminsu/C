#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)

typedef struct Stack {
	char* stack;
	int top;
}Stack;

void pop(Stack *s) {
	if (s->top == -1) {
		printf("Stack Empty\n");
	}
	else {
		s->top -= 1;
		printf("%c", s->stack[s->top]);
	}
}

void push(Stack *s,char ele,int n) {
	if (s->top == n - 1) {
		printf("Stack FULL");
	}
	s->top++;
	s->stack[s->top] = ele;
}

void print(Stack *s) {
	for (int i = s->top; i > -1; i--) {
		printf("%c", s->stack[i]);
	}
	printf("\n");
}

void init(Stack* s, int n ) {
	s->stack = malloc(sizeof(char) * n);
	s->top = -1;
}

void upRotate(Stack* s, int n) {
	int temp;
	for (int i = 0; i < n; i++) {

	}


}

int main() {

	int n;
	scanf("%d", &n);
	Stack* s;
	s = (Stack*)malloc(sizeof(Stack));
	init(s, n);

	int oper;
	char oper2[6];
	char ele;
	scanf("%d", &oper); // 연산의 개수

	for (int i = 0; i < oper; i++) {
		scanf("%s", oper2);
		getchar();
		if (oper2[0] == 'P') {
			if (oper2[1] == 'O') {
				pop(s);
			}
			else if (oper2[1] == 'U') {
				scanf("%c", &ele);
				getchar();
				push(s, ele,n);
			}
			else if (oper2[1] == 'R') {
				print(s);
			}
			else if (oper2[1] == 'E') {

			}
		}
		else if (oper2[0] == 'U') {
			upRotate(s, n);
		}
		else if (oper2[0] == 'D') {
			if (oper2[1] == 'o') {

			}
			else if (oper2[1] == 'U') {

			}

		}
	}

	free(s);
	return 0;
}
