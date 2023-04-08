/*
    题目：判断是否是AVL树
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node *left, *right;
} * BTree, Node;

void judgeAVL(BTree T, int& balance, int& h) {
    if (!T) {
        balance = 1;
        h = 0;
    } else if (!T->left && !T->right) {
        balance = h = 1;
    }else{
        int bl,br,lh,rh;
        judgeAVL(T->left,br)
    }
}

int main() {
}