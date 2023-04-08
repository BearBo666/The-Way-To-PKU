/*
题目：将C中的链表奇偶分开，奇数顺序放在A中，偶数逆序放在B中
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

// 分析，依次摘出C中结点，A采用尾插，B采用头插
void Discreat(LinkList& hc) {
    Node *A, *B, *p, *r, *ra;
    A = (Node*)malloc(sizeof(Node));
    B = (Node*)malloc(sizeof(Node));
    A->next = B->next = NULL;

    ra = A;        // ra指向A的尾结点
    p = hc->next;  // 工作指针

    int i = 1;
    while (p != NULL) {
        r = p->next;  // 暂存p的后续，防止断链
        // 奇数，尾插法插入A
        if (i % 2 == 1) {
            ra->next = p;
            ra = ra->next;
            ra->next = NULL;
        } else {
            // 偶数，头插法插入B
            p->next = B->next;
            B->next = p;
        }
        p = r;
    }
}

int main() {
}