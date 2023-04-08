/*
    题目：找到满足条件的的结点的双亲 递归模型：参数的传递 func(根,前置结点/高度)
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node *left, *right;
} * BTree, Node;

bool Check(Node* p) {
    return p->data > 5;
}

// 递归版
Node* findParent(BTree T) {
    static Node* pre = T;  // 静态变量
    if (Check(T)) {
        return pre;
    }
    pre = T;
    findParent(T->left);
    findParent(T->right);
}

int main() {
}