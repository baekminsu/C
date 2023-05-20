#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct Stack {
	char stack[101];
	int top;
}Stack;

int OperBoolean(char* s) {
	if (*s == '!' || *s == '+' || *s == '-' || *s == 'p' || *s == 'm') {
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
	else if (*s == '|') {
		return 0;
	}

	return 1;
}

int priority(char* s) {
	if (*s == '|') {
		return 1;
	}
	else if (*s == '&') {
		return 2;
	}
	else if (*s == '<') {
		return 3;
	}
	else if (*s == '>') {
		return 3;
	}
	else if (*s == '-') {
		return 4;
	}
	else if (*s == '+') {
		return 4;
	}
	else if (*s == '/') {
		return 5;
	}
	else if (*s == '*') {
		return 5;
	}
	else if (*s == 'm') {
		return 6;
	}
	else if (*s == 'p') {
		return 7;
	}
	else if (*s == '!') {
		return 8;
	}
	else {
		return 0;
	}
}

void push(Stack* s, char* ele) {
	if (s->top >= 101) {
		return;
	}
	s->top++;
	s->stack[s->top] = *ele;
}

void pop(Stack* s) {
	if (s->top <= -1) {
		return;
	}
	s->top--;
	if ((s->stack[s->top + 1] == '(') || (s->stack[s->top + 1] == ')')) {
		return;
	}
	if (s->stack[s->top + 1] == 'p') {
		printf("+");
		return;
	}
	if (s->stack[s->top + 1] == 'm') {
		printf("-");
		return;
	}
	printf("%c", s->stack[s->top + 1]);
}


void convert(char* s) {
	Stack empty;
	Stack* p;
	p = &empty;
	p->top = -1;
	int cnt = 0;
	while (*s != '\0') {
		cnt++;
		if (*s == '-' || *s == '+') {
			if (*(s - 1) == '-' || *(s - 1) == '+' || cnt == 1) {
				if (*s == '-') {
					*s = 'm';
				}
				else {
					*s = 'p';
				}
			}
		}

		if (*s == '(') {
			push(p, s);
		}
		else if (*s == ')') {
			while (p->stack[p->top] != '(') {
				pop(p);
			}
			p->top--;
		}
		else if (OperBoolean(s) == 1) {
			printf("%c", *s);
		}
		else {
			while (p->top > -1 && priority(&p->stack[p->top]) >= priority(s)) { // 현재 s 보다 스택이더크면
				pop(p);
			}
			if (priority(s) == 1 || priority(s) == 2) {
				push(p, s);
				push(p, s);
				s++;
			}
			else {
				push(p, s);
			}

		}
		s++;
	}

	while (p->top > -1) {
		pop(p);
	}

}

int main() {

	int N;
	scanf("%d", &N);
	getchar();

	Stack s;
	Stack* stack;

	stack = &s;
	stack->top = -1;

	for (int i = 0; i < N; i++) {
		gets(stack->stack);
		convert(stack->stack);
		printf("\n");
	}

	return 0;
}
