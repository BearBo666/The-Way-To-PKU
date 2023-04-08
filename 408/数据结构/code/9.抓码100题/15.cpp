/*
题目：将A中的偶数号结点摘出去生成一个新链表
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

LinkList DisCreat(LinkList& A) {
    Node *B, *rb, *p， *q;
    // 创建链表B的头节点
    B = (Node*)malloc(sizeof(Node));
    B->next = NULL;
    rb = B;

    p = A->next;  // p始终为奇数号结点
    while (p->next) {
        // 摘下奇数结点的后一个结点插入到链表B的尾部
        q = p->next;
        p->next = p->next->next;  // 把链表接上
        // 摘出去的结点后面置为空
        q->next = NULL;
        // 尾插插入
        rb->next = q;
        rb = rb->next;
        // 跳转到下一个奇数结点
        p = p->next->next;
    }
    return B;
}

int main() {
}