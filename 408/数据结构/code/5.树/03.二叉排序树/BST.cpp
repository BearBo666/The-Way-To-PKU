#include <iostream>

using namespace std;

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode, *BiTree;

// 构造函数
TreeNode* Node(int e) {
    TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
    if (p == NULL) {
        return NULL;
    }
    p->data = e;
    p->left = p->right = NULL;
    return p;
}
// 在某棵子树中插入结点
bool Insert(BiTree root, int e) {
    // 等于的情况划入左子树
    if (e <= root->data) {
        // 左子树为空
        if (root->left == NULL) {
            TreeNode* p = Node(e);
            if (p == NULL) {
                return false;
            }
            root->left = p;
            return true;
        }
        return Insert(root->left, e);
    }
    // 大于划到右子树
    // 右子树为空
    if (root->right == NULL) {
        TreeNode* p = Node(e);
        if (p == NULL) {
            return false;
        }
        root->right = p;
        return true;
    }
    return Insert(root->right, e);
}
// 中序遍历
void InOrder(TreeNode* T) {
    if (T != NULL) {
        // 递归遍历
        InOrder(T->left);
        cout << T->data << " ";
        InOrder(T->right);
    }
}

int main() {
    BiTree root = Node(5);
    for (size_t i = 0; i < 10; i++) {
        Insert(root, i + 1);
    }
    InOrder(root);
}