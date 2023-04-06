#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


typedef struct NODE {
	struct NODE* llink; 
	char data;
	struct NODE* rlink; 
}Node;

typedef struct LIST { //리스트를 나타내는 구조체
	int size;
	Node* header;
	Node* trailer;
}List;

List* createList() {
	List* list = (List*)malloc(sizeof(List));
	list->header = (Node*)malloc(sizeof(Node));
	list->trailer = (Node*)malloc(sizeof(Node));
	list->header->rlink = list->trailer;
	list->trailer->llink = list->header;
	list->size = 0;
	return list;
}

void add(List* list, int r, char e) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = e;
	new_node->llink = NULL;
	new_node->rlink = NULL;

	if (r < 0 || r > list->size) {
		printf("invalid position\n");
		return;
	}

	Node* curr = list->header;

	for (int i = 0; i < r; i++) {
		curr = curr->rlink;
	}

	new_node->llink = curr;
	new_node->rlink = curr->rlink;
	curr->rlink->llink = new_node;
	curr->rlink = new_node;

	list->size++;


}

void delete(List* list, int r) {
	if (r < 0 || r >= list->size ) {
		printf("invalid position\n");
		return;
	}
	
	Node* curr = list->header->rlink;
	for (int i = 0; i < r; i++) {
		curr = curr->rlink;
	}

	curr->llink->rlink = curr->rlink;
	curr->rlink->llink = curr->llink;
	free(curr);

	list->size--;
}

void get(List* list, int r) {
	if (r < 0 || r >= list->size) {
		printf("invalid position\n");
		return;
	}

	Node* curr = list ->header->rlink;
	for (int i = 0; i < r; i++) {
		curr = curr->rlink;
	}
	printf("%c\n", curr->data);
}

void print(List* list) {
	Node* curr = list->header->rlink;
	while (curr != list->trailer) {
		printf("%c", curr->data);
		curr = curr->rlink;
	}
	printf("\n");
}

int main() {

	int N;
	char order;
	int num2;
	char input;
	scanf("%d", &N);
	getchar();
	
	List* list = createList();

	for (int i = 0; i < N; i++) {
		scanf("%c", &order);
		fflush(stdin);
		if (order == 'A') {
			scanf("%d %c", &num2, &input);
			getchar();
			add(list, num2-1, input);
		}
		else if (order == 'D') {
			scanf("%d", &num2);
			getchar();
			delete(list, num2-1);
		}
		else if (order == 'G') {
			scanf("%d", &num2);
			getchar();
			get(list, num2-1);
		}
		else { // order 가 P 일때
			print(list);
			getchar();
		}
	}

	return 0;
}
