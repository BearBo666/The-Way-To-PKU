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
// 在指定结点后插入
bool Insert(TreeNode* p, int e, bool isLeft) {
    TreeNode* node = Node(e);
    if (node == NULL) {
        return false;
    }
    if (isLeft) {
        if (p->left != NULL) {
            return false;
        }
        p->left = node;
        return true;
    }
    if (p->right != NULL) {
        return false;
    }
    p->right = node;
    return true;
}

int main() {
}