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
// 中序线索化
void InThread(TreeNode* T) {
    if (T != NULL) {
        // 递归线索化
        InThread(T->left);
        Visit(T);  // 这里仅改变了T的左子树，所以不影响后面对右子树的判断
        InThread(T->right);
    }
}
// 找到结点前驱
TreeNode* FindPre(TreeNode* p) {
    // 有线索
    if (p->ltag == 1) {
        return p->left;
    }
    // 有左子树,找其左子树的最右下结点
    TreeNode* t = p->left;
    while (t != NULL && t->rtag == 0) {
        t = t->right;
    }
    return t;
}
// 找到结点后继
TreeNode* FindPost(TreeNode* p) {
    // 有线索
    if (p->rtag == 1) {
        return p->right;
    }
    // 有右子树,找其右子树的最左下结点
    TreeNode* t = p->right;
    while (t != NULL && t->ltag == 0) {
        t = t->left;
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

    InThread(root);
    cout << endl;
    cout << "The pre of 6 is:" << FindPre(_6)->data << endl;
    cout << "The post of 5 is:" << FindPost(_5)->data << endl;
}