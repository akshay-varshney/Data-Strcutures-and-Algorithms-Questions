//Binary Tree: LCA of Binary Tree

//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1#


#include <iostream>


using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;
    Node *CreateNode(int data);
    Node *InsertNode(Node* root, int data);
    Node* lca(Node* root ,int n1 ,int n2 );
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

Node* Node::lca(Node* root ,int n1 ,int n2 )
{

    if(root->data==n1 || root->data==n2){
           return root;
       }
    if(!root->left && !root->right)
    {
        return NULL;
    }
   Node *LEFT=NULL;
   Node * RIGHT=NULL;
   if(root->left){
       LEFT=lca(root->left, n1, n2);
   }
   if(root->right){
       RIGHT= lca(root->right, n1, n2);
   }
   if(LEFT && RIGHT)
   {
       return root;
    }
    return LEFT==NULL? RIGHT:LEFT;
}
int main()
{
    Node BT;
    Node* root = BT.CreateNode(1);
    root->left = BT.CreateNode(2);
    root->right = BT.CreateNode(3);
    root->left->left = BT.CreateNode(4);
    root->left->right= BT.CreateNode(5);
    root->right->left=BT.CreateNode(6);
    root->right->right=BT.CreateNode(7);
    Node *temp=BT.lca(root, 1, 3);
    cout<<"LCA is "<<temp->data<<endl;
}
