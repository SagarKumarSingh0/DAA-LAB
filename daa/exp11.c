#include <stdio.h>
#include <stdbool.h>

#define V 5  // Number of vertices in the graph

void printSolution(int path[]);

// A utility function to check if the vertex v can be added at index 'pos' in the Hamiltonian Cycle
bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    // Check if this vertex is adjacent to the previously added vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included
    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }

    return true;
}

// Recursive utility function to solve the Hamiltonian Cycle problem
bool hamCycleUtil(bool graph[V][V], int path[], int pos) {
    // Base case: all vertices are included
    if (pos == V) {
        // Check if there is an edge from the last to the first vertex
        return graph[path[pos - 1]][path[0]] == 1;
    }

    // Try different vertices as candidates for the next position
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to build the rest of the path
            if (hamCycleUtil(graph, path, pos + 1))
                return true;

            // Backtrack
            path[pos] = -1;
        }
    }

    return false;
}

// Solves the Hamiltonian Cycle problem using backtracking
bool hamCycle(bool graph[V][V]) {
    int path[V];

    // Initialize path
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Start at vertex 0
    path[0] = 0;

    if (!hamCycleUtil(graph, path, 1)) {
        printf("\nSolution does not exist\n");
        return false;
    }

    printSolution(path);
    return true;
}

// Print the solution path
void printSolution(int path[]) {
    printf("\nSolution Exists: Following is one Hamiltonian Cycle\n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);

    // Print the first vertex again to complete the cycle
    printf(" %d\n", path[0]);
}

// Main function to test the above functions
int main() {
    bool graph1[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    printf("Graph 1:\n");
    hamCycle(graph1);

    bool graph2[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    printf("\nGraph 2:\n");
    hamCycle(graph2);

    return 0;
}
