/*
    题目：找到无向图中两点之间长度为k的路径条数
*/

#define MaxSize 100
typedef struct Graph {
    int data[MaxSize][MaxSize];
    int vNum, eNum;
} Graph;

bool visited[MaxSize];
int existKPath(Graph& g, int start, int end, int k, int dis) {
    // 如果找到
    if (start == end) {
        return dis == k ? 1 : 0;
    }
    // 统计从此邻接点到终点的所有路径长度为k的个数
    int sum = 0;
    visited[start] = true;
    for (size_t i = 0; i < g.vNum; i++) {
        if (g.data[start][i] && !visited[i]) {
            sum += existKPath(g, i, end, k, dis + 1);
        }
    }
    // 回溯
    visited[start] = false;
    return sum;
}