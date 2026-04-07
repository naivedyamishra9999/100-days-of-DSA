#include <stdio.h>
#include <stdbool.h>

#define MAXN 1000

int graph[MAXN][MAXN];
int graphSize[MAXN];
bool visited[MAXN];
bool recStack[MAXN];

// DFS function
bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < graphSize[node]; i++) {
        int neighbor = graph[node][i];

        // If not visited, recurse
        if (!visited[neighbor]) {
            if (dfs(neighbor))
                return true;
        }
        // If already in recursion stack → cycle
        else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    // Initialize
    for (int i = 0; i < n; i++) {
        graphSize[i] = 0;
        visited[i] = false;
        recStack[i] = false;
    }

    // Input edges (directed)
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][graphSize[u]++] = v;
    }

    // Check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}