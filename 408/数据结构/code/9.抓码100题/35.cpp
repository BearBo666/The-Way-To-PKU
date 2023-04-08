/*
    题目：求所有结点和
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node *left, *right;
} * BTree, Node;

int Sum(BTree T) {
    // 一定先写递归出口
    if (!T)
        return 0;
    return Sum(T->left) + Sum(T->right) + T->data;
}

int main() {
}