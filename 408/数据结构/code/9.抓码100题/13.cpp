/*
题目：删除链表中的满足条件的结点结点
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

void DeleteSome(LinkList& A, bool (*cb)(int x)) {
    Node *p = A->next, *pre = A;
    while (p) {
        if (cb(p->data)) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

int main() {
}