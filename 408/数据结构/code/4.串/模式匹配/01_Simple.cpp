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

// 朴素模式匹配
int IndexOf(SString str, SString parten) {
    int i = 1, j = 1;
    while (i <= str.len && j <= parten.len) {
        if (str.ch[i] == parten.ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 1;
        }
    }

    return j == parten.len ? i - j : 0;
}

int main() {
    SString str, parten;
    str = NewString("abcdefg");
    parten = NewString("cdefg");

    cout << IndexOf(str, parten) << endl;
}