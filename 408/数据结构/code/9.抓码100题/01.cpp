/*
题目：将线性表调整为奇数在前，偶数在后
*/
#include <iostream>

using namespace std;

// 类比快排的Parition的思想
void AdjustList(int A[], int len) {
    int pivot = A[0];
    int low = 0, high = len - 1;
    while (low < high) {
        while (low < high && A[high] % 2 == 0)
            --high;
        A[low] = A[high];
        while (low < high && A[low] % 2 != 0)
            ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
}

int main() {
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    AdjustList(A, 9);
    for (size_t i = 0; i < 9; i++) {
        cout << A[i] << " ";
    }
}