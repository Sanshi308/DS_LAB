#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter stack size: ";
    cin >> n;

    int stack[n], top = -1;

    int choice, val;
    do {
        cout << "\n1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: 
            if (top == n - 1)
                cout << "Stack Overflow!\n";
            else {
                cout << "Enter value: ";
                cin >> val;
                stack[++top] = val;
                cout << val << " pushed\n";
            }
            break;

        case 2:
            if (top == -1) cout << "Stack Underflow!\n";
            else cout << stack[top--] << " popped\n";
            break;

        case 3: 
            cout << (top == -1 ? "Stack is Empty\n" : "Not Empty\n"); 
            break;

        case 4: 
            cout << (top == n - 1 ? "Stack is Full\n" : "Not Full\n"); 
            break;

        case 5:
            if (top == -1) cout << "Stack Empty\n";
            else {
                cout << "Stack elements: ";
                for (int i = 0; i <= top; i++) cout << stack[i] << " ";
                cout << endl;
            }
            break;

        case 6:
            if (top == -1) cout << "Stack Empty\n";
            else cout << "Top element: " << stack[top] << endl;
            break;

        case 7: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
