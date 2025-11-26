Q2.Implement following functions for Binary Search Trees
(a) Search a given item (Recursive & Non-Recursive)
(b) Maximum element of the BST
(c) Minimum element of the BST
(d) In-order successor of a given node the BST
(e) In-order predecessor of a given node the BST


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

// Insert into BST
Node* insert(Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}


Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}


Node* searchIterative(Node* root, int key) {
    while (root != NULL && root->data != key) {
        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}


Node* findMax(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}


Node* findMin(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

Node* inorderSuccessor(Node* root, Node* current) {
    Node* successor = NULL;

    if (current->right != NULL)
        return findMin(current->right);

    while (root != NULL) {
        if (current->data < root->data) {
            successor = root;
            root = root->left;
        }
        else if (current->data > root->data)
            root = root->right;
        else
            break;
    }

    return successor;
}


Node* inorderPredecessor(Node* root, Node* current) {
    Node* predecessor = NULL;

    if (current->left != NULL)
        return findMax(current->left);

    while (root != NULL) {
        if (current->data > root->data) {
            predecessor = root;
            root = root->right;
        }
        else if (current->data < root->data)
            root = root->left;
        else
            break;
    }
    return predecessor;
}


void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int choice, val;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr)
        root = insert(root, x);

    cout << "BST Inorder: ";
    inorder(root);
    cout << endl;

    cout << "\nEnter value to search: ";
    cin >> val;

    Node* found = searchRecursive(root, val);
    if (found != NULL)
        cout << "Found (Recursive)\n";
    else
        cout << "Not found\n";

    found = searchIterative(root, val);
    if (found != NULL)
        cout << "Found (Non-Recursive)\n";
    else
        cout << "Not found\n";

    Node* minNode = findMin(root);
    Node* maxNode = findMax(root);

    cout << "\nMinimum = " << minNode->data << endl;
    cout << "Maximum = " << maxNode->data << endl;

    Node* node = searchRecursive(root, val);

    if (node != NULL) {
        Node* succ = inorderSuccessor(root, node);
        Node* pred = inorderPredecessor(root, node);

        if (succ)
            cout << "Inorder Successor: " << succ->data << endl;
        else
            cout << "No Inorder Successor\n";

        if (pred)
            cout << "Inorder Predecessor: " << pred->data << endl;
        else
            cout << "No Inorder Predecessor\n";
    }

    return 0;
}
