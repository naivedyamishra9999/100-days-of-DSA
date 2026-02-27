#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Calculate length
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection (by value as per example)
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if (len1 > len2) {
        while (diff--)
            ptr1 = ptr1->next;
    } else {
        while (diff--)
            ptr2 = ptr2->next;
    }

    // Traverse together
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data)
            return ptr1->data;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;  // No intersection
}

int main() {
    int n, m, x;
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* newNode = createNode(x);
        if (head1 == NULL) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        struct Node* newNode = createNode(x);
        if (head2 == NULL) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}