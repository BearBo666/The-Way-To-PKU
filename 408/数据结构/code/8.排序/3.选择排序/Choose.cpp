#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 简单选择排序
void Choose(int A[], int n) {
    int i, j, min;
    // 每次选择最小的一个放到最前面 n-1趟
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (min != i) {
            cout << "choose: " << A[min] << endl;
            swap(A[i], A[min]);
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
    Choose(arr, 10);
    Print(arr, 10);
}