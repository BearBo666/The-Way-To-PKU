/*
    题目：找到二叉树中最小值
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node *left, *right;
} * BTree, Node;

// 传递引用，省时省力
int FindMin(BTree T, int& min) {
    if (T && T->data < min)
        min = T->data;
    FindMin(T->left, min);
    FindMin(T->right, min);
}

int main() {
}