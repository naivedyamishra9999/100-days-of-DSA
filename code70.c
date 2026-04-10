#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Adjacency list node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Graph
Node* adj[MAX];

// Min Heap Node
typedef struct {
    int vertex;
    int dist;
} HeapNode;

HeapNode heap[1000];
int heapSize = 0;

// Swap
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Push into heap
void push(HeapNode val) {
    heap[++heapSize] = val;
    int i = heapSize;

    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

// Pop from heap
HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while (1) {
        int smallest = i;
        int left = 2*i;
        int right = 2*i + 1;

        if (left <= heapSize && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if (right <= heapSize && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest == i) break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return top;
}

// Add edge
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra function
void dijkstra(int n, int source) {
    int dist[MAX];

    // Initialize distances
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    heapSize = 0;
    push((HeapNode){source, 0});

    while (heapSize > 0) {
        HeapNode curr = pop();
        int u = curr.vertex;
        int d = curr.dist;

        if (d > dist[u]) continue;

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                push((HeapNode){v, dist[v]});
            }

            temp = temp->next;
        }
    }

    // Print result
    printf("Shortest distances from node %d:\n", source);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("Node %d : INF\n", i);
        else
            printf("Node %d : %d\n", i, dist[i]);
    }
}

// Driver code
int main() {
    int n = 5;

    // Initialize graph
    for (int i = 0; i < MAX; i++)
        adj[i] = NULL;

    // Example graph
    addEdge(1, 2, 2);
    addEdge(1, 3, 4);
    addEdge(2, 3, 1);
    addEdge(2, 4, 7);
    addEdge(3, 5, 3);
    addEdge(4, 5, 1);

    int source = 1;

    dijkstra(n, source);

    return 0;
}