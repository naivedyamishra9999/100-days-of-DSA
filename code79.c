#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100005

typedef struct {
    int node;
    int weight;
} Pair;

typedef struct {
    Pair heap[MAX];
    int size;
} MinHeap;

// Swap function
void swap(Pair *a, Pair *b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(MinHeap *h, int i) {
    while (i > 0 && h->heap[(i - 1) / 2].weight > h->heap[i].weight) {
        swap(&h->heap[(i - 1) / 2], &h->heap[i]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(MinHeap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->heap[left].weight < h->heap[smallest].weight)
        smallest = left;

    if (right < h->size && h->heap[right].weight < h->heap[smallest].weight)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

// Push into heap
void push(MinHeap *h, int node, int weight) {
    h->heap[h->size].node = node;
    h->heap[h->size].weight = weight;
    h->size++;
    heapifyUp(h, h->size - 1);
}

// Pop min
Pair pop(MinHeap *h) {
    Pair root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Adjacency list
    int adj[MAX][2]; // not used directly (we'll use dynamic list)
    int *graph[n + 1];
    int size[n + 1];

    for (int i = 1; i <= n; i++) {
        graph[i] = malloc(2 * m * sizeof(int));
        size[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][size[u]++] = v;
        graph[u][size[u]++] = w;

        graph[v][size[v]++] = u;
        graph[v][size[v]++] = w;
    }

    bool visited[n + 1];
    for (int i = 1; i <= n; i++) visited[i] = false;

    MinHeap heap;
    heap.size = 0;

    // Start from node 1
    push(&heap, 1, 0);

    int totalWeight = 0;

    while (heap.size > 0) {
        Pair p = pop(&heap);
        int u = p.node;
        int w = p.weight;

        if (visited[u]) continue;

        visited[u] = true;
        totalWeight += w;

        for (int i = 0; i < size[u]; i += 2) {
            int v = graph[u][i];
            int weight = graph[u][i + 1];

            if (!visited[v]) {
                push(&heap, v, weight);
            }
        }
    }

    printf("%d\n", totalWeight);
    return 0;
}