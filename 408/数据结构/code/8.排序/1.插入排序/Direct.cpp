#include <iostream>

using namespace std;

// 直接插入排序
void InsertSort(int A[], int n) {
    int i, j, tmp;
    // 处理第i个元素
    for (i = 1; i < n; i++) {
        // 比前面一个元素小才进行插入
        if (A[i] < A[i - 1]) {
            tmp = A[i];
            // 比目标元素大的元素都往后移动
            for (j = i - 1; j >= 0 && A[j] > tmp; --j) {
                A[j + 1] = A[j];
            }
            A[j + 1] = tmp;
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
    InsertSort(arr, 10);
    Print(arr, 10);
}