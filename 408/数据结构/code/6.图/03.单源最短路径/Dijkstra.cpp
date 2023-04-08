/*
    邻接矩阵实现Dijkstra算法
    空间复杂度：O(v)    两个1维数组，分别表示最短路径，路径上的前驱
    时间复杂度：O(v^2)  遍历v次，每次找到到达起点距离最小的点
*/
#include <iostream>
#include <stack>
#include <vector>

#define M 2147483647
#define MaxVertex 100

using namespace std;

// 邻接矩阵
typedef struct Graph {
    int edge[MaxVertex][MaxVertex];
    int vNum, eNum;
} Graph;

// 初始化邻接矩阵
void InitGraph(Graph& g) {
    int N = 5;
    int mock[5][5] = {
        {0, 10, M, M, 5},
        {M, 0, 1, M, 2},
        {M, M, 0, 4, M},
        {7, M, 6, 0, M},
        {M, 3, 9, 2, 0},
    };
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            g.edge[i][j] = mock[i][j];
        }
    }
    g.vNum = N;
    g.eNum = 10;
}
int Min(int a, int b) {
    return a < b ? a : b;
}

// 迪杰斯特拉算法
vector<int> Dijkstra(int start, Graph g) {
    // 初始化
    vector<bool> visit(g.vNum);  // 是否已访问过
    vector<int> dist(g.vNum);    // 起点到各点的距离
    vector<int> pre(g.vNum);     // 路径前驱
    fill(visit.begin(), visit.end(), false);
    fill(dist.begin(), dist.end(), M);
    fill(pre.begin(), pre.end(), -1);
    visit[start] = true;
    dist[start] = 0;
    // 到各点的距离初始置为图中的距离
    for (size_t i = 0; i < g.vNum; i++) {
        dist[i] = g.edge[start][i];
        if (dist[i] != M) {
            pre[i] = start;
        }
    }

    /*
     n-1次循环
     每次找到一个：未visit且到起点dist最小的结点
    */
    for (size_t i = 0; i < g.vNum - 1; i++) {
        // 找到距离集合S中的点距离最短的顶点
        int minVetex = -1;
        for (size_t j = 0, MinDistance = M; j < g.vNum; j++) {
            // 如果没有访问这个结点 且 到其路径长度更短
            if (!visit[j] && dist[j] < MinDistance) {
                minVetex = j;
            }
        }
        // 找不到了就返回
        if (minVetex == -1) {
            return pre;
        }
        // 找到了，将该结点加入集合
        visit[minVetex] = true;
        // 重新计算到达T各顶点的距离
        for (size_t j = 0; j < g.vNum; j++) {
            // 如果新顶点可达该顶点
            if (!visit[j] && g.edge[minVetex][j] != M) {
                dist[j] = Min(dist[j], dist[minVetex] + g.edge[minVetex][j]);
            }
        }
    }
    return pre;
}
// 检验两点间的最短路径
void Test(Graph g) {
    int start, end, p;
    stack<int> stack;

    cout << "Input the start:";
    cin >> start;

    vector<int> pre = Dijkstra(start, g);
    cout << "Input the end:";
    cin >> end;

    cout << "The shorest path is:";
    for (size_t i = end; i != start && i != -1; i = pre[i]) {
        stack.push(i);
    }
    stack.push(start);

    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
}

int main() {
    Graph g;
    InitGraph(g);
    Test(g);

    return 0;
}