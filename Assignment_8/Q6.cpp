Q6.Implement priority queues using heaps.



#include <iostream>
using namespace std;

#define MAX 50
int heap[MAX];
int size = 0;

// Insert into heap
void insert(int val) {
    size++;
    heap[size] = val;
    int i = size;

    // Percolate up
    while (i > 1 && heap[i] > heap[i/2]) {
        swap(heap[i], heap[i/2]);
        i = i / 2;
    }
}

// Delete highest priority (root)
int deleteMax() {
    if (size == 0) {
        cout << "Queue is Empty\n";
        return -1;
    }

    int root = heap[1];
    heap[1] = heap[size];
    size--;

    // Heapify down
    int i = 1;
    while (i <= size/2) {
        int left = 2*i;
        int right = 2*i + 1;
        int largest = i;

        if (left <= size && heap[left] > heap[largest])
            largest = left;

        if (right <= size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            i = largest;
        }
        else break;
    }
    return root;
}

// Display heap
void display() {
    for(int i = 1; i <= size; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main() {
    int ch, val;

    do {
        cout<<"\n--- PRIORITY QUEUE MENU ---\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete Highest Priority\n";
        cout<<"3. Display\n";
        cout<<"0. Exit\n";
        cout<<"Enter choice: ";
        cin >> ch;

        switch(ch) {
        case 1: cout<<"Enter value: "; cin >> val; insert(val); break;
        case 2: cout<<"Deleted: "<< deleteMax() << endl; break;
        case 3: display(); break;
        }
    } while(ch != 0);

    return 0;
}

