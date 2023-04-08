/*
    双链表
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
    // 非循环的双链表头节点指向空
    head->prior = NULL;
    head->next = NULL;

    return head;
}
// 判空
bool Empty(DLinkList L) {
    return L->next == NULL;
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
    // 如果p有后继,其后继指向新节点
    if (p->next != NULL) {
        p->next->prior = node;
    }
    p->next = node;

    return true;
}
// 删除p节点的后继节点
bool DeleteNextDNode(DNode* p) {
    if (p == NULL) {
        return false;
    }
    DNode* q = p->next;
    if (q == NULL) {
        return false;
    }
    p->next = q->next;
    if (q->next != NULL) {
        q->next->prior = p;
    }
    free(q);

    return true;
}
// 删除指定节点
bool DeleteDNode(DNode* p) {
    if (p == NULL) {
        return false;
    }
    if (p->prior != NULL) {
        p->prior->next = p->next;
    }
    if (p->next != NULL) {
        p->next = p->prior;
    }
    free(p);

    return true;
}
// 销毁双向链表
bool DestoryList(DLinkList& L) {
    while (L->next != NULL) {
        if (!DeleteNextDNode(L))
            return false;
    }
    free(L);
    L = NULL;

    return true;
}
// 打印
void Print(DLinkList L) {
    DNode* p = L->next;
    cout << "Print: ";
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
// 获得长度
int Length(DLinkList L) {
    int cnt = 0;
    DNode* p = L;
    while (p->next != NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

int main() {
    DLinkList L = InitDLinkList();
    for (size_t i = 0; i < 10; i++) {
        InsertNextDNode(L, 10 - i);
    }
    Print(L);

    DNode* p = L->next->next;
    cout << "Delete the 3th node: " << DeleteNextDNode(p) << endl;
    Print(L);

    cout << "Delete the 2th node: " << DeleteDNode(p) << endl;
    Print(L);

    return 0;
}