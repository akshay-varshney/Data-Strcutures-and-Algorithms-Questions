//Binary Tree: Check a Binary Tree is balanced or not.

//A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.


#include <iostream>

using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;
    Node *CreateNode(int data);
    Node *InsertNode(Node* root, int data);
    int balance(Node* root, int &ans);
    bool isBalanced(Node *root);
    
};

Node* Node::CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode) {
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int Node::balance(Node* root, int &ans){
if(root==nullptr) return 1;
      int l=balance(root->left,ans);
      int r=balance(root->right,ans);
      if(abs(r-l)>1) ans=0;
      return max(l,r)+1 ;
  }


bool Node::isBalanced(Node *root)
{
  int ans=1;
  balance(root,ans);
  return ans==1;
}
int main()
{
    Node BT;
    Node* root = BT.CreateNode(3);
    root->left = BT.CreateNode(2);
//    root->right = BT.CreateNode(1);
//    root->left->left = BT.CreateNode(4);
    root->left->right= BT.CreateNode(5);
//    root->right->left=BT.CreateNode(6);
//    root->right->right=BT.CreateNode(7);
    cout<<BT.isBalanced(root)<<endl;
    
    Node* root1 = BT.CreateNode(3);
    root1->left = BT.CreateNode(2);
    root1->right = BT.CreateNode(1);
    root1->left->left = BT.CreateNode(4);
    root1->left->right= BT.CreateNode(5);
    root1->right->left=BT.CreateNode(6);
    root1->right->right=BT.CreateNode(7);
    cout<<BT.isBalanced(root1)<<endl;
}
