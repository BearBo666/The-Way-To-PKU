/*
    题目：判断图中是否存在i到j的路径
*/

#define MaxSize 100
typedef struct Graph {
    int data[MaxSize][MaxSize];
    int vNum, eNum;
} Graph;

bool visited[MaxSize];
bool existPath(Graph& g, int i, int j) {
    DFS(g, i);

    return visited[j];
}

void DFS(Graph& g, int start) {
    visited[start];

    for (size_t i = 0; i < g.vNum; i++) {
        if (g.data[start][i] && !visited[i]) {
            DFS(g, i);
        }
    }
}