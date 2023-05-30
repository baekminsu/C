#include <stdio.h>
#include <stdlib.h> // malloc

#define _crt_secure_no_warnings
#pragma warning(disable:4996)

typedef struct treeNode {
	struct treeNode* Left;
	int data;
	struct treeNode* Right;
}treeNode;

treeNode *makeRootNode(int data, treeNode* Left, treeNode* Right) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->Left = Left;
	root->Right = Right;
	return root;
}

void printTree(treeNode* temp) {



}

int main() {

	treeNode* F8 = makeRootNode(80, NULL, NULL);
	treeNode* F7 = makeRootNode(130, NULL, NULL);
	treeNode* F6 = makeRootNode(120, F7, F8);
	treeNode* F5 = makeRootNode(90, NULL, NULL);
	treeNode* F4 = makeRootNode(70, NULL, NULL);
	treeNode* F3 = makeRootNode(50, NULL, F6);
	treeNode* F2 = makeRootNode(30, F4, F5);
	treeNode* F1 = makeRootNode(20, F2, F3);

	int NodeNum;
	scanf("%d", &NodeNum);

	if (NodeNum == 1) {

	}
	else if (NodeNum == 2) {

	}
	else if (NodeNum == 3) {

	}
	else if (NodeNum == 4) {

	}
	else if (NodeNum == 5) {

	}
	else if (NodeNum == 6) {

	}
	else if (NodeNum == 7) {

	}
	else if (NodeNum == 8) {

	}
	else {
		printf("-1");
	}

	return 0;
}
