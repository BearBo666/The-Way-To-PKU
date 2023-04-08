// 观察变量类型
#include <stdio.h>

#define var1 10

typedef struct Info {
    int a;
    int b;
    char c;
    char d;
    int e;
} Info;

int var2 = 100;
const int var3 = 200;
static int var4 = 300;
Info var5;

int main() {
    Info* var6 = (Info*)malloc(sizeof(Info));
}