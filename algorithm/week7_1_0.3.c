#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _crt_secure_no_warnings
#pragma warning(disable:4996)

typedef struct Node {
    struct Node* lChild;
    struct Node* parent;
    int key;
    struct Node* rChild;
} Node;

int isExternal(Node* w) {
    if (w->lChild == NULL && w->rChild == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int isInternal(Node* w) {
    if (w->lChild != NULL || w->rChild != NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

Node* makeNode() {
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->lChild = NULL;
    newNode->rChild = NULL;
    newNode->parent = NULL;
    return newNode;
}

Node* treeSearch(Node* p, int k) {
    if (isExternal(p)) {
        return p;
    }
    if (k == p->key) {
        return p;
    }
    else if (k < p->key) {
        return treeSearch(p->lChild, k);
    }
    else {
        return treeSearch(p->rChild, k);
    }
}

void expandNode(Node* p) {
    Node* lNode = makeNode();
    Node* rNode = makeNode();
    p->lChild = lNode;
    p->rChild = rNode;
    lNode->parent = p;
    rNode->parent = p;
}

void insertItem(int k, Node* root) {
    Node* w = treeSearch(root, k);
    if (isInternal(w)) {
        return;
    }
    else {
        w->key = k;
        expandNode(w);
        return;
    }
}

void printTree(Node* root) {
    if (isExternal(root)) {
        return;
    }
    else {
        printf(" %d", root->key);
        printTree(root->lChild);
        printTree(root->rChild);
    }
}

Node* inOrderSucc(Node* w) {
    Node* y = w->rChild;
    if (isExternal(y)) {
        return y;
    }
    while (isInternal(y->lChild)) {
        y = y->lChild;
    }
    return y;
}

Node* sibling(Node* root, Node* z) {
    if (z == root) {
        return NULL;
    }
    if (z == z->parent->lChild) {
        return z->parent->rChild;
    }
    else {
        return z->parent->lChild;
    }
}

void reduceExternal(Node** root, Node* z) {
    Node* w = z->parent;
    Node* zs, * g;
    zs = sibling(*root, z);

    if (w == *root) {
        *root = zs;
        zs->parent = NULL;
    }
    else {
        g = w->parent;
        zs->parent = g;
        if (w == g->lChild) {
            g->lChild = zs;
        }
        else {
            g->rChild = zs;
        }
    }
    free(z);
    free(w);
}

void removeElement(Node** root, int k) {
    Node* w = treeSearch(*root, k);

    if (isExternal(w) || w->key != k) {
        printf("X\n");
        return;
    }

    Node* z = w->lChild;
    if (!isInternal(z)) {
        z = w->rChild;
    }
    if (isExternal(z)) {
        reduceExternal(root, z);
    }
    else {
        Node* y = inOrderSucc(w);
        z = y->lChild;
        w->key = y->key;
        reduceExternal(root, z);
    }
    printf("%d\n", k);
}

int main() {
    char command;
    int element;
    Node* root;
    root = makeNode();
    while (1) {
        scanf(" %c", &command); 
        if (command == 'q') {
            break;
        }
        else if (command == 'i') {
            scanf(" %d", &element); 
            insertItem(element, root);
        }
        else if (command == 'p') {
            printTree(root);
            printf("\n");
        }
        else if (command == 's') {
            scanf(" %d", &element);
            Node* q2 = treeSearch(root, element);
            if (q2->key == element) {
                printf("%d\n", q2->key);
            }
            else {
                printf("X\n");
            }
        }
        else if (command == 'd') {
            scanf(" %d", &element);
            removeElement(&root, element);
        }
    }
    return 0;
}
