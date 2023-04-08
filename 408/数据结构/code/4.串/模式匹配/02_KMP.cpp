#include <string.h>
#include <iostream>
#define MaxLen 255

using namespace std;

typedef struct {
    char ch[MaxLen];
    int len = 0;
} SString;

SString NewString(char* s) {
    SString string;
    // 下标从1开始
    string.ch[0] = '0';
    strcat(string.ch, s);
    string.len = strlen(s);
    return string;
}

// 计算next数组
int* getNext(SString T) {
    int* next = (int*)malloc((T.len + 1) * sizeof(int));
    // i、j错开一位，进行最大前后缀和匹配
    int i = 1, j = 0;
    next[1] = 0;
    // 求第i个字符的next位置
    while (i < T.len) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    return next;
}

// KMP匹配算法
int IndexOf(SString str, SString parten) {
    int i = 1, j = 1;
    int* next = getNext(parten);

    while (i < str.len && j < parten.len) {
        if (j == 0 || str.ch[i] == parten.ch[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }

    return j > parten.len ? i - parten.len : 0;
}

int main() {
    SString str, parten;
    str = NewString("abcdefg");
    parten = NewString("cdefg");

    cout << IndexOf(str, parten) << endl;
}