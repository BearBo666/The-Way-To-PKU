#include <iostream>

using namespace std;

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode, *BTree;

// 生成一个结点
TreeNode* Node(int data) {
    TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
// 访问
void Visit(TreeNode* p) {
    cout << p->data << " ";
}
// 中序遍历
void InOrder(TreeNode* T) {
    if (T != NULL) {
        // 递归遍历
        InOrder(T->left);
        Visit(T);
        InOrder(T->right);
    }
}

int main() {
    BTree root = Node(1);
    TreeNode* _2 = Node(2);
    TreeNode* _3 = Node(3);
    root->left = _2;
    root->right = _3;
    TreeNode* _4 = Node(4);
    TreeNode* _5 = Node(5);
    _2->left = _4;
    _2->right = _5;
    TreeNode* _6 = Node(6);
    TreeNode* _7 = Node(7);
    _3->left = _6;
    _3->right = _7;

    InOrder(root);
}