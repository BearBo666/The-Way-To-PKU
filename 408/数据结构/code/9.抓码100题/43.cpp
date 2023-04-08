/*
    题目：找到图中顶点之间的所有简单路径
*/
#include <iostream>

#define MaxSize 100
typedef struct Graph {
    int data[MaxSize][MaxSize];
    int vNum, eNum;
} Graph;

// 打印路径
void printPath(int path[], int len) {
    for (size_t i = 0; i < len; i++) {
        std::cout << path[i] << " ";
    }
}

bool visited[MaxSize];
void FindPath(Graph& g, int start, int end, int path[], int dis) {
    path[dis++] = start;  // 路径长度加一,并存储此结点
    // 找到一条路径,输出
    if (start == end) {
        printPath(path, dis);
        return;
    }
    visited[start] = true;  // 访问
    // 遍历起始结点的所有邻接点
    for (size_t i = 0; i < g.vNum; i++) {
        if (g.data[start][i] && !visited[i]) {
            FindPath(g, i, end, path, dis);
        }
    }
    // 回溯
    visited[start] = false;
}