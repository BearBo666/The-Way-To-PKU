/*
题目：删除题目中所有满足条件的元素
*/
#include <iostream>

using namespace std;

// 解法一：统计每个元素前面的满足条件的元素的个数k，并将此元素前移k位
void func1(int A[], int len, bool (*cb)(int x)) {
    int k = 0;
    // 统计个数
    for (size_t i = 0; i < len; i++) {
        if (cb(A[i])) {
            k++;
        } else {
            // 前面有k个
            A[i - k] = A[i];
        }
    }
}

int main() {
    int A[10] = {1, 2, 3, 4, 5, 5, 5, 8, 9, 10};
    auto cb = [](int x) -> bool {
        return x == 5;
    };
    func1(A, 10, cb);
    for (size_t i = 0; i < 7; i++) {
        cout << A[i] << " ";
    }
}