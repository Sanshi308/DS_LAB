Write a program to convert an Infix expression into a Postfix expression.

#include <iostream>
#include <cstring>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

int main() {
    char exp[100];
    cout << "Enter infix expression: ";
    cin >> exp;

    int len = strlen(exp);
    char stack[len], postfix[len];
    int top = -1, k = 0;

    for (int i = 0; i < len; i++) {
        char c = exp[i];
        if (isalnum(c))
            postfix[k++] = c;
        else if (c == '(')
            stack[++top] = c;
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = stack[top--];
            top--; // remove '('
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[k++] = stack[top--];
            stack[++top] = c;
        }
    }

    while (top != -1)
        postfix[k++] = stack[top--];

    postfix[k] = '\0';
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
