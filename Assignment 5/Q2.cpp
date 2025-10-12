Write a program to count the number of occurrences of a given key in a singly linked
list and then delete all the occurrences.
Input: Linked List : 1->2->1->2->1->3->1 , key: 1
Output: Count: 4 , Updated Linked List: 2->2->3.
Ans:-

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

   
    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty.\n";
            return;
        }
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    
    void countAndDelete(int key) {
        int count = 0;

        
        while (head != NULL && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }

        
        Node* current = head;
        while (current != NULL && current->next != NULL) {
            if (current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                count++;
            } else {
                current = current->next;
            }
        }

        cout << "Count: " << count << endl;
        cout << "Updated Linked List: ";
        display();
    }
};

int main() {
    LinkedList list;

    
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(1);

    cout << "Original Linked List: ";
    list.display();

    int key;
    cout << "Enter key to delete: ";
    cin >> key;

    list.countAndDelete(key);

    return 0;
}
