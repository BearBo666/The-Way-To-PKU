/*
题目：两个有序表合并成新的有序表
*/
#include <iostream>

using namespace std;

int* MergeList(int A[], int B[], int len1, int len2) {
    int* C = (int*)malloc((len1 + len2) * sizeof(int));
    int i, j, k;
    i = j = k = 0;
    while (i < len1 && j < len2) {
        if (A[i] <= B[j]) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }
    while (i < len1) {
        C[k++] = A[i++];
    }
    while (j < len2) {
        C[k++] = B[j++];
    }
    return C;
}

int main() {
    int A[8] = {5, 6, 7, 8, 9, 10, 20, 30};
    int B[5] = {1, 2, 3, 10, 15};
    int* C = MergeList(A, B, 8, 5);
    for (size_t i = 0; i < 13; i++) {
        cout << C[i] << " ";
    }
}