#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for tree nodes
struct Queue {
    struct TreeNode* data[2000];
    int front, rear;
};

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->data[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->data[q->front++];
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = createNode(arr[0]);
    struct Queue q = { .front = 0, .rear = 0 };

    enqueue(&q, root);
    int i = 1;

    while (i < n) {
        struct TreeNode* curr = dequeue(&q);

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzagTraversal(struct TreeNode* root) {
    if (!root) return;

    struct Queue q = { .front = 0, .rear = 0 };
    enqueue(&q, root);

    int level = 0;

    while (q.front < q.rear) {
        int size = q.rear - q.front;
        int temp[2000];

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(&q);

            int index = (level % 2 == 0) ? i : (size - 1 - i);
            temp[index] = node->val;

            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }

        // Print current level
        for (int i = 0; i < size; i++) {
            printf("%d ", temp[i]);
        }

        level++;
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}