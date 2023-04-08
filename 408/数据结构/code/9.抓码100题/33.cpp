/*
    题目：计算二叉树叶子结点个数
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node *left, *right;
} * BTree, Node;

int LeavesNum(BTree T) {
    if (T == NULL)
        return 0;
    if (!T->left && !T->right)
        return 1;
    return LeavesNum(T->left) + LeavesNum(T->right);
}

int main() {
}