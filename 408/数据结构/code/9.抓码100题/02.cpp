/*
题目：将顺序表逆置
*/

#include <iostream>

using namespace std;

void Reverse(int A[], int len) {
    int tmp;
    // i + j =len-1，故j=len-1-i
    for (size_t i = 0; i < len / 2; i++) {
        tmp = A[i];
        A[i] = A[len - 1 - i];
        A[len - 1 - i] = tmp;
    }
}

int main() {
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Reverse(A, 10);
    for (size_t i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
}