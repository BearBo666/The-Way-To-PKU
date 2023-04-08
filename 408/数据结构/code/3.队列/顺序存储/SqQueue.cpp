#include <iostream>
#define MaxSize 10
using namespace std;

typedef struct
{
    int data[MaxSize];
    int front, rear;
} SqQueue;

// 初始化
void InitQueue(SqQueue& Q) {
    Q.front = Q.rear = 0;
}
// 判空
bool Empty(SqQueue Q) {
    return Q.front == Q.rear;
}
// 判满
bool Full(SqQueue Q) {
    /*
        方法一：牺牲掉一个空间，队列的差一个就能插满
        方法二：结构体中增加一个size字段
        方法三：结构体中增加一个tag字段(初始0)，记录上一次操作的类型，
                ront==read时，若上次操作是插入则满
    */
    return (Q.rear + 1) % MaxSize == Q.front;
}
// 入队
bool EnQueue(SqQueue& Q, int e) {
    if (Full(Q)) {
        return false;
    }
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;

    return true;
}
// 出队
bool DeQueue(SqQueue& Q, int& e) {
    if (Empty(Q)) {
        return false;
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;

    return true;
}
// 获得队头元素
bool Head(SqQueue Q, int& e) {
    if (Empty(Q)) {
        return false;
    }
    e = Q.data[Q.front];
    return true;
}
// 长度
int Length(SqQueue Q) {
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}

int main() {
    int e;
    SqQueue q;
    InitQueue(q);

    for (size_t i = 0; i < 10; i++) {
        cout << "Enqueue " << i + 1 << ": " << EnQueue(q, i + 1) << endl;
    }
    cout << "Length: " << Length(q) << endl;
    cout << "Full: " << Full(q) << endl;

    for (size_t i = 0; i < 2; i++) {
        cout << "Dequeue: " << DeQueue(q, e) << "   " << e << endl;
    }
    cout << "Length: " << Length(q) << endl;
    cout << "Full: " << Full(q) << endl;
    for (size_t i = 0; i < 10; i++) {
        cout << "Enqueue " << i + 1 << ": " << EnQueue(q, i + 1) << endl;
    }
    cout << "Length: " << Length(q) << endl;
    cout << "Full: " << Full(q) << endl;
}