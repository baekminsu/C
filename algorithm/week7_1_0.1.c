#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _crt_secure_no_warnings
#pragma warning(disable:4996)
// https://code731.tistory.com/32

Node* makeNode() {
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->lChild = NULL;
    newNode->rChild = NULL;
    newNode->parent = NULL;
    return newNode;
}

typedef struct Node {
    struct Node* lChild;
    struct Node* parent;
    int key;
    struct Node* rChild;
}Node;

Node* keySearch(Node* p,int k) {
    Node* q;
    if (p->key == k) {
        return;
    }
    else if (p->key > k){
        return keySearch(p->lChild, k);
    }
    else {
        return keySearch(p->rChild, k);
    }
}

void insertItem(int k, Node* root) {
    if (root->parent == NULL && root->lChild == NULL && root->rChild == NULL) {
        root->key = k;
    }
    else {
        Node* p=keySearch(root, k);
        p->key = k;
    }
}

int main() {
    char command;
    int element;
    command = '0';
    Node* root;

    while (command != 'q') {
        getchar();
        scanf("%c", &command);
        if (command == 'i') {
            scanf("%d", &element);
            root = makeNode();
            insertItem(element, root);
        }
    }
    return 0;
}
