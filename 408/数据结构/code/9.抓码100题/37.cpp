/*
    题目：找到所有值满足条件的结点的高度
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node *left, *right;
} * BTree, Node;

int index = 0;
int Heights[100];

bool Check(Node* p) {
    return p->data == 10;
}

void FindX(BTree T, int h) {
    if (!T)
        return;
    if (Check(T)) {
        Heights[index++] = h;
    }
    FindX(T->left, h + 1);
    FindX(T->right, h + 1);
}

int main() {
}