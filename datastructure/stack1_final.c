#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)

typedef struct Stack {
	char* stack;
	int top;
}Stack;

void pop(Stack* s) {
	if (s->top <= -1) {
		printf("Stack Empty\n");
		return;
	}
	else {
		s->top -= 1;
		//printf("%c\n", s->stack[s->top]);
	}
}

void push(Stack* s, char ele, int n) {
	if (s->top >= n-1 ) {
		printf("Stack FULL\n");
		return;
	}
	else {
		s->top++;
		s->stack[s->top] = ele;
	}
}

void print(Stack* s) {
	for (int i = s->top; i > -1; i--) {
		printf("%c", s->stack[i]);
	}
	printf("\n");
}

void init(Stack* s, int n) {
	s->stack = malloc(sizeof(char) * (n+1));
	s->top = -1;
}

void upRotate(Stack* s, int n) {
	if (n > s->top + 1) {
		return;
	}

	int temp; // 1 2 3 4 5     1 2 5 3 4
	int i;
	temp = s->stack[s->top];
	for (i = s->top; i >= s->top - n + 2; i--) { // 4 ; 3; -- 
		s->stack[i] = s->stack[i - 1];
	}
	s->stack[i] = temp;
}

void peek(Stack* s) {
	if (s->top <= -1) {
		printf("Stack Empty\n");
		return;
	}
	else {
		printf("%c\n", s->stack[s->top]);
	}
}

void downRotate(Stack* s, int n) {
	if (n > s->top + 1) {
		return;
	}
	int temp;  // 1 2 3 4 5    1 3 4 5 2   4
	int i;
	temp = s->stack[s->top - n + 1]; // 6 - 4 +1 = 3
	for (i = s->top - n + 1; i < s->top; i++) {// 6 - 4 +2  = 2
		s->stack[i] = s->stack[i + 1];
	}
	s->stack[i] = temp;
}

void duplicate(Stack* s,int n) {
	char temp;
	if ( s->top >= n) {  
		printf("Stack FULL\n");
		return;
	}
	else {
		temp = s->stack[s->top];
		s->top--;
		push(s, temp, n);
		push(s, temp, n);
	}

}


int main() {

	int n;
	scanf("%d", &n);
	Stack* s;
	s = (Stack*)malloc(sizeof(Stack));
	init(s, n);	

	int oper;
	char oper2[10];
	char ele;
	int Ucom;
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
				push(s, ele, n);
			}
			else if (oper2[1] == 'R') {
				print(s);
			}
			else if (oper2[1] == 'E') {
				peek(s);
			}
		}
		else if (oper2[0] == 'U') {
			scanf("%d", &Ucom);
			upRotate(s, Ucom);
		}
		else if (oper2[0] == 'D') {
			if (oper2[1] == 'o') {
				scanf("%d", &Ucom);
				downRotate(s, Ucom);
			}
			else if (oper2[1] == 'U') {
				duplicate(s,n);
			}

		}
	}

	free(s);
	return 0;
}
