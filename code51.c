#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Search in BST
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);

    return searchBST(root->right, val);
}

// Inorder traversal (to print subtree)
void inorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Main function
int main() {
    struct TreeNode* root = NULL;
    int n, val, x;

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input BST values
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    // Value to search
    printf("Enter value to search: ");
    scanf("%d", &val);

    struct TreeNode* result = searchBST(root, val);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("Subtree (inorder): ");
        inorder(result);
    }

    return 0;
}