#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct Node {
	int data;
	struct Node* link;
}Node;

Node* CreateNode(void) {
	Node* NewNode;
	NewNode = (Node*)malloc(sizeof(Node));

	NewNode->link = NULL;
	NewNode->data = 0;
	return NewNode;
}

void AppendNode(Node* k, int data) {
	Node* NewNode;
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = data;
	NewNode->link = NULL;
	Node* p;

	if (k->link == NULL) {
		k->link = NewNode;
		return;
	}
	else {
		p = k->link;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = NewNode;
	}
}

void ShowNode(Node* k) {
	Node* p = k->link;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
}

int Subset(Node* first, Node* second) {
	

	if (first->link == NULL) {
		return 0;
	}

	while (first != NULL) {

		if (second == NULL) {
			return first->data;
		}
		else if (first->data < second->data) {
			return first->data;
		}
		else if (first->data > second->data) {
			second = second->link;
		}
		else {
			first = first->link;
	/*		if (second->link == NULL) {
				return first->data;
			}*/
			second = second->link;
		}

	}
	return 0;
}

int main() {

	int A, B;
	int input;
	scanf("%d", &A);

	Node* X;
	Node* Y;

	X = CreateNode();
	Y = CreateNode();

	for (int i = 0; i < A; i++) {
		scanf("%d", &input);
		AppendNode(X, input);
	}

	scanf("%d", &B);

	for (int i = 0; i < B; i++) {
		scanf("%d", &input);
		AppendNode(Y, input);
	}

	printf("%d",Subset(X, Y));

	return 0;
}
