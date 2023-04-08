// 观察函数调用
#define M 100

int sum(int a, int b) {
    return a + b;
}

void function() {
    int x = 100;
    int y = 200;
    sum(x, y);
}