/*
题目：两个递增链表合并为一个新的链表，不生成新的空间，不包含重复元素
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

void Merge(LinkList& A, LinkList& B, LinkList& C) {
    Node *pa, *pb, *pc, *q;
    pa = A->next;
    pb = B->next;
    // A的头节点作为C的头节点
    C = pc = A;
    while (pa && pb) {
        // 取较小者
        if (pa->data < pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else if (pa->data > pb->data) {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        } else {
            // 二者相等取一个
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            // 释放掉另一个的空间
            q = pb;
            pb = pb->next;
            free(q);
        }
    }
    // 剩余的挂在pc后面
    pc->next = pa ? pa : pb;
    // 释放B的头节点
    free(B);
}

int main() {
}