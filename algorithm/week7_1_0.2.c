#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _crt_secure_no_warnings
#pragma warning(disable:4996)
// https://code731.tistory.com/32

typedef struct Node {
    struct Node* lChild;
    struct Node* parent;
    int key;
    struct Node* rChild;
}Node;

Node* makeNode() {
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->lChild = NULL;
    newNode->rChild = NULL;
    newNode->parent = NULL;
    return newNode;
}

Node* treeSearch(Node* p,int k) {
    if (p->key == k) {
        return p;
    }
    else if (p->key > k){
        return treeSearch(p->lChild, k);
    }
    else {
        return treeSearch(p->rChild, k);
    }
}

void expandNode(Node* p) {
    Node* lNode = makeNode();
    Node* rNode = makeNode();
    lNode->parent = p;
    rNode->parent = p;
}

void insertItem(int k, Node* root) {
    if (root->parent == NULL && root->lChild == NULL && root->rChild == NULL) {
        root->key = k;
    }
    else {
        Node* p=treeSearch(root, k);
        p->key = k;
        expandNode(p);
    }
    return;
}

void printTree(Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        printTree(root->lChild);
        printTree(root->rChild);
    }
}

int main() {
    char command;
    int element;
    command;
    Node* root;
    root = makeNode();
    while (1) {
        scanf("%c", &command);
        if (command == 'q') {
            break;
        }
        if (command == 'i') {
            scanf("%d", &element);
            insertItem(element, root);
        }
        else if (command == 'p') {
            printTree(root);
            printf("\n");
        }
        getchar();
    }
    return 0;
}
