#include <stdio.h>

#define INF 99
#define MAX 20

int Prim(int g[MAX][MAX], int n, int t[MAX][MAX]) {
    int u, v, min, mincost = 0;
    int visited[MAX] = {0};
    int i, j, k;

    visited[1] = 1;

    for (k = 1; k < n; k++) {
        min = INF;
        u = v = 0;

        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && g[i][j] < min) {
                        min = g[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != 0 && v != 0) {
            t[u][v] = t[v][u] = g[u][v];
            mincost += g[u][v];
            visited[v] = 1;

            printf("\nEdge (%d, %d) with cost = %d", u, v, g[u][v]);

            // Optional: set g[u][v] = g[v][u] = INF to prevent re-use
            g[u][v] = g[v][u] = INF;
        }
    }

    return mincost;
}

int main() {
    int n, cost[MAX][MAX], t[MAX][MAX];
    int mincost, i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (0 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    // Initialize the MST matrix
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            t[i][j] = INF;
        }
    }

    printf("\nOrder of insertion of edges in MST:");
    mincost = Prim(cost, n, t);

    printf("\n\nMinimum cost of spanning tree = %d\n", mincost);
    return 0;
}
