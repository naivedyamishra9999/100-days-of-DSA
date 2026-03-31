#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Search index in inorder
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct TreeNode* buildTreeUtil(int inorder[], int postorder[],
                              int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = createNode(rootVal);

    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    // build right first
    root->right = buildTreeUtil(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left  = buildTreeUtil(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

// Preorder traversal (Root -> Left -> Right)
void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct TreeNode* root = buildTreeUtil(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}