/*
    题目：求不带权无向图中到某点最远的结点，以及经历的边数
*/
#include <queue>
using namespace std;

#define MaxSize 100
typedef struct Graph {
    int data[MaxSize][MaxSize];
    int vNum, eNum;
} Graph;

bool visited[MaxSize];
int maxNode(Graph& g, int start) {
    queue<int> q, queue<int> nextLevel;

    int k = 0, elm, lastKid;
    q.push(start);
    while (!q.empty()) {
        elm = q.front();
        q.pop();

        for (size_t i = 0; i < g.vNum; i++) {
            if (g.data[elm][i] && !visited[i]) {
                nextLevel.push(i);  // 下一层结点入栈
                // 记录下本层的的最后一个孩子
                lastKid = i;
            }
        }
        // 如果取完了一层结点
        if (q.empty()) {
            q = nextLevel;
            k++;
        }
    }
    // k为层数，lastKid为最后一层的最后一个结点
    return k;
}