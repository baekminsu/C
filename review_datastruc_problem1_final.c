#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _crt_secure_no_warnings
#pragma warning(disable:4996)  // swea 에서 이거쓰면 오류남 c++ 지원하고 c언어 선택란없음

typedef struct Node {
	char elem;
	struct Node* prev;
	struct Node* next;
}Node;

typedef struct List {
	Node* header;
	Node* trailer;
	int num;
}List;

void Listinit(List *list) {
	list->header = (Node*)malloc(sizeof(Node));
	list->trailer = (Node*)malloc(sizeof(Node));
	list->header->next = NULL;
	list->header->prev = NULL;
	list->trailer->next = NULL;
	list->trailer->prev = NULL;
	list->header->next = list->trailer;
	list->trailer->prev = list->header;
}

void add(List* list, int com3, char com4) {
	if (list->num+1 < com3) {
		printf("invalid position\n");
		return;
	}
	if (list->header->next == list->trailer) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->elem = com4;
		newNode->prev = list->header;
		newNode->next = list->trailer;
		list->header->next = newNode;
		list->trailer->prev = newNode;
		list->num++;
	}
	else {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->elem = com4;
		newNode->prev = NULL;
		newNode->next = NULL;
		if (com3 > list->num) { //꼬리에붙일때
			Node* p = list->trailer;
			p->prev->next = newNode;
			newNode->next = p;
			newNode->prev = p->prev;
			p->prev = newNode;
			list->num++;
		}
		else {
			Node* p = list->header;
			for (int i = 0; i < com3; i++) {
				p = p->next;
			}
			newNode->next = p;
			newNode->prev = p->prev;
			p->prev->next = newNode;
			p->prev = newNode;
			list->num++;
		}
	}
}

void print(List* list) {
	Node* p = list->header->next;
	while (p != list->trailer) {
		printf("%c", p->elem);
		p = p->next;
	}
	printf("\n");
}

void delete(List* list,int com3) {
	if (list->num < com3) {
		printf("invalid position\n");
		return;
	}
	Node* p = list->header->next;
	for (int i = 0; i < com3-1; i++) {
		p = p->next;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
	list->num--;
}

void get_entry(List* list, int com3) {
	if (list->num < com3) {
		printf("invalid position\n");
		return;
	}
	Node* p = list->header->next;
	for (int i = 0; i < com3 - 1; i++) {
		p = p->next;
	}
	printf("%c\n", p->elem);
}

int main() {

	int com;
	int com3;
	char com2,com4;
	scanf("%d", &com);
	getchar();

	List list;
	Listinit(&list);
	list.num = 0;

	for (int i = 0; i < com; i++) {
		scanf(" %c", &com2);
		getchar();
		if (com2 == 'A') {
			scanf("%d", &com3);
			getchar();
			scanf("%c", &com4);
			add(&list, com3, com4);
		}
		else if (com2 == 'P') {
			print(&list);
		}
		else if (com2 == 'D') {
			scanf("%d", &com3);
			delete(&list, com3);
		}
		else if (com2 == 'G') {
			scanf("%d", &com3);
			get_entry(&list, com3);
		}
	}
	return 0;
}
/*
5
A 1 S
A 2 t
A 3 r	
A 3 a
P
*/
/*
9
A 1 D
A 2 a
A 3 y
D 1
P
G 3
A 1 S
P
G 3
*/
/*
5
A 1 D
A 2 y
D 1
A 1 S
P
*/
