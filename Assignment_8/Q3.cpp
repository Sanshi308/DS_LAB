Q3. Write a program for binary search tree (BST) having functions for the following
operations:
(a) Insert an element (no duplicates are allowed),
(b) Delete an existing element,
(c) Maximum depth of BST
(d) Minimum depth of 


#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        cout << "Duplicate value not allowed\n";

    return root;
}


Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}


Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}


int maxDepth(Node* root) {
    if (root == NULL)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}


int minDepth(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL)
        return minDepth(root->right) + 1;

    if (root->right == NULL)
        return minDepth(root->left) + 1;

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}


void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main() {
    Node* root = NULL;
    int choice, val;

    do {
        cout << "\n--- BST MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Maximum Depth\n";
        cout << "4. Minimum Depth\n";
        cout << "5. Display (Inorder)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            root = insert(root, val);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            root = deleteNode(root, val);
            break;

        case 3:
            cout << "Maximum Depth = " << maxDepth(root) << endl;
            break;

        case 4:
            cout << "Minimum Depth = " << minDepth(root) << endl;
            break;

        case 5:
            cout << "BST Inorder: ";
            inorder(root);
            cout << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
