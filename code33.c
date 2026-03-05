#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main() {

    char infix[MAX], postfix[MAX];
    int i, j = 0;

    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {

        char ch = infix[i];

        // Operand
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        // Left parenthesis
        else if (ch == '(') {
            push(ch);
        }

        // Right parenthesis
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }

        // Operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}