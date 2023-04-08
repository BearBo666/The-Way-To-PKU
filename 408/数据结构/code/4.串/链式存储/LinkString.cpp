/*
    链式存储
*/
#include <iostream>

#define BlockSize 16

using namespace std;

/*
    一个char 1B，一个指针4B
    所以尽量一个节点多存一些字符
    但BlockSize设置过大会导致碎片较大
*/
typedef struct StringBlock {
    char ch[BlockSize];
    BlockPoint next;
} StringBlock, *BlockPoint;
// 字符串
typedef struct String {
    BlockPoint head;
    int length = 0;
    int blockNum = 0;
} String;

int main() {
}