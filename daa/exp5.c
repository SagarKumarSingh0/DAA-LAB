#include <stdio.h>

#define SIZE 20
#define TRUE 1
#define FALSE 0

int queue[SIZE], visit[SIZE], rear = -1, front = 0;
int n, s, adj[SIZE][SIZE], flag = 0;

void insertq(int v) {
    if (rear < SIZE - 1) {
        queue[++rear] = v;
    }
}

int deleteq() {
    if (front <= rear) {
        return queue[front++];
    }
    return -1;
}

int qempty() {
    return (rear < front);
}

void bfs(int v) {
    int w;
    visit[v] = 1;
    insertq(v);
    printf("v%d\t", v); // Print the start vertex

    while (!qempty()) {
        v = deleteq();
        for (w = 1; w <= n; w++) {
            if (adj[v][w] == 1 && visit[w] == 0) {
                visit[w] = 1;
                flag = 1;
                printf("v%d\t", w);
                insertq(w);
            }
        }
    }
}

int main() {
    int v, w;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (v = 1; v <= n; v++) {
        for (w = 1; w <= n; w++) {
            scanf("%d", &adj[v][w]);
        }
    }

    printf("Enter the start vertex: ");
    scanf("%d", &s);

    for (v = 1; v <= n; v++) {
        visit[v] = 0;
    }

    printf("Reachability from vertex v%d:\n", s);
    bfs(s);

    if (flag == 0) {
        printf("No path found!!\n");
    }

    return 0;
}
