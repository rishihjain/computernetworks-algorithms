#include <stdio.h>

int n, i, j, visited[10], queue[10], front = -1, rear = -1;
int adj[10][10];

void bfs(int v)
{
    for (i = 1; i <= n; i++)
        if (adj[v][i] && !visited[i])
            queue[++rear] = i;
    if (front <= rear)
    {
        visited[queue[front]] = 1;
        bfs(queue[front++]);
    }
}

void main()
{
    int v;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);  // Fix: Use n instead of v

    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
        queue[i] = 0;
    }

    printf("Enter graph data in matrix form:    \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    bfs(v);

    printf("The nodes which are reachable are :\n");
    for (i = 1; i <= n; i++)
        if (visited[i])
            printf("%d->", i);
    else
        printf("BFS is not possible, not all nodes are reachable\n");
}
