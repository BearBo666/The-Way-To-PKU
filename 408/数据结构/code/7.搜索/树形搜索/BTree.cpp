#include <iostream>

// 分叉数
#define M 5
// m/2向上取整
#define K 3

using namespace std;

typedef struct BTreeNode {
    bool isLeaf;
    int n, *keys;                 // 关键字数组、以及有多少关键字
    struct BTreeNode** children;  // 孩子数组
} BTreeNode;

// 构造函数
BTreeNode* Node(bool isLeaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    if (node == NULL) {
        return NULL;
    }
    node->keys = new int[M];
};
// 在结点中搜索
BTreeNode* Search(BTreeNode* node, int k) {
    // 如果已经是叶子则查找失败
    if (node->isLeaf) {
        return NULL;
    }
    // 找到第一个大于等于k的记录
    int i = 0;
    while (i < node->n && k > node->keys[i])
        i++;
    // 找到了
    if (k == node->keys[i])
        return node;
    // 在子树中搜索
    return Search(node->children[i], k);
}

int main() {
}