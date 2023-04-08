#define Size 100

int UFSets[Size];

void Initial(int S[]) {
    for (int i = 0; i < Size; i++) {
        S[i] = -1;
    }
}

// 查：寻找元素的根(原始版) O(h)，树高，最坏树高n
int Find(int S[], int x) {
    while (S[x] > 0) {
        x = S[x];
    }
    return x;
}

// 并：合并集合(原始版) O(n^2)，n个独立元素通过多次合并
void Union(int S[], int root1, int root2) {
    if (root1 == root2)
        return;
    S[root2] = root1;
}

// 查：寻找元素的根(改进版,路径压缩)  O(h)，最坏树高为α(n)
int Find1(int S[], int x) {
    // 先查出根
    int root = x;
    while (S[x] > 0) {
        root = S[root];
    }
    // 将查找路径上的结点都压缩到根结点上
    while (x != root) {
        int t = S[x];  // 先保存x的原始父结点
        S[x] = root;   // x的父节点指向根
        x = t;         // x指向其原始父节点,即对其父结点也挂到根
    }

    return x;
}

// 并：合并集合(改进版,小树并大树)  O(nα)，n乘以树高，压缩路径时树高为α(n)
void Union1(int S[], int root1, int root2) {
    if (root1 == root2)
        return;
    // root结点里的负数不再仅是-1，表示其树上结点个数的相反数
    if (S[root1] > S[root2]) {  // 对于负数，更大表示其结点个数更小
        // root1结点更少
        S[root2] += S[root1];  // 将root1并到root2
        S[root1] = root2;
    } else {
        // root2结点更少
        S[root1] += S[root2];  // 将root2并到root1
        S[root2] = root1;
    }
}