/*
    题目：二叉树的非递归中序遍历
*/
#include <iostream>
#include <stack>

using namespace std;

typedef struct Node {
    int data;
    struct Node *left, *right;
} * BTree, Node;

void visit(Node* p) {
    cout << p->data << " ";
}

void InOrder(BTree T) {
    stack<Node*> s;
    Node* p = T;
    while (!p || !s.empty()) {
        // 左孩子顺序入栈
        if (p) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top(), s.pop();  // 此时p为最左结点
            visit(p);
            p = p->right;  // 准备遍历右孩子
        }
    }
}

int main() {
}