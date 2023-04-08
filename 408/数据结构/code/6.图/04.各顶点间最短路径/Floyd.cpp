/*
    邻接矩阵实现Floyd算法
    空间复杂度：O(v^2)  两个2维数组分别表示两点间最短路径、路径上的前驱
    时间复杂度：O(v^3) 重复v次，每次要遍历整个图
*/
#include <iostream>
#include <vector>

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
// Floyd算法
vector<vector<int>> Floyd(Graph g) {
    vector<vector<int>> paths(g.vNum, vector<int>(g.vNum));
    vector<vector<int>> distance(g.vNum, vector<int>(g.vNum));
    // 初始化路径 paths[i][j]代表i到j的路径上,j的前一个结点
    for (size_t i = 0; i < g.vNum; i++) {
        for (size_t j = 0; j < g.vNum; j++) {
            paths[i][j] = -1;
        }
    }

    // 将第k个点添加为中转
    for (size_t k = 0; k < g.vNum; k++) {
        // 遍历所有的两个点
        for (size_t i = 0; i < g.vNum; i++) {
            for (size_t j = 0; j < g.vNum; j++) {
                // 将第k个结点作为中转
                if (g.edge[i][k] != M && g.edge[k][j] != M) {
                    int newDistance = distance[i][k] + distance[k][j];
                    // 判断通过该结点作为中转、和不用该节点做中转的距离大小
                    if (newDistance < distance[i][j]) {
                        distance[i][j] = newDistance;
                        paths[i][j] = k;
                    }
                }
            }
        }
    }
}

int main() {
}