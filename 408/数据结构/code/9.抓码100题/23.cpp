/*
题目：查找链表中倒数第k个结点的数据
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

int FindLastK(LinkList& L, int k) {
    int count = 0;
    Node *fast, *slow;
    slow = fast = L->next;
    // 快指针先走k步
    while (fast != NULL) {
        if (count < k) {
            count++;
        } else {
            slow = slow->next;
        }
        fast = fast->next;
    }
    if (count == k) {
        return slow->data;
    }
    return -1;
}

int main() {
}