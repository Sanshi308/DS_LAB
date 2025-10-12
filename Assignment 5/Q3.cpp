Write a program to find the middle of a linked list.
Input: 1->2->3->4->5
Output: 3
Ans:-
  
#include <iostream>
using namespace std;

// Define a node
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to find the middle of the linked list
void findMiddle(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* slow = head;  // moves 1 step
    Node* fast = head;  // moves 2 steps

    // Move fast by 2 and slow by 1
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element is: " << slow->data << endl;
}

int main() {
    // Create linked list 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find middle
    findMiddle(head);

    return 0;
}
