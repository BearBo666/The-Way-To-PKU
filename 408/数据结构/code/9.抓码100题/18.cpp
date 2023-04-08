/*
题目：找到链表中的最大元素
*/
#include <limits.h>
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

int Max(LinkList& L) {
    int max = INT_MIN;
    Node* p = L->next;
    while (p != NULL) {
        if (p->data > max) {
            max = p->data;
        }
    }
    return max;
}

int main() {
}