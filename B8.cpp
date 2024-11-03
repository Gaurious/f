#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert nodes into the binary tree
TreeNode* insert(TreeNode* root, int val) {
    if (val == -1) {
        return root; // Stop insertion when input is -1
    }
    
    if (root == NULL) {
        return new TreeNode(val); // If root is null, create a new node
    }
    
    if (val < root->val) {
        root->left = insert(root->left, val); // Insert in left subtree
    } else {
        root->right = insert(root->right, val); // Insert in right subtree
    }
    return root;
}

// Function to search for a value in the binary tree
bool search(TreeNode* root, int key) {
    if (root == NULL) {
        return false; // Base case: if root is null, key is not found
    }
    
    if (root->val == key) {
        return true; // Key found at root
    }

    // Recursively search in left and right subtrees
    return search(root->left, key) || search(root->right, key);
}

int main() {
    TreeNode* root = NULL;
    int val;

    // Taking multiple inputs until -1 is entered
    cout << "Enter values to insert into the binary tree (-1 to stop):" << endl;
    while (true) {
        cin >> val;
        if (val == -1) {
            break; // Stop taking input when -1 is entered
        }
        root = insert(root, val);
    }

    // Searching for a key in the binary tree
    int key;
    cout << "Enter a value to search for in the binary tree: ";
    cin >> key;
    
    if (search(root, key)) {
        cout << "Key " << key << " found in the binary tree." << endl;
    } else {
        cout << "Key " << key << " not found in the binary tree." << endl;
    }

    return 0;
}
