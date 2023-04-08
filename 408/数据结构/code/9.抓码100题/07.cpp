/*
题目：10年统考真题，数组循环移位
*/
#include <iostream>

using namespace std;

// 数组逆置
void Reverse(int A[], int low, int high) {
    int tmp;
    while (low < high) {
        tmp = A[low];
        A[low] = A[high];
        A[high] = tmp;
        low++, high--;
    }
}

void LeftShift(int A[], int len, int p) {
    // 数组全部逆置
    Reverse(A, 0, len - 1);
    // 前部分逆置
    Reverse(A, 0, len - p - 1);
    // 后p个逆置
    Reverse(A, len - p, len - 1);
}

int main() {
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LeftShift(A, 10, 2);
    for (size_t i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
}