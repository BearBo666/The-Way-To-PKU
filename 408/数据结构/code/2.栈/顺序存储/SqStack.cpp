/*
    顺序栈
*/
#include <iostream>

#define MaxSize 20

using namespace std;

typedef struct {
    int data[MaxSize];
    int top;
} SqStack;

// 初始化
void InitStack(SqStack& S) {
    S.top = -1;
}
// 判空
bool Empty(SqStack S) {
    return S.top == -1;
}
// 入栈
bool Push(SqStack& S, int e) {
    if (S.top == MaxSize - 1) {
        return false;
    }
    S.data[++S.top] = e;
    return true;
}
// 出栈
bool Pop(SqStack& S, int& e) {
    if (S.top == -1) {
        return false;
    }
    e = S.data[S.top--];
    return true;
}
// 读栈顶
bool Top(SqStack& S, int& e) {
    if (S.top == -1) {
        return false;
    }
    e = S.data[S.top];
    return true;
}

int main() {
}