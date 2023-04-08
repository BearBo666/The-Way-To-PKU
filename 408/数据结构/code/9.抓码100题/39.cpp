/*
    题目：图的非递归dfs
*/

#define MaxSize 100
typedef struct Graph {
    int data[MaxSize][MaxSize];
    int vNum, eNum;
} Graph;

bool visited[MaxSize];
void DFS(Graph& g) {
    int stack[MaxSize], top = -1;

    stack[++top] = 0;  // 0号结点入栈
    // 栈非空
    while (top != -1) {
        // 出栈
        int elm = stack[top--];
        visited[elm] = true;
        for (size_t i = 0; i < g.vNum; i++) {
            if (g.data[elm][i] && !visited[i]) {
                stack[++top] = i;
            }
        }
    }
}