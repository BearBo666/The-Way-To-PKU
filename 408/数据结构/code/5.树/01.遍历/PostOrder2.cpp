/*
非递归实现后序遍历
*/
#include <iostream>
#include <stack>

using namespace std;

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode, *BiTree;

typedef struct StackElem {
    TreeNode* node;
    int flag;  // 标记第几次访问
};

// 访问
void visit(TreeNode* ele) {
    cout << ele->data << " ";
}

// 实现
void PostOrder(BiTree T) {
    stack<StackElem> s;
    TreeNode* p = T;
    StackElem elem;
    // p为空栈为空推出循环
    while (p != NULL || !s.empty()) {
        // 循环将左子树入栈但不访问
        while (p != NULL) {
            elem.node = p;
            elem.flag = 1;
            s.push(elem);
            p = p->left;
        }
        // 此时p为空，即左子树访问完毕
        if (!s.empty()) {
            elem = s.top(), s.pop();
            p = elem.node;
            // 第一次入栈
            if (elem.flag == 1) {
                // 再次入栈，并访问右孩子
                elem.flag = 2;
                s.push(elem);
                p = p->right;
            } else {
                // 第二次入栈，进行访问
                visit(p);
                p = NULL;
            }
        }
    }
}