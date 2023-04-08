/*
题目：链表的原地逆置
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

void Reverse(LinkList& L) {
    Node *p, *next;  // p为工作指针，next为p的后继，以防断链
    p = L->next;
    L->next = NULL;
    // 依次摘下结点进行头插
    while (p != NULL) {
        next = p->next;     // 暂存p的后继
        p->next = L->next;  // 将p插入
        L->next = p;
    }
}

int main() {
}