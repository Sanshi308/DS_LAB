Q5. Write a program to check if a linked list is Circular Linked List or not.
 Example: 2->4->6->7->5->2.....


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;


void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void makeCircular() {
    if (head == NULL) return;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head;  
}


bool isCircular() {
    if (head == NULL) return false;

    Node* temp = head->next;

    while (temp != NULL && temp != head)
        temp = temp->next;

    return (temp == head);
}

// Test
int main() {
    insert(2);
    insert(4);
    insert(6);
    insert(7);
    insert(5);

    makeCircular();   // Comment this line to test non-circular

    if (isCircular())
        cout << "True";
    else
        cout << "False";

    return 0;
}
