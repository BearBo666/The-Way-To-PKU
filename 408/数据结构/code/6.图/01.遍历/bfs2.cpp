/*
    邻接矩阵bfs
    空间复杂度：O(v)   辅助队列、辅助数组
    时间复杂度：O(v^2) 遍历了一遍邻接矩阵
*/
#include <iostream>
#include <queue>

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

// 从顶点v开始遍历
void BFSTraverse(Graph g, int v, bool* visited) {
    queue<int> q;
    q.push(v);

    while (!q.empty()) {
        // 拿到队头元素并访问
        v = q.front(), q.pop();
        visited[v] = true;
        // 将其未被访问的邻居入队
        for (int i = FirstNeighbor(g, v); i != -1; i = NextNeighbor(g, v, i)) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
// 对整个图进行广度优先遍历
void BFS(Graph g) {
    bool* visited = (bool*)malloc(sizeof(bool) * g.vNum);
    for (size_t i = 0; i < g.vNum; i++) {
        visited[i] = false;
    }

    // 从0号结点开始bfs
    int count = 0;
    for (size_t i = 0; i < g.vNum; i++) {
        if (!visited[i]) {
            BFSTraverse(g, i, visited);
            count++;  // 统计连通分量
        }
    }
    cout << endl;
    cout << "bfs over:" << count << endl;
}

int main() {
}