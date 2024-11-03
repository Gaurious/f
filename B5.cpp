#include<bits/stdc++.h>
using namespace std;

class node{



  public:
  int data;
  node* left;
  node* right;

  node(int data){
    this -> data = data;
    this -> left = NULL;
    this -> right = NULL;
  }
};

node* buildTree(node* root) {

  cout << "Enter data here: " << endl;
  int data;
  cin >> data;

  root = new node(data);
  if(data ==  -1)
   {
    return NULL;
   }

  cout << "Enter data for inserting in left of " << data << endl;
  root -> left  =  buildTree(root -> left);
  cout << "Enter data for inserting in right of " << data << endl;
  root -> right = buildTree(root -> right);

  return root;
}

void levelorderTraversal(node* root) {
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()) {
    node* temp = q.front();
    q.pop();

    if(temp == NULL) {
      cout << endl;
      if(!q.empty()){
        q.push(NULL);
      }
    }else {
      cout << temp -> data << " ";
      if(temp  -> left) {
        q.push(temp -> left);
      }
      if(temp -> right) {
        q.push(temp -> right);
      }
    }
  }
}

void inorder(node* root) {
  if(root == NULL) {
    return;
  }

  inorder(root->left);
  cout << root -> data << " ";
  inorder(root->right);
}

void preorder(node* root) {
  if(root == NULL) {
    return;
  }
  cout << root -> data << " ";
  preorder(root -> left);
  preorder(root -> right);
  
}

void postorder(node* root) {
  if(root == NULL) {
    return ;
  }

  postorder(root -> left);
  postorder(root -> right);
  cout << root -> data << " ";
}
 
//Input data set : 3  4 5  10 11 12 

int main() {

  node* root = NULL;

  root = buildTree(root);

  levelorderTraversal(root);
  cout << "Inorder traversal: ";
  inorder(root);

  cout << endl;
  cout << "Preorder Traversal: ";
  preorder(root);
  cout << endl;

  cout << "Post order traversal: ";
  postorder(root);
  cout << endl;

  return 0;
}