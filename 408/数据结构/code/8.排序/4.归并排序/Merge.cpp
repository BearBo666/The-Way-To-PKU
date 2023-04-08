#include <iostream>

#define N 10

using namespace std;

int* B = (int*)malloc(N * sizeof(int));

// [low,mid] [mid+1,hgih]有序，进行归并
void Merge(int A[], int low, int mid, int high) {
    int i, j, k;
    // 将[low,hgih]拷贝到B中
    for (i = low; i <= high; i++) {
        B[i] = A[i];
    }
    // i指向1路，j指向2路，k指向要插入的位置
    for (k = i = low, j = mid + 1; i <= mid && j <= high; k++) {
        // 1路本就在2路左边，优先放进去，故稳定
        if (B[i] < B[j]) {
            A[k] = B[i++];
        } else {
            A[k] = B[j++];
        }
    }
    // 把未归并完的归并进去
    while (i <= mid) {
        A[k++] = B[i++];
    }
    while (j <= high) {
        A[k++] = B[j++];
    }
}

void MergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        // 对左右部分进行归并排序
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        // 归并
        Merge(A, low, mid, high);
    }
}

void Print(int A[], int n) {
    for (size_t i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[N] = {7, 2, 8, 6, 5, 9, 10, 1, 2, 3};
    MergeSort(arr, 0, N);
    Print(arr, N);
}