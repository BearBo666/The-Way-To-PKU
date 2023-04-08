/*
题目：将链表A中的结点分成正负两部分，存在链表B、C中，要求利用A的空间
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

void DisCreat(LinkList& A) {
    Node *B, *C, *p, *rb, *rc, *r;
    B = (Node*)malloc(sizeof(Node));
    C = (Node*)malloc(sizeof(Node));
    B->next = C->next = NULL;
    rb = B;
    rc = C;

    p = A->next;
    while (p) {
        r = p->next;  // 暂存p的后继，以防断链
        if (p->data < 0) {
            p->next = rb->next;
            rb->next = p;
            rb = rb->next;
            rb->next = NULL;
        } else if (p->data > 0) {
            p->next = rc->next;
            rc->next = p;
            rc = rc->next;
            rc->next = NULL;
        } else {
            free(p);  // 等于0，释放空间
        }
        p = r;
    }
}

int main() {
}