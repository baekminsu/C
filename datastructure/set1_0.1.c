#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct Node {
	int data;
	struct Node* link;
}Node;

Node* CreateNode(void){
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

/*void ShowNode(Node* k) {
	Node* p = k->link;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
}*/

void Subset(Node* first, Node* second) {
	int cnt = 0;
	int check = 0;
	int cnt2 = 0;
	int max = 0;
	Node* p = first;
	Node* q;
	max = 0;
	while (p->link != NULL) {
		cnt = cnt + 1;
		if (max < p->data) {
			max = p->data;
		}
		p = p->link;
	}
	if (max < p->data) {
		max = p->data;
	}
	p = first;
	while (p != NULL) {
		q = second;
		while (q != NULL) {
			if (p->data == q->data) {
				cnt2++;
				break;
			}
			q = q->link;
		}
		if (cnt2 > 0) {
			check++;
		}
		cnt2 = 0;
		p = p->link;
	}

	if (check == cnt) {
		printf("0");
	}
	else {
		printf("%d", max);
	}
}

int main() {

	int A,B;
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
		AppendNode(Y,input);
	}

	Subset(X, Y);

	//ShowNode(X);
	//printf("\n");
	//ShowNode(Y);

	return 0;
}
