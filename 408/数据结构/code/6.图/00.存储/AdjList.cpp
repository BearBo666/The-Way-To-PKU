/*
    邻接表存储
    空间：O(v+e)【有向图】  O(v+2e)【无向图】
*/
#include <iostream>

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
        if (p->adjvex == y) {
            return p->next == NULL ? -1 : p->next->adjvex;
        }
        p = p->next;
    }
    return -1;
}

int main() {
    AdjList graph;
    InitGraph(graph);
    int x = FirstNeighbor(graph, 0);
    cout << "the first neighbor of node0 is:" << x << endl;
    x = NextNeighbor(graph, 0, x);
    cout << "the next neighbor of node0 is:" << x << endl;
    x = NextNeighbor(graph, 0, x);
    cout << "the next neighbor of node0 is:" << x << endl;
}