/*
非递归实现二叉树前序遍历
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
        // 循环往左遍历
        while (p != NULL) {
            // 访问此结点并入栈
            visit(p);
            s.push(p);
            // 遍历左子树，至到没有左子树
            p = p->left;
        }
        // 此时p指向最左元素的左指针，栈顶为最左元素
        if (!s.empty()) {
            // 将p指向最左元素的右根
            p = s.top(), s.pop();
            p = p->right;
        }
    }
}