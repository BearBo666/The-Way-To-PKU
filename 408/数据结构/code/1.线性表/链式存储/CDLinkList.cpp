/*
    循环双链表
*/
#include <iostream>

using namespace std;

typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

// 初始化双向链表
DLinkList InitDLinkList() {
    DNode* head = (DNode*)malloc(sizeof(DNode));
    if (head == NULL) {
        return NULL;
    }
    // 循环的双链表头节点指向自己
    // 双手抱住空虚的自己
    head->prior = head;
    head->next = head;

    return head;
}
// 判空
bool Empty(DLinkList L) {
    // 是否抱住自己
    return L->next == L;
}
// 判断是否是表尾
bool isTail(DLinkList L, DNode* p) {
    return p->next == L;
}
// 指定节点后插
bool InsertNextDNode(DNode* p, int e) {
    if (p == NULL) {
        return false;
    }
    DNode* node = (DNode*)malloc(sizeof(DNode));
    if (node == NULL) {
        return false;
    }

    node->data = e;
    node->prior = p;
    node->next = p->next;
    // p只要不为空一定有后继
    p->next->prior = node;
    p->next = node;

    return true;
}
// 删除p节点的后继节点
bool DeleteNextDNode(DLinkList L, DNode* p) {
    if (p == NULL || isTail(L, p)) {
        return false;
    }
    DNode* q = p->next;

    p->next = q->next;
    q->next->prior = p;
    free(q);

    return true;
}
// 删除指定节点
bool DeleteDNode(DNode* p) {
    if (p == NULL) {
        return false;
    }
    // 成全前后两个节点
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);

    return true;
}
// 打印
void Print(DLinkList L) {
    DNode* p = L->next;
    cout << "Print: ";
    // 此处跟其它链表不一样
    while (!isTail(L, p)) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    DLinkList L = InitDLinkList();
    for (size_t i = 0; i < 10; i++) {
        InsertNextDNode(L, 10 - i);
    }
    Print(L);

    DNode* p = L->next->next;
    cout << "Delete the 3th node: " << DeleteNextDNode(L, p) << endl;
    Print(L);

    cout << "Delete the 2th node: " << DeleteDNode(p) << endl;
    Print(L);

    return 0;
}