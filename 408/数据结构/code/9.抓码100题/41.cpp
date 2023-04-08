/*
    题目：不带权无向图两点间最短路径
*/

#define MaxSize 100
typedef struct Graph {
    int data[MaxSize][MaxSize];
    int vNum, eNum;
} Graph;

int path[MaxSize];  // 记录前驱结点
bool visited[MaxSize];
void minPath(Graph& g, int i, int j) {
    // 初始化队列
    int queue[MaxSize], front = 0, rear = 0;
    // 第一个节点入队
    queue[rear++] = i;
    // 队列只要非空
    while (front != rear) {
        int elm = queue[front++];
        visited[elm] = true;
        for (size_t i = 0; i < g.vNum; i++) {
            if (g.data[elm][i] && !visited[i]) {
                queue[rear++] = i;
                path[elm];  // 记录前驱
            }
        }
    }
}