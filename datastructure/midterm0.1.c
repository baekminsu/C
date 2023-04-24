#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)




/*입력값  한줄로입력하고 홀수 짝수 두줄로내보내기
1 2 3 4 5 6 7 8 9 10  

10 9 8 7 6 5 4 3 2 1

293 10 13 155 55 87 46 42 23 33
*/


int num = 0;

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* CreateNode() {
	Node* NewNode;

	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->next = NULL;

	return NewNode;
}

void addNode(Node* k,int input,int num) {
	Node* new;
	new = CreateNode();

	new->data = input;

	for (int i = 0; i < num; i++) {
		k = k->next;
	}

	k->next = new;


}

void printNode1(Node* k, int num) {
	k = k->next;
	for(int i = 0 ; i < num ; i ++) {
		if (k->data % 2 == 1) {
			printf(" %d", k->data);
			k = k->next;
		}
	}
}

void printNode2(Node* k, int num) {
	k = k->next;
	for (int i = 0; i < num; i++) {
		if (k->data % 2 == 0) {
			printf(" %d", k->data);
			k = k->next;
		}
	}
}





int main() {

	int i;
	int input;

	Node* A;   //홀수 리스트
	Node* B;  // 짝수 리스트
	Node* C; // 처음 리스트

	A = CreateNode();
	B = CreateNode();
	C = CreateNode();


	for (i = 0; i < 10; i++) {
		scanf("%d", &input);
		addNode(C,input,num);
		num++;
	}

	printNode1(C,num);
	printf("\n");
	printNode2(C, num);


	return 0;
}
