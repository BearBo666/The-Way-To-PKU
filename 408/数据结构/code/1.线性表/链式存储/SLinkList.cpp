/*
    静态链表
*/
#include <iostream>

using namespace std;

#define MaxSize 10
typedef struct Node {
    int data;
    int next;  // -1代表指向NULL，-2代表表空间为空
} * LinkList, SLinkList[MaxSize];

// 初始化静态链表空间，避免next域里有巧合的-1、-2
void InitSLinkList(LinkList L) {
    for (size_t i = 0; i < MaxSize; i++) {
        L[i].next = -1;
    }
}
// 判空
bool Empty(LinkList L) {
    return L[0].next == -1;
}
// 按位查找   O(n)
int GetElem(LinkList L, int i) {
    if (i < 0) {
        return -1;
    }

    int cnt = 0, p = 0;
    // 等价于不等于NULL
    while (p != -1) {
        p = L[p].next;
        cnt++;
    }
    return p;
}
// 删除某个节点
bool DeleteNode(LinkList L, int e) {
    if (Empty(L)) {
        return false;
    }
    int next;
    for (size_t i = 1; i < MaxSize; i++) {
        // 是可用节点
        if (L[i].next != -2) {
            next = L[i].next;
            // 它的下一个节点是待删除节点
            if (L[next].data == e) {
                L[i].next = L[next].next;
                L[next].next = -2;
                return true;
            }
        }
    }
    return false;
}
// 指定节点后插
bool InsertNextNode(LinkList L, int k, int e) {
    for (size_t i = 1; i < MaxSize; i++) {
        // 找到空闲空间
        if (L[i].next == -2) {
            L[i].data = e;
            L[k].next = i;
            return true;
        }
    }
    return false;
}
// 按位序插入
bool ListInsert(Node* L, int i, int e) {
    if (i < 1) {
        return false;
    }
    // 找到第i-1个元素
    int p = GetElem(L, i - 1);
    // 在其后面插入,其实可优化,因为有多余的遍历次数
    return InsertNextNode(L, p, e);
}

int main() {
    SLinkList L;
    L[0].next = -1;
}