#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* expr) {
    char* token = strtok(expr, " ");

    while (token != NULL) {

        if (isdigit(token[0])) {
            push(atoi(token));
        }
        else {
            int b = pop();
            int a = pop();
            int res;

            switch(token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }

            push(res);
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char expr[200];

    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0;

    int result = evaluatePostfix(expr);

    printf("%d\n", result);

    return 0;
}