//Binary Search Tree: Count BST nodes that lie in a given range
/*
 Input:
       10
      /  \
     5    50
    /    /  \
   1    40  100
 l = 5, h = 45
 Output: 3
 */

#include <iostream>

using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;
    Node(){};
    Node(int value){
        data=value;
        left=right=NULL;
    }
    Node* InsertNode(Node* root, int data);
    void inorder(Node* root);
    void  getCount(Node *root, int l, int h);
};


Node* Node::InsertNode(Node* root, int data)
{
    if(root==NULL){
        return new Node(data);
    }
    if(data>root->data){
        root->right=InsertNode(root->right, data);
    }
    else{
        root->left=InsertNode(root->left, data);
    }
    return root;
}

void Node::inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int value=0;
void Node::getCount(Node *root, int l, int h)
{
  if(root==NULL)
      return ;
    getCount(root->left, l, h);
    if(root->data>=l && root->data <=h ){
        value++;
    }
    getCount(root->right, l, h);
}



int main()
{
    /*
        20
       /   \
     8     22
    /  \
   4   12
      /   \
     10    14
*/
    Node BT;
    Node *root=NULL;
    root = BT.InsertNode(root, 20);
    BT.InsertNode(root, 22);
    BT.InsertNode(root, 8);
    BT.InsertNode(root, 4);
    BT.InsertNode(root, 12);
    BT.InsertNode(root, 14);
    BT.InsertNode(root, 10);
    cout<<"inorder Traversal of Tree 1: ";
    BT.inorder(root);
    cout<<endl;
    BT.getCount(root, 12, 25);
    cout<<"Number of elements between the given range are: "<<value<<endl;
}
