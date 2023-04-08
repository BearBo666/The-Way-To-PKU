#include <iostream>

using namespace std;

typedef struct TreeNode {
    int data;
    int ltag, rtag;
    struct TreeNode *left, *right;
} TreeNode, *BTree;

TreeNode* pre = NULL;

// 生成一个结点
TreeNode* Node(int data) {
    TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    p->ltag = p->rtag = 0;
    return p;
}
// 访问
void Visit(TreeNode* p) {
    cout << p->data << " ";
    // 左子树为空才建立前驱线索
    if (p->left == NULL) {
        p->left = pre;
        p->ltag = 1;
    }
    // 前驱结点的右子树为空则建立后继线索
    if (pre != NULL && pre->right == NULL) {
        pre->right = p;
        pre->rtag = 1;
    }
    pre = p;
}
// 先序线索化
void PreThread(TreeNode* T) {
    if (T != NULL) {
        Visit(T);  // 这里改变了T的左子树，会影响下一行对左子树的判断
        // 判断是左子树还是左线索，避免陷入死循环
        if (T->ltag == 0) {
            PreThread(T->left);
        }
        PreThread(T->right);
    }
}
// 找到结点前驱
TreeNode* FindPre(TreeNode* p) {
    // 有线索
    if (p->ltag == 1) {
        return p->left;
    }
    // 左右子树中的结点只会是p的后继，不可能是前驱
    // Todo.....
    return NULL;
}
// 找到结点后继
TreeNode* FindPost(TreeNode* p) {
    // 有线索
    if (p->rtag == 1) {
        return p->right;
    }
    // 先序后继为左孩子，若为空则为右孩子
    TreeNode* t = p->left;
    if (p->left == NULL) {
        t = p->right;
    }
    return t;
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

    PreThread(root);
}