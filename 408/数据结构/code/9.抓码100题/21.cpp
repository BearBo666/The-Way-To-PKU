/*
题目：将链表拆成三个循环链表，利用原链表空间
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

void DisCreat(LinkList& L) {
    Node *p = L->next, *r;
    LinkList A, B, C;
    A = (Node*)malloc(sizeof(Node));
    B = (Node*)malloc(sizeof(Node));
    C = (Node*)malloc(sizeof(Node));
    A->next = A;
    B->next = B;
    C->next = C;
    while (p != NULL) {
        r = p->next;  // 暂存p的后续，防止断链
        if (p->data < 0) {
            // 头插法插入A
            p->next = A->next;
            A->next = p;
        } else if (p->data == 0) {
            // 头插法插入B
            p->next = B->next;
            B->next = p;
        } else {
            // 头插法插入C
            p->next = C->next;
            C->next = p;
        }
        p = r;
    }
}

int main() {
}