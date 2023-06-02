#include <stdio.h>
#include <stdlib.h> 

#define _crt_secure_no_warnings
#pragma warning(disable:4996)

typedef struct treeNode {
	int id;
	int data;
	struct treeNode* Left;
	struct treeNode* Right;
}treeNode;

treeNode* makeRootNode(int id, int data, treeNode* Left,treeNode * Right){
	treeNode* root = (treeNode*)malloc(treeNode);
	root->id = id;
	root->data = data;
	root->Left = Left;
	root->Right = Right;
	return root;
}

int main() {
	int nodeid;
	scanf("%d", &nodeid);

	treeNode* F8 = makeRootNode(8, 80, NULL, NULL);
	treeNode* F7 = makeRootNode(7, 130, NULL, NULL);
	treeNode* F6 = makeRootNode(6, 120, F7, F8);
	treeNode* F5 = makeRootNode(5, 90, NULL, NULL);
	treeNode* F4 = makeRootNode(4, 70, NULL, NULL);
	treeNode* F3 = makeRootNode(3, 50, NULL, F6);
	treeNode* F2 = makeRootNode(2, 30, F4, F5);
	treeNode* F1 = makeRootNode(1, 20, F2, F3);

	return 0;
}
