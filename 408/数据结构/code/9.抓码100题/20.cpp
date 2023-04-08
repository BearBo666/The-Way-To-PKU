/*
题目：对递增链表元素去重
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

void DeleteSame(LinkList& L) {
    if (L->next == NULL)
        return;
    Node *p = L->next, *q;
    while (p->next) {
        q = p->next;               // 指向p的后继
        if (q->data == p->data) {  // 后继元素相同
            p->next = q->next;     // 从链中断开
            free(q);               // 释放空间
        } else {
            p = p->next;
        }
    }
}

int main() {
}