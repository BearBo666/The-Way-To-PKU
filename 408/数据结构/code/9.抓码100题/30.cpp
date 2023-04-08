/*
    题目：自下而上，从右至左的层次遍历
*/
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

typedef struct Node {
    int data;
    struct Node *left, *right;
} * BTree, Node;

void LevelOrder(BTree T) {
    if (T == NULL)
        return;
    queue<Node*> q;
    stack<Node*> s;
    Node* p = T;
    q.push(T);
    while (!q.empty()) {
        p = q.front(), q.pop();
        // visit相等于入栈
        s.push(p);
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    // 出栈即为自下而上
    while (!s.empty()) {
        p = s.top(), s.pop();
    }
}

int main() {
}