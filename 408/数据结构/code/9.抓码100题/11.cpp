/*
题目：删除两个链表中的差集，即在A中删除B中有的元素
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

/*
分析：其实此题也是合并两个链表的变种
两个指针，较小者前移，可以得到一个递增的序列
每次对比的两个结点总是在总的序列中邻近的结点
故可以对比到A、B中相同的结点
*/
void SubSet(LinkList& A, LinkList& B) {
    Node *pa, *pb, *pre;
    pre = A;
    pa = A->next;
    pb = B->next;
    while (pa && pb) {
        // 相同元素，执行删除
        if (pa->data == pb->data) {
            pre->next = pa->next;  // 从链中断开
            free(pa);              // 释放空间
            pa = pre->next;
        } else if (pa->data < pb->data) {
            pre = pa;
            pa = pa->next;
        } else {
            pb = pb->next;
        }
    }
}

int main() {
}