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
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->id = id;
	root->data = data;
	root->Left = Left;
	root->Right = Right;
	return root;
}

treeNode* findNodeid(treeNode* root,int nodeid) {
		if (root == NULL) { // No write postorder error
		return NULL;
	}
	if (root->id == nodeid) {
		return root;
	}
	treeNode* p;
	p = root->Left;
	treeNode* LeftResult = findNodeid(root->Left, nodeid);
	if (LeftResult != NULL) {
		return LeftResult;
	}
	treeNode* RightResult = findNodeid(root->Right, nodeid);
	if (RightResult != NULL) {
		return RightResult;
	}

}

int sumCapacity(treeNode* Node) {
		if (Node != NULL) {
		int left =sumCapacity(Node->Left);
		int right=sumCapacity(Node->Right);
		int sum = left + right + Node->data;
		return sum;
	}
		else {
			return 0;
		}
		
}

int main() {
	int nodeid;
	scanf("%d", &nodeid);
	if (nodeid >= 1 && nodeid <= 8) {
		treeNode* F8 = makeRootNode(8, 80, NULL, NULL);
		treeNode* F7 = makeRootNode(7, 130, NULL, NULL);
		treeNode* F6 = makeRootNode(6, 120, F7, F8);
		treeNode* F5 = makeRootNode(5, 90, NULL, NULL);
		treeNode* F4 = makeRootNode(4, 70, NULL, NULL);
		treeNode* F3 = makeRootNode(3, 50, NULL, F6);
		treeNode* F2 = makeRootNode(2, 30, F4, F5);
		treeNode* F1 = makeRootNode(1, 20, F2, F3);
		treeNode* startNode = makeRootNode(0, 0, NULL, NULL);
		startNode = findNodeid(F1,nodeid);
		printf("%d",sumCapacity(startNode));
	}
	else {
		printf("-1");
	}

	return 0;
}
