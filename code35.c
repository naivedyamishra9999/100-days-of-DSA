#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
}

void display() {
    if (front == -1) {
        printf("Queue is empty");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    int n, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    display();

    return 0;
}