#include <stdio.h>
#include <iostream>

// 初始化初始长度
#define InitSize 10

using namespace std;

typedef struct
{
    int* data;
    int MaxSize;  // 当前的容量
    int length;
} SeqList;

// 初始化线性表  O(1)
void InitList(SeqList& L);
// 动态增加数组的长度
void IncreaseSize(SeqList& L, int len);
// 指定位序插入  O(n)
bool ListInsert(SeqList& L, int i, int e);
// 指定位序删除  O(n)
bool ListDelete(SeqList& L, int i, int& e);
// 按位查找     O(1)
bool GetElem(SeqList L, int i, int& e);
// 按值查找     O(n)
int LocateElem(SeqList L, int e);

int main() {
    SeqList L;
    InitList(L);
    // 插入11个
    for (int i = 0; i < 11; i++) {
        cout << "插入" << i << "结果：" << ListInsert(L, i, i) << endl;
    }
    cout << "长度：" << L.length << endl;

    // 删除第5个
    int elem;
    cout << "删除结果：" << ListDelete(L, 4, elem) << "，元素：" << elem << endl;

    // 扩容10个，再插入10个
    IncreaseSize(L, 10);
    cout << "扩容后空间：" << L.MaxSize << endl;
    // 插入10个
    for (int i = 0; i < 10; i++) {
        cout << "插入" << i + 10 << "结果：" << ListInsert(L, 9 + i, 10 + i) << endl;
    }

    // 按位查找
    cout << "查找下标10结果：" << GetElem(L, 10, elem) << "，元素：" << elem << endl;
    // 按值查找
    cout << "元素5下标：" << LocateElem(L, 5) << "，元素13下标：" << LocateElem(L, 13) << endl;

    return 0;
}

// 代码实现
void InitList(SeqList& L) {
    L.data = (int*)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}
void IncreaseSize(SeqList& L, int len) {
    // 先保留原来的数据的指针
    int* p = L.data;
    // 重新申请空间
    L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
    // 数据迁移
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    // 释放原来的数据空间
    free(p);
}
bool ListInsert(SeqList& L, int i, int e) {
    // 空间满了，不能插入
    if (L.length >= L.MaxSize) {
        cout << "空间满，插入失败！" << endl;
        return false;
    }
    // 检验是否越界
    if (!(i >= 0 && i <= L.length)) {
        cout << "下标" << i << "越界，插入失败！" << endl;
        return false;
    }
    // 将下标为i的元素开始的元素向后移一位
    for (int j = L.length; j > i; j--) {
        L.data[j] = L.data[j - 1];
    }
    // 放入元素
    L.data[i] = e;
    L.length++;
    return true;
}
bool ListDelete(SeqList& L, int i, int& e) {
    // 检验是否越界
    if (!(i >= 0 && i < L.length)) {
        return false;
    }
    // 删除的元素赋给e
    e = L.data[i];
    // 删除位置后面的元素前移
    for (int j = i + 1; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}
bool GetElem(SeqList L, int i, int& e) {
    // 检验是否越界
    if (!(i >= 0 && i < L.length)) {
        return false;
    }
    e = L.data[i];
    return true;
}
int LocateElem(SeqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i;
        }
    }
    return -1;
}