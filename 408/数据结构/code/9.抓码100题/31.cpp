/*
    题目：求二叉树高度，递归模型，根 + func(左/右)
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node *left, *right;
} * BTree, Node;

// 递归遍历，空间O(h)，或者层次遍历
int Height(BTree T) {
    if (T == NULL) {
        return 0;
    }
    int lh = Height(T->left);
    int rh = Height(T->right);
    int max = lh > rh ? lh : rh;
    return max + 1;
}

int main() {
}