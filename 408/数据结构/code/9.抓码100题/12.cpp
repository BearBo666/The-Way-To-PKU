/*
题目：删除链表中的最小元素
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

void MinNode(LinkList& A) {
    Node *p, *pre, *min, *minPre;
    minPre = pre = A;
    min = p = A->next;
    while (p != NULL) {
        if (p->data < min->data) {
            min = p;
            minPre = pre;
        }
        p = p->next;
        pre = pre->next;
    }
    // 删除最小值点
    if (min) {
        minPre->next = min->next;
        free(min);
    }
}

int main() {
}