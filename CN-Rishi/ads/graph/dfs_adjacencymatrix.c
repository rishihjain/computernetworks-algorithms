#include <stdio.h>

void DFS(int);
int G[10][10], visited[10], n;

int main() {
    int i, j, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix of the graph:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("\nEnter the starting vertex for Depth-First Traversal: ");
    scanf("%d", &startVertex);

    printf("\nDepth-First Traversal starting from vertex %d:\n", startVertex);
    DFS(startVertex);

    return 0;
}

void DFS(int i) {
    int j;
    printf("%d ", i);
    visited[i] = 1;
    for (j = 0; j < n; j++) {
        if (!visited[j] && G[i][j] == 1) {
            DFS(j);
        }
    }
}
