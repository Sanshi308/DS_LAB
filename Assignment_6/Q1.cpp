Q1. Develop a menu driven program for the following operations of on a Circular as well
as a Doubly Linked List.
(a) Insertion anywhere in the linked list (As a first node, as a last node, and
after/before a specific node).
(b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
deleted may appear as a head node, last node or a node in between.
(c) Search for a node.

// CIRCULAR LINKED LIST
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;


void insertBegin(int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}


void insertEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}


void insertAfter(int key, int val) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        if (temp->data == key) {
            Node* newNode = new Node();
            newNode->data = val;

            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Node not found\n";
}


void deleteNode(int key) {
    if (head == NULL) return;

    Node* temp = head, *prev = NULL;

    if (temp->data == key) {
        Node* last = head;
        while (last->next != head)
            last = last->next;

        last->next = head->next;
        head = head->next;
        delete temp;
        return;
    }

    do {
        prev = temp;
        temp = temp->next;
        if (temp->data == key) {
            prev->next = temp->next;
            delete temp;
            return;
        }
    } while (temp != head);

    cout << "Node not found\n";
}


void search(int key) {
    if (head == NULL) return;

    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    cout << "Not found\n";
}


void display() {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(HEAD)\n";
}


int main() {
    int ch, val, key;

    do {
        cout << "\n--- Circular Linked List ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After\n";
        cout << "4. Delete Node\n";
        cout << "5. Search\n";
        cout << "6. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
        case 1: cout << "Enter value: "; cin >> val; insertBegin(val); break;
        case 2: cout << "Enter value: "; cin >> val; insertEnd(val); break;
        case 3: cout << "Insert after which value: "; cin >> key;
                cout << "Enter new value: "; cin >> val;
                insertAfter(key, val); break;
        case 4: cout << "Delete value: "; cin >> key; deleteNode(key); break;
        case 5: cout << "Search value: "; cin >> key; search(key); break;
        case 6: display(); break;
        }
    } while (ch != 0);

    return 0;
}






// DOUBLY LINKED LIST
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
void insertBegin(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}


void insertEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}


void insertAfter(int key, int val) {
    Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Node not found\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}


void deleteNode(int key) {
    Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Node not found\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}


void search(int key) {
    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Not found\n";
}

void display() {
    if (head == NULL) return;

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int main() {
    int ch, val, key;

    do {
        cout << "\n--- Doubly Linked List ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After\n";
        cout << "4. Delete Node\n";
        cout << "5. Search\n";
        cout << "6. Display\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
        case 1: cout << "Enter value: "; cin >> val; insertBegin(val); break;
        case 2: cout << "Enter value: "; cin >> val; insertEnd(val); break;
        case 3: cout << "Insert after which value: "; cin >> key;
                cout << "Enter new value: "; cin >> val;
                insertAfter(key, val); break;
        case 4: cout << "Delete value: "; cin >> key; deleteNode(key); break;
        case 5: cout << "Search value: "; cin >> key; search(key); break;
        case 6: display(); break;
        }
    } while (ch != 0);

    return 0;
}
