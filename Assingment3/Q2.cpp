#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    int len = strlen(str);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++)
        stack[++top] = str[i];

    cout << "Reversed string: ";
    while (top != -1)
        cout << stack[top--];
    cout << endl;

    return 0;
}
