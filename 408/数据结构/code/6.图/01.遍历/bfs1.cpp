/*
    邻接表bfs
    空间复杂度：O(v)   辅助队列、辅助数组
    时间复杂度：O(v+e) 遍历了一遍邻接表
*/
#include <iostream>
#include <queue>

#define VertextNum 5
#define M 2147483647

using namespace std;

// 边结点
typedef struct ArcNode {
    int adjvex;  // 顶点号
    int weight;  // 权重
    struct ArcNode* next;
} ArcNode;
// 点结点
typedef struct VNode {
    int data;
    ArcNode* first;  // 第一条边
} VNode, AdjList[VertextNum];

// 边构造
void GeneEdge(VNode* graph, int x, int y, int weight) {
    ArcNode* edge1 = (ArcNode*)malloc(sizeof(ArcNode));

    edge1->adjvex = y;
    edge1->weight = weight;
    // 头插法插入边
    edge1->next = graph[x].first;
    graph[x].first = edge1;
}
// 初始化矩阵
void InitGraph(VNode* graph) {
    int mock[VertextNum][VertextNum] = {
        {0, 10, M, M, 5},  // 0->1 0->4
        {M, 0, 1, M, 2},   // 1->2 1->4
        {M, M, 0, 4, M},   // 2->3
        {7, M, 6, 0, M},   // 3->1 3->2
        {M, 3, 9, 2, 0},   // 4->1 4->2 4->3
    };

    for (size_t i = 0; i < VertextNum; i++) {
        for (size_t j = 0; j < VertextNum; j++) {
            if (mock[i][j] != M && i != j) {
                GeneEdge(graph, i, j, mock[i][j]);
            }
        }
    }
}
// 找到第一个邻居的顶点号
int FirstNeighbor(VNode* graph, int x) {
    if (x < 0 || x >= VertextNum) {
        return -1;
    }
    return graph[x].first == NULL ? -1 : graph[x].first->adjvex;
}
// 找到下一个邻居
int NextNeighbor(VNode* graph, int x, int y) {
    ArcNode* p = graph[x].first;
    while (p != NULL) {
        // 找到指定邻居了
        if (p->adjvex == y) {
            // 根据后面有无邻居返回不同结果
            return p->next == NULL ? -1 : p->next->adjvex;
        }
        p = p->next;
    }
    return -1;
}

// 从结点v开始广度优先遍历
void BFSTraverse(VNode* graph, int v, bool* visited) {
    queue<int> q;
    ArcNode* p;

    q.push(v);
    while (!q.empty()) {
        // 队头元素出队并被访问
        v = q.front(), q.pop();
        visited[v] = true;
        cout << v << " ";
        // 将其未被访问的邻居入队
        p = graph[v].first;
        while (p != NULL) {
            if (!visited[p->adjvex]) {
                q.push(p->adjvex);
                visited[p->adjvex] = true;
            }
            p = p->next;
        }
    }
}
// 对整个图进行广度优先遍历
void BFS(VNode* graph) {
    bool visited[VertextNum];
    for (size_t i = 0; i < VertextNum; i++) {
        visited[i] = false;
    }

    // 从0号结点开始bfs
    int count = 0;
    for (size_t i = 0; i < VertextNum; i++) {
        if (!visited[i]) {
            BFSTraverse(graph, i, visited);
            count++;  // 统计连通分量
        }
    }
    cout << endl;
    cout << "bfs over:" << count << endl;
}

int main() {
    AdjList graph;
    InitGraph(graph);
    BFS(graph);
}