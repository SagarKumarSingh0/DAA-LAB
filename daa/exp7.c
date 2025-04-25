#include <stdio.h>

#define INF 99
#define MAX 20

int parent[MAX], mincost = 0;

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int union_set(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int cost[MAX][MAX];
    int n, i, j, ne = 1;
    int a, b, u, v, min;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("\nThe edges in the Minimum Spanning Tree are:\n");
    while (ne < n) {
        min = INF;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (union_set(u, v)) {
            printf("%d\tEdge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost of the spanning tree = %d\n", mincost);
    return 0;
}
