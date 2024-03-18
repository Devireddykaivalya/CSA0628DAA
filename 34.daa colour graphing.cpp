#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int V;

bool isSafe(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

bool graphColoringUtil(int v, int m) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;

            if (graphColoringUtil(v + 1, m))
                return true;

            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(int m) {
    if (!graphColoringUtil(0, m)) {
        printf("Solution does not exist.\n");
        return false;
    }

    printf("Solution exists with the following coloring:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d --> Color %d\n", i, color[i]);

    return true;
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int m;
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    if (!graphColoring(m))
        printf("No solution exists.\n");

    return 0;
}
