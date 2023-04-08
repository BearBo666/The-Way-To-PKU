/*
    邻接表实现拓扑排序：
        空间复杂度：O(v)   辅助队列/栈均可
        时间复杂度：O(v+e) 相当于遍历一遍图
    邻接矩阵实现拓扑排序：
        时间复杂度：O(v^2)
*/
#include <iostream>
#include <stack>

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
typedef struct Graph {
    AdjList vertices;
    int inDegree[VertextNum];
} Graph;

// 边构造
void GeneEdge(Graph graph, int x, int y, int weight) {
    ArcNode* edge1 = (ArcNode*)malloc(sizeof(ArcNode));

    edge1->adjvex = y;
    edge1->weight = weight;
    // 头插法插入边
    edge1->next = graph.vertices[x].first;
    graph.vertices[x].first = edge1;
    // y的入度加1
    graph.inDegree[y]++;
}
// 初始化矩阵
void InitGraph(Graph g) {
    int mock[VertextNum][VertextNum] = {
        {0, 10, M, M, 5},  // 0->1 0->4
        {M, 0, 1, M, 2},   // 1->2 1->4
        {M, M, 0, 4, M},   // 2->3
        {7, M, 6, 0, M},   // 3->1 3->2
        {M, 3, 9, 2, 0},   // 4->1 4->2 4->3
    };
    for (size_t i = 0; i < VertextNum; i++) {
        g.inDegree[i] = 0;
    }

    for (size_t i = 0; i < VertextNum; i++) {
        for (size_t j = 0; j < VertextNum; j++) {
            if (mock[i][j] != M && i != j) {
                GeneEdge(g, i, j, mock[i][j]);
            }
        }
    }
}

bool TopologicalSort(Graph g) {
    stack<int> s;
    // 将入度为0的结点压入栈中
    for (size_t i = 0; i < VertextNum; i++) {
        if (g.inDegree[i] == 0) {
            s.push(i);
        }
    }

    int count = 0, v;
    while (!s.empty()) {
        v = s.top(), s.pop();
        cout << v << " ";
        count++;  // 对已输出顶点进行计数
        // 对输出的顶点入度进行减一
        for (ArcNode* p = g.vertices[v].first; p != NULL; p = p->next) {
            // 入度变成0了，入栈
            if (--g.inDegree[p->adjvex] == 0) {
                s.push(p->adjvex);
            }
        }
    }

    // 如果还有顶点未遍历，则存在环
    if (count < VertextNum) {
        return false;
    }
    return true;
}

int main() {
    Graph g;
    InitGraph(g);
}