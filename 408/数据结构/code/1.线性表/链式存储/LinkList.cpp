/*
    带头节点的单链表
*/
#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;
// 等价于 typedef struct LNode LNode
// 等价于 typedef struct LNode *LinkList

// 头插法(不带头节点)  仅示范，后面函数均为带头节点
LinkList InitListByHead2() {
    LinkList L = NULL;
    LNode* node;
    // 读取数据
    int in;
    cout << "输入数据，9999代表结束：";
    cin >> in;
    while (in != 9999) {
        // 看是否是创建的第一个元素
        if (L != NULL) {
            // 申请空间
            node = (LNode*)malloc(sizeof(LNode));
            node->data = in;
            // 节点指向第一个节点
            node->next = L;
            L = node;
        } else {
            L = (LNode*)malloc(sizeof(LNode));
            L->data = in;
            L->next = NULL;
        }
        cout << "输入数据，9999代表结束：";
        cin >> in;
    }
    return L;
}
// 头插法(带头节点)  先插入的在后面
LinkList InitListByHead() {
    // 创建头节点
    LNode *head, *node;
    head = (LNode*)malloc(sizeof(LNode));
    head->next = NULL;

    // 读取数据
    int in;
    cout << "input data,9999 means over:";
    cin >> in;
    while (in != 9999) {
        // 申请空间
        node = (LNode*)malloc(sizeof(LNode));
        node->data = in;
        // 继承头节点的next
        node->next = head->next;
        head->next = node;
        cout << "input data,9999 means over:";
        cin >> in;
    }

    return head;
}
// 尾插法
LinkList ListTailInsert() {
    // 创建头节点
    LNode *head, *node;
    head = (LNode*)malloc(sizeof(LNode));
    head->next = NULL;
    LNode* tail = head;

    // 读取数据
    int in;
    cout << "输入数据，9999代表结束：";
    cin >> in;
    while (in != 9999) {
        // 申请空间
        node = (LNode*)malloc(sizeof(LNode));
        node->data = in;
        // 插到尾部
        tail->next = node;
        tail = node;
    }
    tail->next = NULL;

    return head;
}
// 判空
bool Empty(LinkList L) {
    return L->next == NULL;
}
// 按位查找   O(n)
LNode* GetElem(LinkList L, int i) {
    if (i < 0) {
        return NULL;
    }

    int cnt = 0;
    LNode* p = L;
    while (p != NULL && cnt < i) {
        p = p->next;
        cnt++;
    }
    return p;
}
// 按值查找
LNode* LocateElem(LinkList L, int e) {
    LNode* p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}
// 指定节点的后插
bool InsertNextNode(LNode* p, int e) {
    if (p == NULL) {
        return false;
    }

    // 生成新节点
    LNode* node = (LNode*)malloc(sizeof(LNode));
    if (node == NULL) {
        return false;
    }
    node->data = e;
    node->next = p->next;
    p->next = node;

    return true;
}
// 指定节点的前插
bool InsertPriorNode(LNode* p, int e) {
    /*
        a->b->c
        假设要在b的前面插入d，不需要从头开始遍历链表
        只需先用一个tmp存下b，然后将b覆盖为d，然后在d后插b即可
    */
    if (p == NULL) {
        return false;
    }
    // 覆盖原数据
    int tmp = p->data;
    p->data = e;
    // 后插
    return InsertNextNode(p, tmp);
}
// 按位序插入 O(n)
bool ListInsert(LinkList& L, int i, int e) {
    if (i < 1) {
        return false;
    }
    // 找到第i-1个元素
    LNode* p = GetElem(L, i - 1);
    // 在第i-1个节点后插入
    return InsertNextNode(p, e);
}
// 按位序删除  O(n)
bool ListDelete(LinkList L, int i, int& e) {
    if (i < 1) {
        return false;
    }

    // 找到第i个节点
    LNode* p = GetElem(L, i - 1);
    if (p == NULL || p->next == NULL) {
        return false;
    }

    // 将第i个节点从链表中断开
    LNode* q;
    q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);

    return true;
}
// 删除指定节点
bool DeleteNode(LinkList L, LNode* p) {
    /*
        a->b->c
        类似于指定节点前插，不需要从头开始遍历找到前驱节点
        可以“遮天蔽日”，将b的值设为c，然后删除c
        但如果b是最后一个节点，就只能从头开始遍历
    */
    if (p == NULL) {
        return false;
    }
    LNode* q;
    // 非最后一个节点
    if (p->next != NULL) {
        q = p->next;
        p->data = q->data;
        p->next = q->next;
        free(q);
        return true;
    }

    // p是最后一个节点
    q = L;
    while (q->next != p) {
        q = q->next;
    }
    // p不是链表中的节点
    if (q == NULL) {
        return false;
    }
    free(q->next);
    q->next = NULL;
    return true;
}
// 获得长度
int Length(LinkList L) {
    int cnt = 0;
    LNode* p = L;
    while (p->next != NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}
// 打印
void Print(LinkList L) {
    LNode* p = L->next;
    cout << "Print:";
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    // 头插法创建一个链表
    LinkList L = InitListByHead();
    Print(L);
    // 查找第3个元素
    LNode* node = GetElem(L, 3);
    cout << "The 3th Elem: " << node->data << endl;
    // 查找值为5的元素
    node = LocateElem(L, 5);
    cout << "The Elem valued 5 is: " << node->data << endl;
    // 在第三个元素前后后插入
    cout << "Insert 9999 after 3th: " << InsertNextNode(node, 9999) << endl;
    cout << "Insert 8888 before 3th: " << InsertPriorNode(node, 8888) << endl;
    Print(L);
    // 在最后的位置插入10000
    int len = Length(L);
    cout << "Insert 10000 on the tail: " << ListInsert(L, len + 1, 10000) << endl;
    Print(L);
    // 删除最后一个元素
    int e = 0;
    cout << "Delete the last Elem: " << ListDelete(L, len + 1, e) << endl;
    Print(L);
    return 0;
}