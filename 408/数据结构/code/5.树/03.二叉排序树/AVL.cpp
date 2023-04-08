#include <stdlib.h>
#include <iostream>

using namespace std;

// 定义平衡二叉树的结点结构
typedef struct TreeNode {
    int data;
    int bf;  // 平衡因子
    TreeNode *left, *right, *parent;
} TreeNode, *BiTree;

// 构造函数
TreeNode* Node(int e) {
    TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
    if (p == NULL) {
        return NULL;
    }
    p->data = e;
    p->parent = p->left = p->right = NULL;
    return p;
}

// 右旋处理，即LL调整
void RRotate(TreeNode* f) {
    /*
      目标：
        1.父节点左孩子p取代父节点    把爸爸的腿先接上
        2.父节点变p的右孩子         斩首
        3.p的左孩子变父节点的左孩子  请客
    */
    TreeNode* gf = f->parent;
    TreeNode* p = f->left;
    bool isLeft = gf->left == f;

    // 父结点左指针指向p右子树
    f->left = f->left->right;
    // p的右指针指向父结点
    p->right = f;
    // 祖父结点指向新孩子
    if (isLeft) {
        gf->left = p;
    } else {
        gf->right = p;
    }
}
// 左旋处理，即RR调整
void LRotate(TreeNode* f) {
    /*
       目标：
        1.父节点右孩子p取代父节点    把爸爸的腿先接上
        2.父节点变p的左孩子         斩首
        3.p的左孩子变父节点的右孩子  请客
     */
    TreeNode* gf = f->parent;
    TreeNode* p = f->right;
    bool isLeft = gf->left == f;

    // 父结点右指针指向p左子树
    f->right = f->right->left;
    // p的左指针指向父结点
    p->left = f;
    // 祖父结点指向新孩子
    if (isLeft) {
        gf->left = p;
    } else {
        gf->right = p;
    }
}
// 先左旋再右旋，即LR调整
void LRRotate(TreeNode* f, bool isLeft) {
    // 左子树左旋
    LRotate(f->left);
    // 再右旋
    RRotate(f);
}
// 先右旋再左旋，即RL调整
void LRRotate(TreeNode* gf, TreeNode* f, bool isLeft) {
    // 右子树右旋
    RRotate(f->right);
    // 再左旋
    LRotate(f);
}

// 在某棵子树中插入结点
bool Insert(BiTree root, int e) {
    return false;
}
// 最后插入的树
void RealInsert(TreeNode* f, TreeNode* node, bool isLeft) {
    // 在f的左边插入
    if (isLeft) {
        f->left = node;
        // 如果f有右孩子，不可能破坏平衡了
        if (f->right != NULL) {
            return;
        }
    }
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
}