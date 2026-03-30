#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int preorder[], int inorder[],
                       int preStart, int preEnd,
                       int inStart, int inEnd) {

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    int rootVal = preorder[preStart];
    struct Node* root = newNode(rootVal);

    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);
    int leftSize = inIndex - inStart;

    root->left = buildTree(preorder, inorder,
                           preStart + 1, preStart + leftSize,
                           inStart, inIndex - 1);

    root->right = buildTree(preorder, inorder,
                            preStart + leftSize + 1, preEnd,
                            inIndex + 1, inEnd);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = buildTree(preorder, inorder,
                                 0, n - 1,
                                 0, n - 1);

    postorder(root);

    return 0;
}