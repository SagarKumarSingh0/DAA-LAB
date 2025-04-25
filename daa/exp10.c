#include <stdio.h>

#define MAX 20
#define INF 9999

int a[MAX][MAX], dis[MAX], s[MAX], i, j;

void dij(int v, int n);
int min(int n);

int main() {
    int v, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (use %d for no connection):\n", INF);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &v);

    dij(v, n);

    printf("\nShortest distances from vertex %d:\n", v);
    for (i = 1; i <= n; i++) {
        printf("From %d to %d is %d\n", v, i, dis[i]);
    }

    return 0;
}

void dij(int v, int n) {
    int u, w;

    // Initialize distances and visited array
    for (i = 1; i <= n; i++) {
        dis[i] = a[v][i];
        s[i] = 0;
    }

    s[v] = 1;
    dis[v] = 0;

    for (i = 2; i <= n; i++) {
        u = min(n);
        s[u] = 1;

        for (w = 1; w <= n; w++) {
            if (!s[w] && dis[w] > dis[u] + a[u][w]) {
                dis[w] = dis[u] + a[u][w];
            }
        }
    }
}

int min(int n) {
    int i, p = -1, minimum = INF;

    for (i = 1; i <= n; i++) {
        if (dis[i] < minimum && s[i] == 0) {
            minimum = dis[i];
            p = i;
        }
    }

    return p;
}
