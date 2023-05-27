#include <stdio.h>
#include <stdlib.h> // malloc

#define _crt_secure_no_warnings
#pragma warning(disable:4996)

typedef struct Node {
	struct Node* llink;
	int ele;
	struct Node* rlink;
}Node;

typedef struct Deque {
	Node* front;
	Node* rear;
}Deque;

void init(Deque* deque) {
	deque->front = NULL;
	deque->rear = NULL;
}

void add_front(Deque* deque, int X) {

	Node* NewNode;
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->ele = X;
	NewNode->llink = NULL;
	NewNode->rlink = NULL;

	if (deque->front == NULL) {
		deque->front = NewNode; //
		deque->rear = NewNode; // 붙여준다가 아니라 포인터로 NewNode에 지정한다는개념 "포인터"
	}
	else {
		NewNode->rlink = deque->front;
		deque->front->llink = NewNode;
		deque->front = NewNode;
	}

}

void add_rear(Deque* deque, int X) {

	Node* NewNode;
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->ele = X;
	NewNode->llink = NULL;
	NewNode->rlink = NULL;


	if (deque->rear == NULL) {
		deque->front = NewNode;
		deque->rear = NewNode;
	}
	else {
		NewNode->llink = deque->rear;
		deque->rear->rlink = NewNode;
		deque->rear = NewNode;
	}
}

void print(Deque* deque) {
	Node* p;
	p = deque->front;
	while (p) {
		printf(" %d", p->ele);
		p = p->rlink;		
	}
	printf("\n");

}

void delete_front(Deque* deque) {
	Node* p = deque->front;
	if (isEmpty(deque)) {
		return;
	}
	else {
		if (deque->front->rlink == NULL) {
			deque->front = NULL;
			deque->rear = NULL;
		}
		else {
			deque->front = deque->front->rlink;
			deque->front->llink = NULL;
		}
	}
}

void delete_rear(Deque* deque) {
	Node* p = deque->rear;
	if (isEmpty(deque)) {
		return;
	}
	else {
		if (deque->front->rlink == NULL) {
			deque->front = NULL;
			deque->rear = NULL;
		}
		else {
			deque->rear = deque->rear->llink;
			deque->rear->rlink = NULL;
		}
	}
}

int isEmpty(Deque* deque) {
	if (deque->front == NULL) {
		printf("underflow");
		exit(1);
	}
	else {
		return 0;
	}
}

int main() {

	char command[3];
	int N;
	int X;

	scanf("%d", &N);

	Deque deque;
	init(&deque);

	for (int i = 0; i < N; i++) {

		getchar();
		scanf("%s", command);

		if (command[0] == 'A') {
			if (command[1] == 'F') {
				scanf("%d", &X);
				add_front(&deque, X);
			}
			else if (command[1] == 'R') {
				scanf("%d", &X);
				add_rear(&deque, X);
			}
		}
		else if (command[0] == 'P') {
			print(&deque);
		}
		else if (command[0] == 'D') {
			if (command[1] == 'F') {
				delete_front(&deque);
			}
			else if (command[1] == 'R') {
				delete_rear(&deque);
			}
		}
	}



	return 0;
}
