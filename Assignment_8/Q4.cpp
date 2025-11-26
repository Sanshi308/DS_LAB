Q4.Write a program to determine whether a given binary tree is a BST or not.

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


bool isBSTUtil(Node* root, Node* &prev) {
    if (root == NULL)
        return true;

 
    if (!isBSTUtil(root->left, prev))
        return false;

  
    if (prev != NULL && root->data <= prev->data)
        return false;

    prev = root;

    return isBSTUtil(root->right, prev);
}


bool isBST(Node* root) {
    Node* prev = NULL;
    return isBSTUtil(root, prev);
}


int main() {

    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(8);
    root->right->right = createNode(30);

    if (isBST(root))
        cout << "The tree is a BST";
    else
        cout << "The tree is NOT a BST";

    return 0;
}
