1) Develop a menu driven program demonstrating the following operations on simple
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear, size;
public:
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }
    bool isEmpty() { return front == -1; }
    bool isFull() { return (rear + 1) % size == front; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Overflow!\n"; return; }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = x;
    }
    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow!\n"; return; }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % size;
    }
    void peek() {
        if (isEmpty()) cout << "Queue Empty\n";
        else cout << "Front: " << arr[front] << endl;
    }
    void display() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        cout << "Queue: ";
        for (int i = front; i != rear; i = (i + 1) % size)
            cout << arr[i] << " ";
        cout << arr[rear] << endl;
    }
};

int main() {
    int n, choice, val;
    cout << "Enter queue size: ";
    cin >> n;
    Queue q(n);

    do {
        cout << "\n1.Enqueue  2.Dequeue  3.Display  4.Peek  5.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: q.peek(); break;
        }
    } while (choice != 5);
}
