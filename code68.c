#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Adjacency list
int adj[MAX][MAX];
int adjSize[MAX];

// Visited array
int visited[MAX];

// Stack
int stack[MAX];
int top = -1;

// DFS function
void dfs(int node) {
    visited[node] = 1;

    for(int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if(!visited[neighbor]) {
            dfs(neighbor);
        }
    }

    // Push to stack after visiting all neighbors
    stack[++top] = node;
}

// Function to perform topological sort
void topoSort(int V) {
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    // Print stack in reverse (top to bottom)
    while(top >= 0) {
        printf("%d ", stack[top--]);
    }
}

// Driver code
int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // Initialize
    for(int i = 0; i < V; i++) {
        adjSize[i] = 0;
        visited[i] = 0;
    }

    // Input edges (u -> v)
    for(int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
    }

    topoSort(V);

    return 0;
}