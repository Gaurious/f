#include<bits/stdc++.h>
using namespace std;


class node {


  public:
  int data;
  node* right;
  node* left;
  node(int data) {
    this-> data = data;
    this->right = NULL;
    this->left = NULL;
  }
};


node* buildtree(node* root) {
  cout << "Enter the data" << endl;
  int data;
  cin >> data;

  root = new node(root);
  if(data == -1) {
    return NULL;
  }
  cout << "Enter the data for left node"  << data << endl;
  root -> left = buildtree(root -> left);
  cout << "Enter the data for right node " << data << endl;
  root -> right = buildtree(root -> right);
 return root;


}


int main() {

  node* root = NULL;
  root = buildtree(root);


  return 0;
}