/*
题目：合并两个递增链表，不生成空间，可以包含重复元素
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

/*
分析：两个指针，小者向前移动，可以得到一个递增有序的序列
同时此题也可以变种到其它类型的题目
*/
void Merge(LinkList& A, LinkList& B, LinkList& C) {
    Node *pa, *pb, *pc;
    pa = A->next;
    pb = B->next;
    // A的头节点作为新链表的头节点
    C = pc = A;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    // 释放B的头节点
    free(B);
}

int main() {
}