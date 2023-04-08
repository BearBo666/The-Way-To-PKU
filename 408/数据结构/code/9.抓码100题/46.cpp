/*
    题目：判断是否是BST
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node *left, *right;
} * BTree, Node;

// 法一：递归，中序遍历
Node* pre = NULL;
bool isBST(BTree T) {
    if (T == NULL)
        return true;
    // 判断左子树
    if (!isBST(T->left)) {
        return false;
    }
    if (pre == NULL)
        pre = T;
    if (T->data < pre->data) {
        return false;
    }
    pre = T;
    // 判断右子树
    return isBST(T->right);
}

// 法二：非递归中序遍历
bool isBST(BTree T) {
    Node *stack[100], int top = -1;
    Node *p = T, *pre = NULL;
    while (p || top != -1) {
        // 左子树持续入栈
        if (p) {
            stack[++top] = p;
            p = p->left;
        } else {
            // 此时p为最左结点
            p = stack[top--];
            if (pre && pre->data > p->data) {
                return false;
            }
            pre = p;
            p = p->right;
        }
    }
}

int main() {
}