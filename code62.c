#include <stdio.h>

int main() {
    int n, m;
    
    // Input number of vertices and edges
    scanf("%d", &n);
    scanf("%d", &m);

    // Create adjacency matrix and initialize with 0
    int adj[n][n];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int u, v;

    // Input edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Assuming vertices are 0-based indexed
        adj[u][v] = 1;

        // Uncomment below line for undirected graph
        // adj[v][u] = 1;
    }

    // Print adjacency matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}