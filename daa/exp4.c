#include <stdio.h>

int visit[20], adj[20][20], n, count = 0;

void dfs(int v) {
    int w;
    visit[v] = 1;
    count++;

    for (w = 1; w <= n; w++) {
        if (adj[v][w] == 1 && visit[w] == 0) {
            dfs(w);
        }
    }
}

int main() {
    int v, w;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (v = 1; v <= n; v++) {
        for (w = 1; w <= n; w++) {
            scanf("%d", &adj[v][w]);
        }
    }

    // Initialize visit array
    for (v = 1; v <= n; v++) {
        visit[v] = 0;
    }

    // Perform DFS starting from vertex 1
    dfs(1);

    if (count == n)
        printf("\nThe graph is connected.\n");
    else
        printf("\nThe graph is not connected.\n");

    return 0;
}
