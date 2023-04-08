#include <math.h>
#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 打印堆树
void PrintHeap(int A[], int n) {
    int level = (int)log2(n) + 1;
    // 每次打印2^i个结果
    for (size_t i = 0, count = 0; count < n; i++) {
        for (size_t j = 0; j < level - i - 1; j++) {
            cout << " ";
        }
        for (size_t j = 0; j < pow(2, i) && count < n; j++, count++) {
            cout << " " << A[count] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 对某一个小堆进行调整(i表示该小根堆的顶部下标)
void minHeapify(int A[], int root, int heapSize) {
    // 左右孩子(minest用来判断三者中的最小值)
    int left = root * 2 + 1, right = root * 2 + 2, min = root;
    // 找到三者中的最小值(一定要先检查左右孩子是否存在)
    if (left < heapSize && A[left] < A[root]) {
        min = left;
    }
    if (right < heapSize && A[right] < A[root]) {
        min = right;
    }
    // 如果最小值不是堆顶元素
    if (min != root) {
        // 将最小值换到对顶部
        swap(A[root], A[min]);
        // 换下去后需要对以该处节点为顶的对再次进行调整
        minHeapify(A, min, heapSize);
    }
}

// 数组变为小根堆
void buildMinHeap(int A[], int heapSize) {
    // 从倒数第二层，最后一个拥有孩子的节点开始
    for (int i = heapSize / 2; i >= 0; i++) {
        // 必须自下而上进行调整
        minHeapify(A, i, heapSize);
    }
}

void HeapSort(int A[], int n) {
    // 构建小根堆
    buildMinHeap(A, n);
    // 此时堆顶即A[0]为最小值
    for (int heapSize = n - 1; heapSize > 0; heapSize--) {
        // 将堆顶换到堆的最底部，并减小堆容积(视为移除堆)
        swap(A[0], A[heapSize]);
        // 进行调整(建堆调整后，可以自上而下进行调整，所以每次都从0开始)
        minHeapify(A, 0, heapSize);
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
    PrintHeap(arr, 10);
    HeapSort(arr, 10);
    Print(arr, 10);
}