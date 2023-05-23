#include <stdio.h>
#include <stdlib.h>

typedef struct Que {
    int* Q;
    int f;
    int r;
} Que;

int isFull(Que* Q, int N) {
    if (((Q->r + 1) % N) == Q->f) {
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty(Que* Q, int N) {
    if ((Q->r == Q->f)) {
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(Que* q, int N, int e) {
    if (isFull(q, N) == 1) {
        printf("overflow");
        PrintQue(q, N);
        exit(1);
    }
    q->r = (q->r + 1) % N;
    q->Q[q->r] = e;
}

void dequeue(Que* Q2, int qn) {
    if (isEmpty(Q2, qn) == 1) {
        printf("underflow");
        exit(1);
    }
    Q2->f = (Q2->f + 1) % qn;
    Q2->Q[Q2->f] = 0;
}

void PrintQue(Que* Q2, int qn) {
    int* p;
    p = Q2->Q;
    for (int i = 0; i < qn; i++) {
        printf(" %d", p[i]);
    }
    printf("\n");
}


void initQueue(Que* q, int N) {
    q->Q = (int*)malloc(sizeof(int) * N);
    q->f = 0;
    q->r = 0;
    for (int i = 0; i < N; i++) {
        q->Q[i] = 0;
    }
}

int main() {
    int qn;
    int n;
    char input1;
    int input2;

    scanf("%d", &qn);
    scanf("%d", &n);

    Que* q;
    q = (Que*)malloc(sizeof(Que));
    initQueue(q, qn);

    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c", &input1);
        if (input1 == 'I') {
            scanf("%d", &input2);
            enqueue(q, qn, input2);
        }
        else if (input1 == 'P') {
            PrintQue(q, qn);
        }
        else if (input1 == 'D') {
            dequeue(q, qn);
        }
    }

    free(q->Q);
    free(q);

    return 0;
}
