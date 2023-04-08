/*
    邻接矩阵实现拓扑排序(基于dfs)：
        空间：O(v)   递归栈
        时间：O(v^2) 相当于遍历图
*/
#include <iostream>
#include <stack>

#define MaxVertex 100
#define M 2147483647
#define White 0
#define Gray 1
#define Black 2

using namespace std;

typedef struct Graph {
    int edge[MaxVertex][MaxVertex];
    int color[MaxVertex];
    int vNum, eNum;
} Graph;

stack<int> path;

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

// 访问结点
bool DFSTravel(Graph g, int v) {
    // 将此结点置为灰色并访问
    g.color[v] = Gray;
    // 遍历孩子
    for (size_t i = FirstNeighbor(g, v); i != -1; i = NextNeighbor(g, v, i)) {
        // 如果孩子是灰色的,则有环，返回
        if (g.color[i] == Gray) {
            return false;
        }
        // 如果孩子访问时发现环也返回失败
        if (!DFSTravel(g, i)) {
            return false;
        }
    }
    /*
        置为黑色并入栈
        上一层的for循环结束后，结点v的子孙都已在栈底
    */
    path.push(v);
    g.color[v] = Black;

    return true;
}
// 拓扑排序
bool TopoDfs(Graph g) {
    for (size_t i = 0; i < g.vNum; i++) {
        if (g.color[i] == White) {
            // 如果此连通分量存在环，则退出
            if (!DFSTravel(g, i)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
}