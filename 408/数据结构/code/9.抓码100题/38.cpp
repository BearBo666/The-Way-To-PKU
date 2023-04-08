/*
    题目：判断图是否是树
*/
#include <stdio.h>
#include <iostream>

#define MaxSize 100
typedef struct Graph {
    int data[MaxSize][MaxSize];
    int vNum, eNum;
} Graph;

bool isTree(Graph& g) {
    bool* visited = (bool*)malloc(sizeof(bool) * g.vNum);
    for (size_t i = 0; i < g.vNum; i++) {
        visited[false];
    }
    int vNum = 0, eNum = 0;
    DFS(g, 0, vNum, eNum, visited);

    // 一遍DFS能遍历完所有结点，且只经过了n-1条边即为树
    return vNum == g.vNum && eNum == (g.vNum - 1);
}

void DFS(Graph& g, int start, int& vNum, int& eNum, bool visited[]) {
    visited[start] = true;
    // 遍历邻居
    for (size_t i = 0; i < g.vNum; i++) {
        if (g.data[start][i] && !visited[i]) {
            vNum++;
            eNum++;
            DFS(g, i, vNum, eNum, visited);
        }
    }
}