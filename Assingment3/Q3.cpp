#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char exp[100];
    cout << "Enter expression: ";
    cin >> exp;

    int len = strlen(exp);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = exp[i];
        if (c == '(' || c == '{' || c == '[')
            stack[++top] = c;
        else if (c == ')' || c == '}' || c == ']') {
            if (top == -1) { cout << "Not Balanced\n"; return 0; }
            char ch = stack[top--];
            if ((c == ')' && ch != '(') ||
                (c == '}' && ch != '{') ||
                (c == ']' && ch != '[')) {
                cout << "Not Balanced\n";
                return 0;
            }
        }
    }

    if (top == -1) cout << "Balanced\n";
    else cout << "Not Balanced\n";
    return 0;
}
