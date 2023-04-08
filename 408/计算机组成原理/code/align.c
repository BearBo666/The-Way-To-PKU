// 观察边界对齐
#include <stdio.h>

#pragma(1)  // 按1字节对齐
struct A {
    int a;
    char b;
    short c;
    char d;
};
#pragma()

int main() {
    struct A a;
    a.a = 1;
    a.b = 2;
    a.c = 3;
    a.d = 4;
    printf("%d %d %d %d\n", &a.a, &a.b, &a.c, &a.d);
    printf("int:%dB\n", sizeof(int));
    printf("char:%dB\n", sizeof(char));
    printf("short:%dB\n", sizeof(short));
    printf("struct:%dB\n", sizeof(struct A));
}