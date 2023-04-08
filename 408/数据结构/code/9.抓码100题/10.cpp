/*
题目：求两个递增链表A、B的交集，并将结果存放在A链表中
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

/*
分析：其实此题也是合并两个链表的变种
若pa、pb相等摘取(此处也可释放pb空间)
若pa、pb不等，则删除小者并向前移动(因为大者的指针向前动没有意义)
*/
void Differ(LinkList& A, LinkList& B, LinkList& C) {
    Node *pa, *pb, *pc, *q;
    pa = A->next;
    pb = B->next;
    // 用A链表的头指针作为新的头指针
    pc = C = A;
    while (pa && pb) {
        if (pa->data == pb->data) {
            // 摘取下来插到C的后面
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            // 释放B的空间(具体看题目要求)
            q = pb;
            pb = pb->next;
            free(q);
        } else if (pa->data < pb->data) {
            // A的元素小，此处必须删除了
            q = pa;
            pa = pa->next;
            free(q);
        } else {
            // B的元素小，向前移动(可释放空间)
            q = pb;
            pb = pb->next;
            free(q);
        }
    }
    // 如果是pb先遍历完了,即A中还有元素，一定不是交集，必须删除
    while (pa) {
        q = pa;
        pa = pa->next;
        free(q);
    }
    // 如果是A遍历完了，释放B的空间
    while (pb) {
        q = pb;
        pb = pb->next;
        free(q);
    }
    pc->next = NULL;
    free(B);
}

int main() {
}