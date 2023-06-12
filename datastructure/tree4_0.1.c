#include <stdio.h>
#include <stdlib.h> 

#define _crt_secure_no_warnings
#pragma warning(disable:4996)

typedef struct treeNode {
	struct treeNode* Llink;
	int nodeid;
	struct treeNode* Rlink;
}treeNode;

treeNode* createtNode() {
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->Llink = NULL;
	newNode->nodeid = 0;
	newNode->Rlink = NULL;
	return newNode;
}

treeNode* makeRootNode(int x,int y, int z) {
	treeNode* newNode = createtNode();

	if (y != 0) {
		treeNode* newNode2 = createtNode();
		newNode2->nodeid = y;
		newNode->Llink = newNode2;
	}
	else {
		newNode->Llink = NULL;
	}
	if (z != 0) {
		treeNode* newNode3 = createtNode();
		newNode3->nodeid = z;
		newNode->Rlink = newNode3;
	}
	else {
		newNode->Rlink = NULL;
	}
	newNode->nodeid = x;
	return newNode;
}

treeNode* findX(treeNode* rootNode, int x) {
	if (rootNode == NULL) {
		return NULL;
	}
	treeNode* p = rootNode;
	if (p->nodeid == x) {
		return rootNode;
	}
	treeNode* Left = findX(p->Llink, x);
	if (Left != NULL) { //이부분을 ==로 했었음 그럼어떻게될까?
		return Left;
	}
	treeNode* Right = findX(p->Rlink, x);
	if (Right != NULL) { //이부분을 ==로 했었음 그럼어떻게될까?
		return Right;
	}
	return NULL;
}

void insertNode(treeNode* node, int y, int z) {
	if (y == 0) {
		node->Llink = NULL;
	}
	else {
		treeNode* newNode2 = createtNode();
		newNode2->nodeid = y;
		node->Llink = newNode2;
	}
	if (z == 0) {
		node->Rlink = NULL;
	}
	else {
		treeNode* newNode3 = createtNode();
		newNode3->nodeid = z;
		node->Rlink = newNode3;
	}
}

int main() {

	int nodeNumber;
	int x, y, z;
	int i = 0;
	scanf("%d", &nodeNumber);

	for (i = 1; i < nodeNumber+1; i++) {
		scanf("%d %d %d", &x, &y, &z);
		if (x != 0) {
			break;
		}
	}
	treeNode* rootNode = createtNode();
	rootNode = makeRootNode(x,y,z);

	for (int j = 0; j < nodeNumber - 1; j++) {
		getchar();
		scanf("%d %d %d", &x, &y, &z);
		if (x == 0) {
			continue;
		}
		else {
			treeNode* p = createtNode();
			p = findX(rootNode,x);
			insertNode(p, y, z);
		}
	}

	return 0;
}
