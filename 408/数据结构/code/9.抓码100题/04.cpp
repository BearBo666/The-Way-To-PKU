/*
题目：删除线性表中的最小元素，空出的元素由最后一个元素补充
*/
#include <iostream>

using namespace std;

int DeleteMin(int A[], int len) {
    int pos = 0, tmp;
    for (size_t i = 0; i < len; i++) {
        if (A[i] < A[pos]) {
            pos = i;
        }
    }
    tmp = A[pos];
    A[pos] = A[len - 1];
    return tmp;
}

int main() {
    int A[10] = {5, 6, 7, 8, 1, -1, 9, 10, 20, 30};
    cout << DeleteMin(A, 10) << endl;
    for (size_t i = 0; i < 9; i++) {
        cout << A[i] << " ";
    }
}