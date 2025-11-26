Q4.Write a program to check if a doubly linked list of characters is palindrome or not.
 Example 1: L<->E<->V<->E<->L


  
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;


void insert(char ch) {
    Node* newNode = new Node();
    newNode->data = ch;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL)
        head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
}


bool isPalindrome() {
    Node* left = head;
    Node* right = tail;

    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}


int main() {
    
    insert('L');
    insert('E');
    insert('V');
    insert('E');
    insert('L');

    if (isPalindrome())
        cout << "True";
    else
        cout << "False";

    return 0;
}
