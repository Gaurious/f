#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// Build tree using level order input until -1 is encountered
Node* buildTreeLevelOrder(Node*& root) {
    std::queue<Node*> q;
    int data;
    
    // Read the first data (root node)
    std::cin >> data;

    if (data == -1) {
        return nullptr;  // No tree to build
    }

    root = new Node(data);  // Create the root node
    q.push(root);

    // Read subsequent data in sequence until -1 is encountered
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Input the left child data
        std::cin >> data;
        if (data != -1) {
            temp->left = new Node(data);
            q.push(temp->left);
        }

        // Input the right child data
        std::cin >> data;
        if (data != -1) {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }

    return root;
}

// Function for inorder traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Traverse left subtree
    inorderTraversal(root->left);

    // Visit the root node
    std::cout << root->data << " ";

    // Traverse right subtree
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    // Build the tree based on level order input
    root = buildTreeLevelOrder(root);

    // Print inorder traversal
    std::cout << "Inorder Traversal of the Tree: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
