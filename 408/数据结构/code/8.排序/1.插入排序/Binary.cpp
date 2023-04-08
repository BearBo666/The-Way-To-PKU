#include <iostream>

using namespace std;

// 折半插入
void BinaryInsert(int A[], int n) {
    int i, j, low, high, mid, tmp;
    // 处理第i个元素
    for (i = 1; i < n; i++) {
        tmp = A[i];
        low = 0, high = i - 1;
        // upper_bound
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (A[mid] > tmp) {
                high = mid - 1;
            } else {
                // mid等于target也向前移动
                // 相等于等于的情况也小于目标值，保证了稳定性
                low = mid + 1;
            }
        }
        // [low,i-1]向后移动
        for (j = i - 1; j >= high + 1; j--) {
            A[j + 1] = A[j];
        }
        A[high + 1] = tmp;
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
    BinaryInsert(arr, 10);
    Print(arr, 10);
}