/*
    链式栈
*/
#include <iostream>

using namespace std;

// 头插法建立就类似于先进的在底部
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

// 初始化
bool InitStack(LinkList& S) {
    S = (LNode*)malloc(sizeof(LNode));
    if (S == NULL) {
        return false;
    }
    S->next = NULL;
    return true;
}
// 判空
bool Empty(LinkList& S) {
    return S == NULL || S->next == NULL;
}
// 入栈
bool Push(LinkList& S, int e) {
    LNode* node = (LNode*)malloc(sizeof(LNode));
    if (node == NULL) {
        return false;
    }
    node->data = e;
    node->next = S->next;
    S->next = node;
    return true;
}
// 出栈
bool Pop(LinkList& S, int& e) {
    if (Empty(S)) {
        return false;
    }
    e = S->next->data;
    S->next = S->next->next;
    return true;
}
// 获得栈顶元素
bool Top(LinkList S, int& e) {
    if (Empty(S)) {
        return false;
    }
    e = S->next->data;
    return true;
}