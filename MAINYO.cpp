#include <iostream>
using namespace std;

// Node structure for the binary search tree
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor to create a new node
    TreeNode(int val) {
        value = val;
        left = right = nullptr;
    }
};

// Binary search tree class
class BinarySearchTree {
public:
    TreeNode* root;
    
    // Constructor to initialize the tree
    BinarySearchTree() {
        root = nullptr;
    }

    // Function to insert a new node
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Helper function to insert nodes recursively
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->value) {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }

    // Function to perform post-order traversal
    void postOrderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        // Visit left subtree
        postOrderTraversal(node->left);
        // Visit right subtree
        postOrderTraversal(node->right);
        // Visit node
        cout << node->value << " ";
    }
};

int main() {
    BinarySearchTree bst;
    int value;
    
    // Reading input values until -1 is encountered
    while (cin >> value && value != -1) {
        bst.insert(value);
    }
    
    // Perform post-order traversal and print the result
    bst.postOrderTraversal(bst.root);
    cout << endl;
    
    return 0;
}
