#include <iostream>

using namespace std;

// 划分
// 一次划分≠一趟排序，一趟排序可以确定一个或多个元素最终位置，一次划分仅能确定一个
int Partition(int A[], int low, int high) {
    cout << "Partition: " << low << " " << high << endl;
    // 选定第一个元素为枢轴,故下面循环先用high开始遍历
    int pivot = A[low];
    while (low < high) {
        // 找到右边从右往左数第1个≤枢轴的元素
        while (A[high] >= pivot && low < high) {
            high--;
        }
        A[low] = A[high];
        // 找到左边第一个≥数轴的元素
        while (A[low] < pivot && low < high) {
            low++;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

// 快速排序
void Quick(int A[], int low, int high) {
    // 满足递归条件
    if (low < high) {
        // 进行一次划分
        int piovtIdx = Partition(A, low, high);
        // 对左右在进行递归快排
        Quick(A, low, piovtIdx - 1);
        Quick(A, piovtIdx + 1, high);
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
    Quick(arr, 0, 9);
    Print(arr, 10);
}