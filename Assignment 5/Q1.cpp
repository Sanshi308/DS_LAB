Develop a menu driven program for the following operations on a Singly Linked
List.
(a) Insertion at the beginning.
(b) Insertion at the end.
(c) Insertion in between (before or after a node having a specific value, say 'Insert a
new Node 35 before/after the Node 30').
(d) Deletion from the beginning.
(e) Deletion from the end.
(f) Deletion of a specific node, say 'Delete Node 60').
(g) Search for a node and display its position from head.
(h) Display all the node values.

Ans :-

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked List class
class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // (a) Insertion at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at the beginning.\n";
    }

    // (b) Insertion at end
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
        cout << "Inserted " << val << " at the end.\n";
    }

    // (c) Insertion before/after a given value
    void insertBeforeAfter(int key, int val, bool insertAfter = true) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* newNode = new Node();
        newNode->data = val;

        // If inserting before head
        if (head->data == key && !insertAfter) {
            newNode->next = head;
            head = newNode;
            cout << "Inserted " << val << " before " << key << ".\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            if (insertAfter && temp->data == key) {
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted " << val << " after " << key << ".\n";
                return;
            }
            if (!insertAfter && temp->next != NULL && temp->next->data == key) {
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted " << val << " before " << key << ".\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Node with value " << key << " not found.\n";
    }

    // (d) Deletion from beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted node with value " << temp->data << " from beginning.\n";
        delete temp;
    }

    // (e) Deletion from end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == NULL) {
            cout << "Deleted node with value " << head->data << " from end.\n";
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        cout << "Deleted node with value " << temp->next->data << " from end.\n";
        delete temp->next;
        temp->next = NULL;
    }

    // (f) Deletion of a specific node
    void deleteSpecific(int key) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted node with value " << key << ".\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Node with value " << key << " not found.\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        cout << "Deleted node with value " << key << ".\n";
    }

    // (g) Search for a node and display position
    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found in the list.\n";
    }

    // (h) Display all node values
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, value, key;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter node value before which to insert: ";
                cin >> key;
                list.insertBeforeAfter(key, value, false);
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter node value after which to insert: ";
                cin >> key;
                list.insertBeforeAfter(key, value, true);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> key;
                list.deleteSpecific(key);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> key;
                list.search(key);
                break;
            case 9:
                list.display();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

