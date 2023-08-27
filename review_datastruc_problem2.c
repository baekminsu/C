#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _crt_secure_no_warnings
#pragma warning(disable:4996)

typedef struct Node {
	struct Node* Llink;
	int num;
	struct Node* Rlink;
}Node;

Node* createNode() {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->Llink = NULL;
	newNode->Rlink = NULL;
	return newNode;
}

Node* findNum(Node* p, int y) {
	if (p == NULL) {
		return NULL;
	}	
	if (p->num == y) {
		return p;
	}
	Node* LlinkResult = findNum(p->Llink, y);
	if (LlinkResult != NULL) {
		return LlinkResult;
	}
	Node* RlinkResult = findNum(p->Rlink, y);
	if (RlinkResult != NULL) {
		return RlinkResult;
	}
	return NULL;
}

void addNode(int x, int y, int z, Node* root) {
	if (x == 0) {
		return;
	}
	if (y != 0) {
		Node* p = root;
		Node* p0 =findNum(p, x);
		Node* Newnode = createNode();
		Newnode->num = y;
		p0->Llink = Newnode;
	}
	if (z != 0) {
		Node* p = root;
		Node* p0 = findNum(p, x);
		Node* Newnode2 = createNode();
		Newnode2->num = z;
		p0->Rlink = Newnode2;
	}
	return;
}

int main() {
	int x, y, z;
	int N;
	char search[101];
	Node* root = NULL;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &x, &y, &z);
		if (root == NULL) {
			root = createNode();
			root->num = x;
			Node* Newnode = createNode();
			Newnode->num = y;
			root->Llink = Newnode;
			Node* Newnode2 = createNode();
			Newnode2->num = z;
			root->Rlink = Newnode2;
			continue;
		}
		addNode(x, y, z, root);
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		Node* p = root;
		getchar();
		scanf("%s", search);
		printf("%d", p->num);
		for (int j = 0; j < strlen(search); j++) {
			if (search[j] == 'R') {
				p = p->Rlink;
				printf(" %d", p->num);
			}
			else if (search[j] == 'L') {
				p = p->Llink;
				printf(" %d", p->num);
			}
		}
		printf("\n");
	}
	return 0;
}
/*
9
5 3 9
3 8 15
8 0 2
2 0 0
15 0 0
9 7 10
7 12 0
12 0 0
10 0 0
3
RLL
LL
LR
*/
