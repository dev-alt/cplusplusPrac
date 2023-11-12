#include <iostream>

// Definition of a Node structure for a binary tree
struct Node {
    int data;       // Data stored in the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize a node with a given value
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to perform an inorder traversal of the binary tree
void inorderTraversal(Node* root) {
    // Base case: Check if the current node is not null
    if (root != nullptr) {
        // Recursively traverse the left subtree
        inorderTraversal(root->left);

        // Process the current node (in this case, print its data)
        std::cout << root->data << " ";

        // Recursively traverse the right subtree
        inorderTraversal(root->right);
    }
}

int main() {
    // Create a simple binary tree
    Node* root = new Node(1);           // Root node with value 1
    root->left = new Node(2);           // Left child with value 2
    root->right = new Node(3);          // Right child with value 3
    root->left->left = new Node(4);     // Left child of the left child with value 4
    root->left->right = new Node(5);    // Right child of the left child with value 5

    // Print the inorder traversal of the binary tree
    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);

    // Deallocate memory to prevent memory leaks
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
