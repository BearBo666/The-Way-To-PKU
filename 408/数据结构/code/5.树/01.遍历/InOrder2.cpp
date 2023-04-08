/*
非递归实现二叉树中序遍历
*/
#include <iostream>
#include <stack>

using namespace std;

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode, *BiTree;

// 访问
void visit(TreeNode* ele) {
    cout << ele->data << " ";
}

// 实现
void PreOrder(BiTree T) {
    stack<TreeNode*> s;
    TreeNode* p = T;
    // p为空栈为空推出循环
    while (!(p == NULL && s.empty())) {
        // 循环将左子树入栈但不访问
        while (p != NULL) {
            s.push(p);
            p = p->left;
        }
        // 此时p为空
        if (!s.empty()) {
            // 出栈并访问
            p = s.top(), s.pop();
            visit(p);
            p = p->right;
        }
    }
}