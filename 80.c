//  You are given an undirected graph with N nodes (numbered 1 through N).
// For each valid i, the i-th node has a weight Wi. Also, for each pair of nodes i and
// j, there is an edge connecting nodes if j – i ≠ Wj - Wi.
// Find the number of connected components in this graph



#include <stdio.h>
#include <stdlib.h>

int parent[200005];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    int x = find(a);
    int y = find(b);

    if (x != y)
        parent[x] = y;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        long long W[200005];

        for (int i = 1; i <= N; i++) {
            scanf("%lld", &W[i]);
            parent[i] = i;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                if (W[j] - W[i] == i ||
                    W[i] - W[j] == j) {
                    unite(i, j);
                }
            }
        }

        int components = 0;

        for (int i = 1; i <= N; i++) {
            if (find(i) == i)
                components++;
        }

        printf("%d\n", components);
    }

    return 0;
}
