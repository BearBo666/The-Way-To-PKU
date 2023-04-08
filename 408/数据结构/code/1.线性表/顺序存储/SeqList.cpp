#include <stdio.h>
#include <iostream>

// ��ʼ����ʼ����
#define InitSize 10

using namespace std;

typedef struct
{
    int* data;
    int MaxSize;  // ��ǰ������
    int length;
} SeqList;

// ��ʼ�����Ա�  O(1)
void InitList(SeqList& L);
// ��̬��������ĳ���
void IncreaseSize(SeqList& L, int len);
// ָ��λ�����  O(n)
bool ListInsert(SeqList& L, int i, int e);
// ָ��λ��ɾ��  O(n)
bool ListDelete(SeqList& L, int i, int& e);
// ��λ����     O(1)
bool GetElem(SeqList L, int i, int& e);
// ��ֵ����     O(n)
int LocateElem(SeqList L, int e);

int main() {
    SeqList L;
    InitList(L);
    // ����11��
    for (int i = 0; i < 11; i++) {
        cout << "����" << i << "�����" << ListInsert(L, i, i) << endl;
    }
    cout << "���ȣ�" << L.length << endl;

    // ɾ����5��
    int elem;
    cout << "ɾ�������" << ListDelete(L, 4, elem) << "��Ԫ�أ�" << elem << endl;

    // ����10�����ٲ���10��
    IncreaseSize(L, 10);
    cout << "���ݺ�ռ䣺" << L.MaxSize << endl;
    // ����10��
    for (int i = 0; i < 10; i++) {
        cout << "����" << i + 10 << "�����" << ListInsert(L, 9 + i, 10 + i) << endl;
    }

    // ��λ����
    cout << "�����±�10�����" << GetElem(L, 10, elem) << "��Ԫ�أ�" << elem << endl;
    // ��ֵ����
    cout << "Ԫ��5�±꣺" << LocateElem(L, 5) << "��Ԫ��13�±꣺" << LocateElem(L, 13) << endl;

    return 0;
}

// ����ʵ��
void InitList(SeqList& L) {
    L.data = (int*)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}
void IncreaseSize(SeqList& L, int len) {
    // �ȱ���ԭ�������ݵ�ָ��
    int* p = L.data;
    // ��������ռ�
    L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
    // ����Ǩ��
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    // �ͷ�ԭ�������ݿռ�
    free(p);
}
bool ListInsert(SeqList& L, int i, int e) {
    // �ռ����ˣ����ܲ���
    if (L.length >= L.MaxSize) {
        cout << "�ռ���������ʧ�ܣ�" << endl;
        return false;
    }
    // �����Ƿ�Խ��
    if (!(i >= 0 && i <= L.length)) {
        cout << "�±�" << i << "Խ�磬����ʧ�ܣ�" << endl;
        return false;
    }
    // ���±�Ϊi��Ԫ�ؿ�ʼ��Ԫ�������һλ
    for (int j = L.length; j > i; j--) {
        L.data[j] = L.data[j - 1];
    }
    // ����Ԫ��
    L.data[i] = e;
    L.length++;
    return true;
}
bool ListDelete(SeqList& L, int i, int& e) {
    // �����Ƿ�Խ��
    if (!(i >= 0 && i < L.length)) {
        return false;
    }
    // ɾ����Ԫ�ظ���e
    e = L.data[i];
    // ɾ��λ�ú����Ԫ��ǰ��
    for (int j = i + 1; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}
bool GetElem(SeqList L, int i, int& e) {
    // �����Ƿ�Խ��
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