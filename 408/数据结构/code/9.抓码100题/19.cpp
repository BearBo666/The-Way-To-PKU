/*
题目：删除递增链表中指定范围的结点
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

void DeleteScope(LinkList& L, int min, int max) {
    Node *p = L->next, *pre = L;
    // 找到第一个大于等于min的结点
    while (p != NULL && p->data < min) {
        p = p->next;
        pre = pre->next;
    }
    // p向前移动直到大于max
    while (p && p->data <= max) {
        pre->next = p->next;  // 从链中断开
        free(p);
        p = pre->next;
    }
}

int main() {
}