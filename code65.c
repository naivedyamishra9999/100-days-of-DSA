#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

// Check if empty
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// Enqueue
void enqueue(Queue *q, int value) {
    q->items[q->rear++] = value;
}

// Dequeue
int dequeue(Queue *q) {
    return q->items[q->front++];
}

// BFS function
void BFS(int adj[MAX][MAX], int n, int s) {
    int visited[MAX] = {0};
    Queue q;

    initQueue(&q);

    visited[s] = 1;
    enqueue(&q, s);

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}

// Driver code
int main() {
    int n, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    printf("BFS Traversal: ");
    BFS(adj, n, s);

    return 0;
}