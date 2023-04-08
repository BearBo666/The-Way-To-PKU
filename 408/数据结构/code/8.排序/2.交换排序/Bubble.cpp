#include <iostream>

using namespace std;

// 交换排序，没有交换怎么行？
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 冒泡排序
void Bubble(int A[], int n) {
    // 第i趟，每趟从后往前冒一个元素
    for (size_t i = 0; i < n - 1; i++) {
        bool flag = false;
        for (size_t j = n - 1; j > i; j--) {
            // 若相等时也交换则不稳定
            if (A[j - 1] > A[j]) {
                swap(A[j - 1], A[j]);
                flag = true;
            }
        }
        if (!flag) {
            return;
        }
    }
}

void Print(int A[], int n) {
    for (size_t i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {7, 2, 8, 6, 5, 9, 10, 1, 2, 3};
    Bubble(arr, 10);
    Print(arr, 10);
}