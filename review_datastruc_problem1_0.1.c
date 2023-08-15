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
		Node* p = list->header->next;
		if (list->num >= com3) {
			for (int i = 0; i < com3-2 && p->next != list->trailer; i++) {
				p = p->next;
			}
			newNode->prev = p;
			newNode->next = p->next;
			p->next->prev = newNode;
			p->next = newNode;
			list->num++;
		}
		else {
			for (int i = 0; i < com3 && p->next != list->trailer; i++) {
				p = p->next;
			}
			newNode->prev = p;
			newNode->next = p->next;
			p->next->prev = newNode;
			p->next = newNode;
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
