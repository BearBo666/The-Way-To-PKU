#include <iostream>
#define MaxLen 255

using namespace std;

// 栈区分配
typedef struct {
    char ch[MaxLen];
    int len = 0;
} SString;
// 堆区分配
typedef struct {
    char* ch;
    int len = 0;
} HString;

int main() {
    SString str1;
    HString str2;
    str2.ch = (char*)malloc(sizeof(char) * MaxLen);
}