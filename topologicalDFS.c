#include <stdio.h>

int i, visit[20], n, adj[20][20], topo_order[20];

void dfs(int v) {
    int w;
    visit[v] = 1;
    for (w = 1; w <= n; w++) {
        if (adj[v][w] == 1 && visit[w] == 0)
            dfs(w);
    }
    topo_order[i--] = v;
}

int main() {
    int v, w;

    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (v = 1; v <= n; v++) {
        for (w = 1; w <= n; w++) {
            scanf("%d", &adj[v][w]);
        }
    }

    for (v = 1; v <= n; v++)
        visit[v] = 0;

    i = n;

    for (v = 1; v <= n; v++) {
        if (visit[v] == 0)
            dfs(v);
    }

    printf("\nTopological sorting is: ");
    for (v = 1; v <= n; v++) {
        printf("v%d ", topo_order[v]);
    }

    return 0;
}