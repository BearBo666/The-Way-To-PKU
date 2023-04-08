/*
题目：链表判环
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

bool judgeCycle(LinkList& L) {
    Node *fast, *slow;
    fast = slow = L->next;
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
        // 多前进一步
        if (fast->next != NULL)
            fast = fast->next;
        if (fast = slow)
            return true;
    }
    return false;
}

int main() {
}