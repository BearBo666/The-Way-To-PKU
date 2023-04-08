#include <iostream>
#include <stack>

using namespace std;

typedef struct Node {
    int data;
    struct Node *left, *right;
    int tag = 0;
} * BTree, Node;

void visit(Node* p) {
    cout << p->data << " ";
}

// 法一：二次入栈法
void PostOrder(BTree T) {
    stack<Node*> s;
    Node* p = T;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top(), s.pop();
            // 若有右孩子，且只入栈过一次(表示右子树还未访问)，则再次入栈
            if (p->right && p->tag == 0) {
                p->tag = 1;
                s.push(p);
                p = p->right;
            } else {
                // 没有右孩子或入栈过两次(右子树已访问)
                visit(p);
                p = NULL;
            }
        }
    }
}

// 法二：前向指针法(更好)
void PostOrder2(BTree T) {
    stack<Node*> s;
    Node *p = T, *r = NULL;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();  // 并不出栈,因为可能会再push回去
            // 访问完右子树后r会指向右子树的根，相当于一个pre前向标记
            // 若有右子树且right不等于r则相等于右子树未访问，再次入栈
            if (p->right && p->right != r) {
                p = p->right;
            } else {
                // 没有右子树，或者右子树已访问完了,p此时是根,出栈
                s.pop();
                visit(p);
                // p可能是其父节点右子树的根，保留状态
                r = p;
                p = NULL;
            }
        }
    }
}

int main() {
}