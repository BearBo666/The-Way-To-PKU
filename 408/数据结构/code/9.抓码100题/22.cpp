/*
题目：判断循环链表(至少有两个结点)中的每个结点是否小于其后续两个结点之和
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

/*
分析；循环链表中没有空的链域，
一定要考虑清楚没有结点和只有一个/两个结点的情况
此题规定了至少两个结点，所以不需要考虑
*/
bool Judge(LinkList& L) {
    Node* p = L->next;
    while (p->next->next != L) {
        if (p->data < p->next->data + p->next->next->data)
            return false;
    }
    return true;
}

int main() {
}