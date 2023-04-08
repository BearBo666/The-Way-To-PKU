/*
    链式队列
*/
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    Node* next;
} Node, *LinkNode;

typedef struct LinkQueue {
    int length;
    LinkNode front, rear;  // 队头、队尾指针
} LinkQueue;

// 初始化(不带头节点)
void InitQueue(LinkQueue& Q) {
    Q.length = 0;
    Q.front = Q.rear = NULL;
}
// 判空
bool Empty(LinkQueue Q) {
    return Q.front == NULL;
}
// 入队
bool Enqueue(LinkQueue& Q, int e) {
    LinkNode node = (LinkNode)malloc(sizeof(Node));
    if (node == NULL) {
        return false;
    }
    node->data = e;
    if (Empty(Q)) {
        Q.front = Q.rear = node;
    } else {
        Q.rear->next = node;
        Q.rear = node;
    }
    Q.length++;
    return true;
}
// 出队
bool Dequeue(LinkQueue& Q, int& e) {
    if (Empty(Q)) {
        return false;
    }
    LinkNode p = Q.front;
    e = p->data;
    Q.front = p->next;
    // 如果空了
    if (Q.rear == p) {
        Q.rear = NULL;
    }
    Q.length--;
    return true;
}

int main() {
    int e;
    LinkQueue q;
    InitQueue(q);
    // 入队
    for (size_t i = 0; i < 5; i++) {
        cout << "Enqueue " << i + 1 << ": " << Enqueue(q, i + 1) << endl;
    }
    cout << "Length: " << q.length << endl;
    cout << "Full: " << Empty(q) << endl;
    // 出队
    for (size_t i = 0; i < 2; i++) {
        cout << "Dequeue: " << Dequeue(q, e) << "   " << e << endl;
    }
    cout << "Length: " << q.length << endl;
    cout << "Full: " << Empty(q) << endl;
    // 入队
    for (size_t i = 0; i < 5; i++) {
        cout << "Enqueue " << i + 1 << ": " << Enqueue(q, i + 1) << endl;
    }
    cout << "Length: " << q.length << endl;
    cout << "Full: " << Empty(q) << endl;
}