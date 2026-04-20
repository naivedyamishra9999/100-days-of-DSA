#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

// Adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Graph
struct Node* adj[MAX];

// Min heap structure
struct HeapNode {
    int vertex;
    int dist;
};

struct HeapNode heap[MAX];
int size = 0;

// Swap
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[(i-1)/2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert into heap
void push(int v, int d) {
    heap[size].vertex = v;
    heap[size].dist = d;
    heapifyUp(size);
    size++;
}

// Extract min
struct HeapNode pop() {
    struct HeapNode root = heap[0];
    heap[0] = heap[size-1];
    size--;
    heapifyDown(0);
    return root;
}

// Add edge
void addEdge(int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra
void dijkstra(int n, int src) {
    int dist[MAX];
    
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        struct HeapNode temp = pop();
        int u = temp.vertex;

        struct Node* curr = adj[u];
        while (curr != NULL) {
            int v = curr->vertex;
            int w = curr->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            curr = curr->next;
        }
    }

    // Print result
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < MAX; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        // If undirected, also add reverse:
        // addEdge(v, u, w);
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}