#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct ListNode {
	int coef; //항의 계수
	int exp; // 항의 차수
	struct ListNode* next; // 단일연결리스트니까
}ListNode;

typedef struct ListHead {
	ListNode* head;
}ListHead;

ListNode* createLinkedList(void) {
	ListNode* L;
	L = (ListNode *)malloc(sizeof(ListNode));
	L->next = NULL;

	return L;
}

void appendTerm(ListNode* k, int coef, int exp) {
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->coef = coef;
	newnode->exp = exp;
	newnode->next = NULL;
	ListNode* p;


	if (k->next == NULL) {
		k->next = newnode;
		return;
	}
	else {
		p = k->next;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = newnode;
	}

}

ListNode* addPoly(ListNode* x, ListNode* y) {
	ListNode* result = (ListNode*)malloc(sizeof(ListNode));
	result->next = NULL;
	result->coef = 0;
	result->exp = 0;

	ListNode* i = x->next;
	ListNode* j = y->next;

	ListNode* k = result;

	while ((i != NULL) && (j != NULL)) {
		if (i->exp > j->exp) {
			appendTerm(k, i->coef, i->exp);
			i = i->next;
		}
		else if (i->exp < j->exp) {
			appendTerm(k, j->coef, j->exp);
			j = j->next;
		}
		else {
			int sum = i->coef + j->coef;
			if (sum != 0) {
				appendTerm(k, sum, i->exp);
			}
			i = i->next;
			j = j->next;
		}
	}
	while (i != NULL) {
		appendTerm(k, i->coef, i->exp);
		i = i->next;
	}

	while (j != NULL) {
		appendTerm(k, j->coef, j->exp);
		j = j->next;
	}
	return result;
}

void printPoly(ListNode* header) {
	ListNode* p = header->next;
	while (p != NULL) {
		printf(" %d %d", p->coef, p->exp);
		p = p->next;
	}
}

int main() {
	
	ListNode* A;
	ListNode* B;
	ListNode* C;

	int N;
	int coef, exp; // 항의 계수 , 항의 차수

	A = createLinkedList();
	B = createLinkedList();
	C = createLinkedList();

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &coef, &exp);
		appendTerm(A, coef, exp);
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &coef, &exp);
		appendTerm(B, coef, exp);
	}

	C = addPoly(A, B);
	printPoly(C);

	return 0;
}
