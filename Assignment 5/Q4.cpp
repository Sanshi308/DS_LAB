Write a program to reverse a linked list.
Input: 1->2->3->4->NULL
Output: 4->3->2->1->NULL

Ans:-
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse the link
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }
    return prev; // new head
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create linked list: 1->2->3->4->NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
