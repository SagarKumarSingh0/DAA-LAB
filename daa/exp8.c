#include <stdio.h>

int max(int a, int b);
void kpsk(int n, int m, int w[], int p[], int v[][100]);
void opt(int n, int m, int w[], int v[][100]);

int main() {
    int w[20], p[20], n, m, i, v[20][100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &m);

    printf("Enter the weights of elements:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Enter the profits of elements:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    kpsk(n, m, w, p, v);
    opt(n, m, w, v);

    return 0;
}

void kpsk(int n, int m, int w[], int p[], int v[][100]) {
    int i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (j < w[i])
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], p[i] + v[i - 1][j - w[i]]);
        }
    }

    // Print DP table (optional)
    printf("\nDP Table:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
}

void opt(int n, int m, int w[], int v[][100]) {
    int i = n, j = m;
    int x[20] = {0}; // To store selected items

    printf("\nThe optimal profit is: %d\n", v[n][m]);

    // Traceback to find selected items
    while (i != 0 && j != 0) {
        if (v[i][j] != v[i - 1][j]) {
            x[i] = 1;
            j = j - w[i];
        }
        i--;
    }

    printf("The items selected are: ");
    for (i = 1; i <= n; i++) {
        if (x[i] == 1)
            printf("%d ", i);
    }
    printf("\n");
}

int max(int a, int b) {
    return (a > b ? a : b);
}
