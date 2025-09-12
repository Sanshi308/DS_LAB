#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char exp[100];
    cout << "Enter postfix expression: ";
    cin >> exp;

    int len = strlen(exp);
    int stack[len], top = -1;

    for (int i = 0; i < len; i++) {
        char c = exp[i];
        if (isdigit(c))
            stack[++top] = c - '0';
        else {
            int val2 = stack[top--];
            int val1 = stack[top--];
            switch (c) {
            case '+': stack[++top] = val1 + val2; break;
            case '-': stack[++top] = val1 - val2; break;
            case '*': stack[++top] = val1 * val2; break;
            case '/': stack[++top] = val1 / val2; break;
            }
        }
    }

    cout << "Result: " << stack[top] << endl;
    return 0;
}
