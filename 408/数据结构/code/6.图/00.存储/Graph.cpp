/*
    邻接表存储
    空间：O(v^2)
*/
#include <iostream>

#define MaxVertex 100
#define M 2147483647

using namespace std;

typedef struct Graph {
    int edge[MaxVertex][MaxVertex];
    int vNum, eNum;
} Graph;

// 初始化邻接矩阵
void InitGraph(Graph& g) {
    int N = 5;
    int mock[5][5] = {
        {0, 10, M, M, 5},  // 0->1 0->4
        {M, 0, 1, M, 2},   // 1->2 1->4
        {M, M, 0, 4, M},   // 2->3
        {7, M, 6, 0, M},   // 3->1 3->2
        {M, 3, 9, 2, 0},   // 4->1 4->2 4->3
    };
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            g.edge[i][j] = mock[i][j];
        }
    }
    g.vNum = N;
    g.eNum = 10;
}
// 找到第一个邻居的顶点号
int FirstNeighbor(Graph& g, int x) {
    if (x < 0 || x >= g.vNum) {
        return -1;
    }
    for (size_t i = 0; i < g.vNum; i++) {
        if (i != x && g.edge[x][i] != M) {
            return i;
        }
    }
    return -1;
}
// 找到下一个邻居
int NextNeighbor(Graph& g, int x, int y) {
    if (x < 0 || x >= g.vNum) {
        return -1;
    }
    for (size_t i = y + 1; i < g.vNum; i++) {
        if (i != x && g.edge[x][i] != M) {
            return i;
        }
    }
    return -1;
}

int main() {
}