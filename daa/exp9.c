#include <stdio.h>

#define INF 999

int a[10][10], visited[10], n, cost = 0;

void get() {
    int i, j;
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("\nEnter Cost Matrix:\n");
    for (i = 0; i < n; i++) {
        printf("Enter elements of row #%d:\n", i + 1);
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
        visited[i] = 0;
    }

    printf("\nThe cost matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

int least(int c) {
    int i, nc = INF, min = INF;

    for (i = 0; i < n; i++) {
        if (a[c][i] != 0 && visited[i] == 0) {
            if ((a[c][i] + a[i][0]) < min) {
                min = a[c][i] + a[i][0];
                nc = i;
            }
        }
    }

    if (min != INF) {
        cost += a[c][nc];
    }

    return nc;
}

void mincost(int city) {
    int ncity;
    visited[city] = 1;

    printf("%d --> ", city + 1);
    ncity = least(city);

    if (ncity == INF) {
        ncity = 0;
        printf("%d", ncity + 1);
        cost += a[city][ncity];
        return;
    }

    mincost(ncity);
}

void put() {
    printf("\n\nMinimum cost: %d\n", cost);
}

int main() {
    get();
    printf("\nThe Path is:\n");
    mincost(0);
    put();
    return 0;
}
