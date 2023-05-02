#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct Node {
	int ele;
	struct Node* next;
}Node;

typedef struct List {
	struct Node* head;
	int count;
}List;

List* CreateList(){
	List* list;
	list = (List*)malloc(sizeof(List));
	list->head = NULL;
	list->count = 0;
	return list;
}

void AppendNode(List* k, int num) {
	Node* new;
	new = (Node*)malloc(sizeof(Node));
	new->ele = num;
	new->next = NULL;

	if (k->head == NULL) {
		k->head = new;
	}
	else {
		Node* p;
		p = k->head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = new;

	}
	k->count++;
}

void ShowList(List* k) {
	
	Node* current;
	current= k->head;

	while (current != NULL) {
		printf(" %d", current->ele);
		current = current->next;
	}

}

void Union(List* A, List* B) {

	List* C;

	Node* p = A->head;
	Node* q = B->head;

	C = CreateList();

	while (p != NULL && q != NULL) {

		if (p->ele > q->ele) {
			AppendNode(C, q->ele);
			q = q->next;
		}
		else if (p->ele < q->ele) {
			AppendNode(C, p->ele);
			p = p->next;
		}
		else {
			AppendNode(C, p->ele);
			p = p->next;
			q = q->next;
		}
	}
	while (p) {
		AppendNode(C, p->ele);
		p = p->next;
	}
	while (q) {
		AppendNode(C, q->ele);
		q = q->next;
	}
	ShowList(C);
}

void Intersect(List* A, List* B) {

	List* C;
	C = CreateList();
	int cnt = 0;
	Node* p;
	Node* q;
	p = A->head;
	q = B->head;

	while (p != NULL && q != NULL) {

		if (p->ele == q->ele) {
			AppendNode(C, p->ele);
			cnt++;
			p = p->next;
			q = q->next;
		}
		else if (p->ele > q->ele) {
			q = q->next;
		}
		else {
			p = p->next;
		}

	}


	if (cnt == 0) {
		printf(" 0");
	}
	else {
		ShowList(C);
	}


}


int main() {

	int A,B;
	int num;

	List* AN;
	List* BN;
	AN = CreateList();
	BN = CreateList();

	scanf("%d", &A);

	for (int i = 0; i < A; i++) {
-		scanf("%d", &num);
		AppendNode(AN,num);
	}

	scanf("%d", &B);

	for (int i = 0; i < B; i++) {
		scanf("%d", &num);
		AppendNode(BN, num);
	}

	//ShowList(AN);
	Union(AN, BN);
	if (A == 0 && B == 0) {
		printf(" 0");
	}
	printf("\n");
	Intersect(AN, BN);

	return 0;
}
