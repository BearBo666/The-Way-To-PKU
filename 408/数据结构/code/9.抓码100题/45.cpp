/*
    题目：折半查找(递归)
*/
#include <iostream>

using namespace std;

int BiSearch(int arr[], int key, int low, int high) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
        return key;
    if (key < arr[mid]) {
        return BiSearch(arr, key, low, mid);
    } else {
        return BiSearch(arr, key, mid, high);
    }
}

int main() {
}