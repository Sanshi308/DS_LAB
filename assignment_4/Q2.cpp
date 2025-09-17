#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front, rear, capacity;

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % capacity == front);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = x;
        cout << x << " enqueued." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << arr[front] << " dequeued." << endl;
        if (front == rear) {
            front = rear = -1; // reset queue
        } else {
            front = (front + 1) % capacity;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;
    cout << "Enter size of Circular Queue: ";
    cin >> size;

    CircularQueue cq(size);

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check Empty\n6. Check Full\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.peek();
                break;
            case 4:
                cq.display();
                break;
            case 5:
                cout << (cq.isEmpty() ? "Queue is Empty" : "Queue is not Empty") << endl;
                break;
            case 6:
                cout << (cq.isFull() ? "Queue is Full" : "Queue is not Full") << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
