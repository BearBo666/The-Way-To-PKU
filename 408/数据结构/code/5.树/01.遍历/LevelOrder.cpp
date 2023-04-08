#include <iostream>
#include <queue>

using namespace std;

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode, *BiTree;

// 层序遍历
void LevelOrder(BiTree T) {
    if (T == NULL) {
        return;
    }
    queue<TreeNode*> q;
    q.push(T);
    while (!q.empty()) {
        TreeNode* elem = q.front();
        q.pop();
        cout << elem->data << " ";
        if (elem->left != NULL) {
            q.push(elem->left);
        }
        if (elem->right != NULL) {
            q.push(elem->right);
        }
    }
    cout << endl;
}

int main() {
}