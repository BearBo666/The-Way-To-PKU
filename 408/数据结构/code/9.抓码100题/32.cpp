/*
    题目：求二叉树宽度
*/
#include <iostream>
#include <queue>

using namespace std;

typedef struct Node {
    int data;
    struct Node *left, *right;
} * BTree, Node;

int Width(BTree T) {
    if (!T)
        return 0;
    queue<Node*> q;
    Node* p = T;
    int count = 1, nextLevel = 0, max = 1;  // 记录同/下层次结点个数

    q.push(p);
    while (!q.empty()) {
        p = q.front(), q.pop(), count--;  // 出队，同层次结点数减一
        if (p->left) {
            q.push(p->left);
            nextLevel++;
        }
        if (p->right) {
            q.push(p->right);
            nextLevel++;
        }
        // 等于0时刚好是本层次最后一个结点
        if (count == 0) {
            max = nextLevel > max ? nextLevel : max;  // 此时nextLevel即为下一层的宽度
            count = nextLevel;
            nextLevel = 0;
        }
    }
    return max;
}

int main() {
}