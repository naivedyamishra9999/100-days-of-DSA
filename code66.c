#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100005

int *adj[MAX];
int adjSize[MAX];
bool visited[MAX];

// DFS function
bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }
    }
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // initialize
    for (int i = 0; i < V; i++) {
        adjSize[i] = 0;
        visited[i] = false;
    }

    int edges[E][2];

    // input edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }

    // allocate exact memory
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    // build adjacency list
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    // check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}