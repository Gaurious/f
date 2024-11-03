#include<bits/stdc++.h>
using namespace std;


class node{
  public:
  int data;
  node* left;
  node* right;
  
  node(int d){
    this -> data = d;
    this -> left = NULL;
    this -> right = NULL;
  }
};
void inorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}


node* buildtree(node* root, int data){
  if(data == -1){
    return root;;
  }

  if(root == NULL) {
    return new node(data);
  }

  if(data < root -> data) {
    root -> left = buildtree(root -> left, data);
  }else {
    root -> right = buildtree(root -> right, data);
  }

  return root;
};



int main() {

  node* root = NULL;

  int num;

  while(true){

    cin >> num;
    if(num == -1){
      break;
    }
    root = buildtree(root, num);
  }

  inorderTraversal(root);


  return 0;
}