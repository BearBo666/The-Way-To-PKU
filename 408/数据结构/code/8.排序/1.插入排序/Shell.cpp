#include <iostream>

using namespace std;

// 希尔排序
void Shell(int A[], int len) {
    int i, j, k, d, tmp;
    // 每次减少增量
    for (d = len / 2; d >= 1; d /= 2) {
        // 第i个分组：i、i+d、i+2d
        for (i = 0; i < d; i++) {
            // 对此分组进行直接插入排序
            for (j = i + d; j < len; j = j + d) {
                // 如果比前一个元素小
                if (A[j] < A[j - d]) {
                    tmp = A[j];
                    // 比目标元素大的元素都往后移动
                    for (k = j - d; k >= i && A[k] > tmp; k = k - d) {
                        A[k + d] = A[k];
                    }
                    A[k + d] = tmp;
                }
            }
        }
    }
}

void Print(int A[], int n) {
    cout << "Shell Sort:";
    for (size_t i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {7, 2, 8, 6, 5, 9, 10, 1, 2, 3};
    Shell(arr, 10);
    Print(arr, 10);
}