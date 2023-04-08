/*
题目：将满足条件的元素删除，同第五题，此题用解法二
总结：解法一类似插入排序思想、解法二双指针(前指针为遍历指针，后指针统计不满足条件个数)
*/
#include <iostream>

using namespace std;

// 解法二：双指针，后面的指针指向下一个不满足条件的元素该放的位置
void func2(int A[], int len, bool (*cb)(int x)) {
    int k = 0;
    for (size_t i = 0; i < len; i++) {
        if (!cb(A[i])) {
            A[k++] = A[i];
        }
    }
}

int main() {
    auto cb = [](int x) -> bool {
        return x >= 5 && x <= 9;
    };

    int B[10] = {1, 2, 3, 4, 5, 5, 5, 8, 9, 10};
    func2(B, 10, cb);
    for (size_t i = 0; i < 10; i++) {
        cout << B[i] << " ";
    }
}