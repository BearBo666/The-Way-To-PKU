/*
题目：以栈的方式判断回文
*/
#include <iostream>
#define StackSize 100

using namespace std;

bool judgeHuiWen(char* str) {
    // 声明栈
    char stack[StackSize];
    int top = -1, len = strlen(str), i;

    // 将一半的字符入栈
    for (i = 0; i < len / 2; i++) {
        stack[++top] = str[i];
    }
    if (len % 2 != 0) {
        i++;
    }
    // 栈未空
    while (top != -1) {
        // 出栈与后半段比较
        if (stack[top--] != str[i++])
            return false;
    }
    return true;
}

int main() {
}