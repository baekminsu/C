#include <stdio.h>
#include <stdlib.h> // malloc

#define _crt_secure_no_warnings
#pragma warning(disable:4996)

typedef struct treeNode {
	struct treeNode* Left;
	int id;
	int data;
	struct treeNode* Right;
}treeNode;

treeNode *makeRootNode(int id, int data, struct treeNode* Left, treeNode* Right) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->Left = Left;
	root->Right = Right;
	root->id = id;
	root->data = data;
	return root;
}

void preOrder(treeNode* startNode) {

}

void inOrder(treeNode* startNode) {

}

void postOrder(treeNode* startNode) {

}

treeNode* findStartNode(treeNode* rootNode,int nodeid) {

	treeNode* p;
	p = rootNode;

	if (rootNode != NULL) {

		if (p->id == nodeid) {
			return p;
		}
		p = findStartNode(p->Left, nodeid);
		p = findStartNode(p->Right, nodeid);
	}


}


int main() {
	int roundMethod;
	int nodeid;

	treeNode* F8 = makeRootNode(8, 80, NULL, NULL);
	treeNode* F7 = makeRootNode(7, 130, NULL, NULL);
	treeNode* F6 = makeRootNode(6, 120, F7, F8);
	treeNode* F5 = makeRootNode(5, 90, NULL, NULL);
	treeNode* F4 = makeRootNode(4, 70, NULL, NULL);
	treeNode* F3 = makeRootNode(3, 50, NULL, F6);
	treeNode* F2 = makeRootNode(2, 30, F4, F5);
	treeNode* F1 = makeRootNode(1, 20, F2, F3);
	treeNode* startNode = makeRootNode(0, 0, NULL, NULL);


	scanf("%d %d", &roundMethod, &nodeid);

	if (nodeid < 9 && nodeid > 0) {

		startNode = findStartNode(F1, nodeid);
		printf("%d", *startNode);
		if (roundMethod == 1) {
			preOrder(startNode);
		}
		else if (roundMethod == 2) {
			inOrder(startNode);
		}
		else if (roundMethod == 3) {
			postOrder(startNode);
		}
	}
	else {
		printf("-1");
	}

	return 0;
}
