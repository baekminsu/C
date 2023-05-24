#include <stdio.h>
#include <stdlib.h> // malloc

#define _crt_secure_no_warnings
#pragma warning(disable:4996)

typedef struct Node{
	struct Node* front;
	int ele;
	struct Node* rear;
}Node;

void print(Node* deque) {

	Node* p;
	p = deque->front;

	while (p != NULL) {
		p = p->front;
	}

	printf(" %d", p->ele);
	p = p->ele;

	while (p != NULL) {
		printf(" %d", p->ele);
		p = p->ele;
	}

}

void add_rear(Node* deque, int X) {

	Node* NewNode;
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->ele = X;
	NewNode->rear = NULL;
	if (deque->rear == NULL) {
		deque->rear = NewNode;
	}
	else {
		Node* p;
		p = deque->rear;
		while (p->rear != NULL) {

			p = p->rear;

		}
	}
}


void add_front(Node* deque, int X) {
	Node* NewNode;
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->ele = X;
	NewNode->front = NULL;
	if (deque->front == NULL) {
		deque->front = NewNode;
	}
	else {
		Node* p;
		p = deque->front;
		while (p != NULL) {

			p = p->front;

		}
		p->front = NewNode;
	}
}

Node* init() {
	Node* n;
	n = (Node*)malloc(sizeof(Node));
	n->front = NULL;
	n->rear = NULL;
	return n;
}

int main() {

	int N;
	char com[3];
	int X;
	scanf("%d", &N);

	Node* deque;

	deque = init();

	for (int i = 0; i < N; i++) {

		getchar();
		scanf("%s", com);

		if (com[0] == 'A') {

			if (com[1] == 'F') {
				scanf("%d", &X);
				add_front(deque, X);
			}
			else if (com[1] == 'R') {
				scanf("%d", &X);
				add_rear(deque, X);
			}

		}
		else if (com[0] == 'P') {
			print(deque);
		}



	}

	return 0;
}
