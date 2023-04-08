/*
题目：设计循环队列，以tag方式来判断空还是满
*/
#include <iostream>
#define QueueSize 100

using namespace std;

typedef struct SqQueue {
    int data[QueueSize];
    int front, rear;
    bool lastInsert;  // 虽然bool只占1B，但是会对齐，仍然是一个字长，不过还是尽量用bool
};

void initqueue(SqQueue& q) {
    q.front = q.rear = 0;
    q.lastInsert = false;
}

bool enqueue(SqQueue& q, int ele) {
    // 队头队尾指针相同，并且上次操作是插入,表示队满
    if ((q.front == q.rear) && q.lastInsert) {
        return false;
    }
    q.data[q.rear] = ele;
    q.rear = (q.rear + 1) % QueueSize;
    q.lastInsert = true;

    return true;
}

bool dequque(SqQueue& q, int& ele) {
    // 队头队尾指针相同，并且上次操作非插入,表示队空
    if ((q.front == q.rear) && !q.lastInsert) {
        return false;
    }
    ele = q.data[q.front];
    q.front = (q.front + 1) % QueueSize;
    q.lastInsert = false;

    return true;
}

main() {
}